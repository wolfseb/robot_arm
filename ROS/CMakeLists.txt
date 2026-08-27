cmake_minimum_required(VERSION 3.20)
project(controller_callibration LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(IMGUI_DIR C:/dev/imgui)

find_package(SDL3 CONFIG REQUIRED)

add_executable(controller_callibration
    src/main.cpp
    src/gamepad_state_gui/gamepad_gui.cpp
    src/gamepad_state_gui/joystick.cpp
    src/gamepad_state_gui/trigger.cpp
    src/gamepad_state_gui/buttons/buttons.cpp
    src/gamepad_state_gui/buttons/dpad.cpp
    src/gamepad_state_gui/buttons/face.cpp
    src/gamepad_state_gui/buttons/shoulder.cpp
    src/gamepad_state_gui/buttons/misc.cpp
    src/gamepad_state_gui/buttons/list.cpp

    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer3.cpp
)

target_include_directories(controller_callibration PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gamepad_state_gui
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

target_link_libraries(controller_callibration PRIVATE SDL3::SDL3)