#include <buttons.hpp>

void render_shoulder(const ImVec2& root, const bool button, const char* label, ImDrawList* draw)
{
    std::vector<ImVec2> buttons_pos = {
        (ImVec2){ root.x,           root.y },
    };
    const std::vector<const char*> button_labels = { "LB", "RB" };
    ImVec2 button_size = { 45, 20 };
    ImVec2 button_end = { root.x + button_size.x, root.y + button_size.y };
    ImColor text_color;
    if (button)
    {
        draw->AddRectFilled(
            root,
            button_end,
            PRESSED_BUTTON_COLOR,
            1
        );
        text_color = PRESSED_BUTTON_LABEL_COLOR;
    }
    else
    {
        draw->AddRect(
            root,
            button_end,
            RELEASED_BUTTON_COLOR,
            1
        );
        text_color = RELEASED_BUTTON_LABEL_COLOR;
    }

    draw->AddText(
        { root.x + 16, root.y + 3 },
        text_color,
        label
    );
}