# Class "Backdrop"

???+ info
    You can get this class by using the following functions:

    * [Room:GetBackdrop()](Room.md#getbackdrop)

    ???+ example "Example Code"
        ```lua
        local camera = Game():GetCurrentRoom():GetBackdrop()
        ```
        
## Functions

### Get·Floor·Image () {: aria-label='Functions' }
#### [Image](Image.md) GetFloorImage ( ) {: .copyable aria-label='Functions' }
Returns the buffer containing the floor texture of the current room.

___
### Get·Wall·Image () {: aria-label='Functions' }
#### [Image](Image.md) GetWallImage ( ) {: .copyable aria-label='Functions' }
Returns the buffer containing the wall texture of the current room.

___