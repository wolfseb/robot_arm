#include <iostream>

#include "gamepad.hpp"
#include "gamepad_gui.hpp"

int main(int argc, char* argv[])
{
    bool show_gui = true;

    for (int i = 0; i < argc; i++)
    {
        if (std::string_view(argv[i]) == "--no-gui") show_gui = false;
    }
    
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
    {
        const char* err = SDL_GetError();
        std::cerr << err << '\n';
        return 1;
    }
    
    int count;
    SDL_JoystickID* gamepadID = SDL_GetGamepads(&count);
    if (count == 0) {
        std::cerr << "Error: No Gamepad found" << std::endl;
        return 1;
    }
    SDL_OpenGamepad(*gamepadID);
    SDL_Gamepad* gamepad = SDL_GetGamepadFromID(*gamepadID);

    bool running = true;
    SDL_Event event;
    GamepadState gp;

    GamepadGUI gui(show_gui);

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_EVENT_JOYSTICK_AXIS_MOTION)
            {
                gp.left_x = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTX);
                gp.left_y = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTY);

                gp.right_x = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_RIGHTX);
                gp.right_y = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_RIGHTY);

                gp.lt = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFT_TRIGGER);
                gp.rt = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER);
            }
            else if (event.type == SDL_EVENT_GAMEPAD_BUTTON_DOWN || event.type == SDL_EVENT_GAMEPAD_BUTTON_UP)
            {
                for (int i=0; i<SDL_GAMEPAD_BUTTON_COUNT; ++i)
                {
                    gp.buttons[i] = SDL_GetGamepadButton(gamepad, static_cast<SDL_GamepadButton>(i));
                }
            }
        }

        if (show_gui) gui.render_GUI(gp);
    }

    SDL_CloseGamepad(gamepad);
}