#include "gamepad_gui.hpp"

// +- area around 0 to count as no action,
// because mechanically the joystick will never rest on perfect 0
#define DEAD_ZONE 5000

void render_joystick_window(const DisplayConfig& config, const Sint16 x, const Sint16 y)
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

    // Axes
    draw->AddLine(
        { root.x + size.x/2, root.y },
        { root.x + size.x/2, root.y + size.y },
        IM_COL32(100, 100, 100, 200)
    );
    draw->AddLine(
        { root.x,           root.y + size.y/2 },
        { root.x + size.x,  root.y + size.y/2 },
        IM_COL32(100, 100, 100, 200)
    );

    // consider DEAD_ZONE
    Sint16 xeff = x;
    Sint16 yeff = y;
    if (std::abs(x) <= DEAD_ZONE) xeff = 0;
    else
    {
        if (x < 0) xeff += DEAD_ZONE;
        else xeff -= DEAD_ZONE;
    } 
    if (std::abs(y) <= DEAD_ZONE) yeff = 0;
    else
    {
        if (y < 0) yeff += DEAD_ZONE;
        else yeff -= DEAD_ZONE;
    }
    float effective_range = SDL_JOYSTICK_AXIS_MAX - SDL_JOYSTICK_AXIS_MIN - 2*DEAD_ZONE;
    // position
    ImVec2 position = {
        root.x + size.x/2 + xeff * ((float)size.x)/effective_range,
        root.y + size.y/2 + yeff * ((float)size.y)/effective_range
    };

    float crosshair_size = 4;
    float scaling = 1.2;
    draw->AddCircle(
        position,
        crosshair_size,
        IM_COL32(255, 100, 100, 255)
    );
    float line_size = scaling*crosshair_size;
    draw->AddLine(
        { position.x - line_size, position.y },
        { position.x + line_size, position.y },
        IM_COL32(255, 100, 100, 255)
    );
    draw->AddLine(
        { position.x, position.y - line_size },
        { position.x, position.y + line_size },
        IM_COL32(255, 100, 100, 255)
    );

    ImGui::Dummy(size);
    ImGui::End();
};
