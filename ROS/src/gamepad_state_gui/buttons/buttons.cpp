#include "gamepad_gui.hpp"
#include "buttons.hpp"

void render_buttons_window(const DisplayConfig& config, const std::vector<bool>& buttons)
{
    ImGui::SetNextWindowPos(config.root_pos);
    ImGui::SetNextWindowSize(config.size);
    ImGui::Begin(config.name);

    ImVec2 size = ImGui::GetContentRegionAvail();
    ImVec2 root = ImGui::GetCursorScreenPos();
    ImDrawList* draw = ImGui::GetWindowDrawList();

    ImVec2 dpad_topleft = { root.x + 270, root.y + 250 };
    ImVec2 face_topleft = { root.x + 450, root.y + 150 };
    ImVec2 lb_topleft   = { root.x + 220, root.y + 100 };
    ImVec2 rb_topleft   = { face_topleft.x + (float)13.5, root.y + 100 };
    ImVec2 lstick_mid   = { lb_topleft.x + (float)22.5, face_topleft.y + 36 };
    ImVec2 rstick_mid   = { root.x + 440, dpad_topleft.y + (float)22.5 };
    ImVec2 lmisc_mid    = { lstick_mid.x + 100, lstick_mid.y };
    ImVec2 mmisc_mid    = { lmisc_mid.x + 25, lstick_mid.y - 50 };
    ImVec2 rmisc_mid    = { lmisc_mid.x + 50, lstick_mid.y };

    render_button_list(root, buttons, draw);
    
    render_dpad(dpad_topleft, std::vector<bool>(buttons.begin()+11, buttons.begin()+15), draw);
    render_face(face_topleft, std::vector<bool>(buttons.begin(), buttons.begin()+4), draw);

    // middle buttons
    render_misc(lmisc_mid, buttons[4], 8, draw);
    render_misc(mmisc_mid, buttons[5], 15, draw);
    render_misc(rmisc_mid, buttons[6], 8, draw);

    // sticks
    render_misc(lstick_mid, buttons[7], 20, draw);
    render_misc(rstick_mid, buttons[8], 20, draw);
    
    // sholder buttons
    render_shoulder(lb_topleft, buttons[9], "LB", draw);
    render_shoulder(rb_topleft, buttons[10], "RB", draw);

    ImGui::Dummy(size);
    ImGui::End();
};
