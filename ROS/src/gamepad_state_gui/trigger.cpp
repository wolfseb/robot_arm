#include "gamepad_gui.hpp"

void render_trigger_window(const DisplayConfig& config, const Sint16 x)
{
    ImGui::SetNextWindowPos(config.root_pos);
    ImGui::SetNextWindowSize(config.size);
    ImGui::Begin(config.name);

    ImVec2 size = ImGui::GetContentRegionAvail();
    ImVec2 root = ImGui::GetCursorScreenPos();
    ImDrawList* draw = ImGui::GetWindowDrawList();

    // Callibration Area
    draw->AddRect(
        root,
        { root.x + size.x, root.y + size.y },
        IM_COL32(150, 150, 150, 255)
    );

    // position
    float position = root.y + size.y - x * ((float)size.y)/SDL_JOYSTICK_AXIS_MAX;
    draw->AddLine(
        { root.x,          position },
        { root.x + size.x, position },
        IM_COL32(255, 100, 100, 255),
        4
    );

    ImGui::Dummy(size);
    ImGui::End();
};
