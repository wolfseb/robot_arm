#include "gamepad_gui.hpp"

GamepadGUI::GamepadGUI(bool show_gui, int width, int height) : show_gui{ show_gui }
{
    if (!show_gui) return;

    this->window = SDL_CreateWindow("Controller Callibration", width, height, 0);
    if (!window) throw std::runtime_error(SDL_GetError());

    this->renderer = SDL_CreateRenderer(this->window, nullptr);
    if (!renderer) throw std::runtime_error(SDL_GetError());

    IMGUI_CHECKVERSION();
    this->context = ImGui::CreateContext();
    ImGui_ImplSDL3_InitForSDLRenderer(this->window, this->renderer);
    ImGui_ImplSDLRenderer3_Init(this->renderer);
}

GamepadGUI::~GamepadGUI()
{
    if (!show_gui) return;

    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext(this->context);

    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void GamepadGUI::render_GUI(GamepadState& gp)
{
    if (!show_gui) return;
    
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    ImVec2 jsize(150, 150);
    DisplayConfig stick_l = {
        .name = "left stick",
        .root_pos = (ImVec2){ 25, 25 },
        .size = jsize,
    };
    render_joystick_window(stick_l, gp.left_x, gp.left_y);
    
    DisplayConfig stick_r = {
        .name = "right stick",
        .root_pos = (ImVec2){ 200, 25 },
        .size = jsize,
    };
    render_joystick_window(stick_r, gp.right_x, gp.right_y);
    
    ImVec2 tsize(50, 150);
    DisplayConfig trigger_l = {
        .name = "LT",
        .root_pos = (ImVec2){ 375, 25 },
        .size = tsize,
    };
    render_trigger_window(trigger_l, gp.lt);
    
    DisplayConfig trigger_r = {
        .name = "RT",
        .root_pos = (ImVec2){ 450, 25 },
        .size = tsize,
    };
    render_trigger_window(trigger_r, gp.rt);

    DisplayConfig buttons_config = {
        .name = "buttons",
        .root_pos = (ImVec2){ 25, 200 },
        .size = (ImVec2){ 1000, 400 }
    };
    render_buttons_window(buttons_config, gp.buttons);

    ImGui::Render();
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
    SDL_RenderPresent(renderer);
};

