#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>

#include <SDL3/SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>

#include "gamepad.hpp"

#pragma once

struct DisplayConfig {
    const char* name;
    ImVec2 root_pos;
    ImVec2 size;
};

void render_joystick_window(const DisplayConfig& config, const Sint16 x, const Sint16 y);
void render_trigger_window(const DisplayConfig& config, const Sint16 x);
void render_buttons_window(const DisplayConfig& config, const std::vector<bool>& buttons);

class GamepadGUI {
public:
    GamepadGUI(bool show_gui, int width = 1240, int height = 740);
    ~GamepadGUI();
    void render_GUI(GamepadState& gp);
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    ImGuiContext* context;
    bool show_gui;
};
