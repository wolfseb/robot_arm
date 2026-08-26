#include <vector>
#include <string>

#include <SDL3/SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>

#pragma once

#define PRESSED_BUTTON_COLOR IM_COL32(255, 100, 100, 255)
#define RELEASED_BUTTON_COLOR IM_COL32(100, 100, 100, 255)
#define PRESSED_BUTTON_LABEL_COLOR IM_COL32(0, 0, 0, 255)
#define RELEASED_BUTTON_LABEL_COLOR IM_COL32(200, 200, 200, 255)

void render_button_list(const ImVec2& root, const std::vector<bool>& buttons, ImDrawList* draw);
void render_dpad(const ImVec2& root, const std::vector<bool> buttons, ImDrawList* draw);
void render_face(const ImVec2& root, const std::vector<bool> buttons, ImDrawList* draw);
void render_shoulder(const ImVec2& root, const bool button, const char* label, ImDrawList* draw);
void render_misc(const ImVec2& root, const bool button, const float& radius, ImDrawList* draw);