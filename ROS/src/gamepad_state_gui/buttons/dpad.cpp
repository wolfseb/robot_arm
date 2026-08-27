#include <buttons.hpp>

void render_dpad(const ImVec2& root, const std::vector<bool> buttons, ImDrawList* draw)
{
    float dpad_line_length = 15;
    std::vector<ImVec2> dpad_points = {
        (ImVec2){ root.x,                      root.y +   dpad_line_length },
        (ImVec2){ root.x +   dpad_line_length, root.y +   dpad_line_length },
        (ImVec2){ root.x +   dpad_line_length, root.y                      },
        (ImVec2){ root.x + 2*dpad_line_length, root.y                      },
        (ImVec2){ root.x + 2*dpad_line_length, root.y +   dpad_line_length },
        (ImVec2){ root.x + 3*dpad_line_length, root.y +   dpad_line_length },
        (ImVec2){ root.x + 3*dpad_line_length, root.y + 2*dpad_line_length },
        (ImVec2){ root.x + 2*dpad_line_length, root.y + 2*dpad_line_length },
        (ImVec2){ root.x + 2*dpad_line_length, root.y + 3*dpad_line_length },
        (ImVec2){ root.x +   dpad_line_length, root.y + 3*dpad_line_length },
        (ImVec2){ root.x +   dpad_line_length, root.y + 2*dpad_line_length },
        (ImVec2){ root.x                     , root.y + 2*dpad_line_length },
        (ImVec2){ root.x                     , root.y +   dpad_line_length },
    };
    for (int i = 0; i < dpad_points.size()-1; ++i)
    {
        draw->AddLine(
            dpad_points[i],
            dpad_points[i+1],
            IM_COL32(100, 100, 100, 255),
            2
        );
    }

    /* dpad pressed
            0
        2       3
            1
    */
    std::vector<ImVec2> dpad_buttons_pos = {
        (ImVec2){ root.x +   dpad_line_length, root.y                      },
        (ImVec2){ root.x +   dpad_line_length, root.y + 2*dpad_line_length },
        (ImVec2){ root.x,                      root.y +   dpad_line_length },
        (ImVec2){ root.x + 2*dpad_line_length, root.y +   dpad_line_length },
    };
    for (int i = 0; i < 4; ++i)
    {
        if (buttons[i])
        {
            draw->AddRectFilled(
                dpad_buttons_pos[i],
                { dpad_buttons_pos[i].x + dpad_line_length, dpad_buttons_pos[i].y + dpad_line_length },
                PRESSED_BUTTON_COLOR,
                0.5
            );
        }
    }
}