#define SDL_MAIN_HANDLED

#include <vector>

#include <SDL3/SDL.h>

#pragma once

struct GamepadState
{
    Sint16 left_x = 0;
    Sint16 left_y = 0;
    Sint16 right_x = 0;
    Sint16 right_y = 0;
    Sint16 lt = 0;
    Sint16 rt = 0;

    std::vector<bool> buttons = std::vector<bool>(SDL_GAMEPAD_BUTTON_COUNT, false);
};