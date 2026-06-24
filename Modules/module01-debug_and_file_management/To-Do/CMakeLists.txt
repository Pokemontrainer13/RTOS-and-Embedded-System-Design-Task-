cmake_minimum_required(VERSION 3.10)
project(FakeMCU_Driver_Test)

set(CMAKE_C_STANDARD 99)

set(CMAKE_BUILD_TYPE Debug)

include_directories(inc)

add_executable(driver_app 
    src/main.c 
    src/sensor.c 
    src/battery.c 
    src/fake_mcu.c
)