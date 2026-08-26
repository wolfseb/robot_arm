#include "buttons.hpp"

void render_button_list(const ImVec2& root, const std::vector<bool>& buttons, ImDrawList* draw)
{
    float padding = 8;
    float margin = 20;
    float radius = 12;
    for (int i = 0; i < SDL_GAMEPAD_BUTTON_COUNT; ++i)
    {
        ImVec2 pos = { root.x + margin + radius + i*padding + i*2*radius, root.y + margin + radius };
        ImVec2 text_pos = { pos.x - 5, pos.y - 5 };
        if (buttons[i])
        {
            draw->AddCircleFilled(
                pos,
                radius,
                PRESSED_BUTTON_COLOR
            );
            draw->AddText(text_pos, PRESSED_BUTTON_LABEL_COLOR, std::to_string(i).c_str());
        }
        else {
            draw->AddCircle(
                pos,
                radius,
                RELEASED_BUTTON_COLOR,
                0,
                2
            );
            draw->AddText(text_pos, RELEASED_BUTTON_LABEL_COLOR, std::to_string(i).c_str());
        }
    }
};
