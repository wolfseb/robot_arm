#include <buttons.hpp>

void render_misc(const ImVec2& root, const bool button, const float& radius, ImDrawList* draw)
{
    if (button)
    {
        draw->AddCircleFilled(
            root,
            radius,
            PRESSED_BUTTON_COLOR
        );
    }
    else
    {
        draw->AddCircle(
            root,
            radius,
            RELEASED_BUTTON_COLOR
        );
    }
}