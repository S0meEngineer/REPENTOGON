#include "imgui.h"

struct ConsoleCommand {
    const char* name; // The name of the command.
    const char* desc; // A short (usually one sentence) description of the command. Will show up when just typing `help`
    const char* helpText; // The help text for the command. Will show up when doing `help (command)`
    bool showOnMenu;

    ConsoleCommand(const char* cmdName, const char* cmdDesc, const char* cmdHelpText, bool cmdShowOnMenu) {
        name = cmdName;
        desc = cmdDesc;
        helpText = cmdHelpText;
        showOnMenu = cmdShowOnMenu;
    }
};

struct ConsoleMega {
    bool enabled;
    char inputBuf[1024];
    std::vector<ConsoleCommand> commands;

    static void  Strtrim(char* s) { char* str_end = s + strlen(s); while (str_end > s && str_end[-1] == ' ') str_end--; *str_end = 0; }

    ConsoleMega()
    {
        enabled = true;
        memset(inputBuf, 0, sizeof(inputBuf));
        commands = {
            ConsoleCommand("help", "Displays help (how else would you get here?)", "Hi, i'm the help text!", true) 
        };
    }

    void ExecuteCommand(char* input) {
        std::string printin = std::string("> ") + input + "\n";
        std::string out;

        g_Game->GetConsole()->Print(printin, 0xFF808080, 0x96u);
        g_Game->GetConsole()->RunCommand(input, out, NULL);
        g_Game->GetConsole()->Print(out.c_str(), 0XFFD3D3D3, 0x96u);
        memset(inputBuf, 0, sizeof(inputBuf));
    }

    void Draw() {
        ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(300, 100));
        if (ImGui::Begin("Console", &enabled)) {
            std::deque<Console_HistoryEntry>* history = g_Game->GetConsole()->GetHistory();

            if (ImGui::BeginChild("Text View", ImVec2(0, 0), true)) {
                /* For "simplicity" and so we don't have duplicated memory while still allowing both old and new console to be usable,
                * we reuse existing console history.
                * The vanilla console stores history backwards, so we iterate over it in reverse.
                */
                for (auto entry = history->rbegin(); entry != history->rend(); ++entry) {
                    int colorMap = entry->GetColorMap();

                    /* 
                    * The vanilla console stores colors like this, because we can't have nice things.
                    * g_colorDouble is used for other things but it isn't really evident what those things are yet, so this will have to do.
                    * Decomp shows it as 0 but it... clearly isn't, so whatever.
                    */

                    float red = ((colorMap >> 0x10 & 0xFF) + g_colorDouble) / 255;
                    float green = ((colorMap >> 8 & 0xFF) + g_colorDouble) / 255;
                    float blue = ((colorMap & 0xFF) + g_colorDouble) / 255;

                    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(red, green, blue, 1));
                    ImGui::TextWrapped(entry->_text.Get());
                    ImGui::PopStyleColor();
                }
                ImGui::EndChild();
            }
            ImGui::Separator();

            bool reclaimFocus = false;
            ImGuiInputTextFlags consoleFlags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_EscapeClearsAll | ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory;
            if (ImGui::InputTextWithHint("", "Type your command here (\"help\" for help)", inputBuf, 1024, consoleFlags)) {
                char* s = inputBuf;
                Strtrim(s);
                if (s[0])
                    ExecuteCommand(s);
                reclaimFocus = true;
            }

            ImGui::SetItemDefaultFocus();
            if (reclaimFocus)
                ImGui::SetKeyboardFocusHere(-1);

            ImGui::End();
        }
        ImGui::PopStyleVar();
    }
};

extern ConsoleMega console;