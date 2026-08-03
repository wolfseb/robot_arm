cmake_minimum_required(VERSION 3.15)

project(servo_tests)

set(CMAKE_CXX_STANDARD 17)

add_executable(
    servo_tests
    test_servo.cpp
    ../Microcontroller/Core/Src/servo.cpp
)

target_include_directories(
    servo_tests
    PRIVATE
    ../Microcontroller/Core/Inc
)