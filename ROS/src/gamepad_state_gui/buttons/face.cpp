#include <buttons.hpp>

void render_face(const ImVec2& root, const std::vector<bool> buttons, ImDrawList* draw)
{
    float button_radius = 12;
    std::vector<ImVec2> buttons_pos = {
        (ImVec2){ root.x + 3*button_radius, root.y + 5*button_radius },
        (ImVec2){ root.x + 5*button_radius, root.y + 3*button_radius },
        (ImVec2){ root.x +   button_radius, root.y + 3*button_radius },
        (ImVec2){ root.x + 3*button_radius, root.y +   button_radius },
    };
    const std::vector<const char*> button_labels = { "A", "B", "X", "Y" };
    for (int i = 0; i < buttons_pos.size(); ++i)
    {
        ImColor button_color;
        ImColor text_color;
        if (buttons[i])
        {
            draw->AddCircleFilled(
                buttons_pos[i],
                button_radius,
                PRESSED_BUTTON_COLOR
            );
            text_color = PRESSED_BUTTON_LABEL_COLOR;
        }
        else
        {
            draw->AddCircle(
                buttons_pos[i],
                button_radius,
                RELEASED_BUTTON_COLOR
            );
            text_color = RELEASED_BUTTON_LABEL_COLOR;
        }
        
        draw->AddText(
            { buttons_pos[i].x - 4, buttons_pos[i].y - 6 },
            text_color,
            button_labels[i]
        );
    }
}