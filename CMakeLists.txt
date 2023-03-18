cmake_minimum_required(VERSION 3.1)
project(analogue_clock)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(include)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(analogue_clock
		src/analogue_clock.cpp
		src/main.cpp
		src/shape.cpp
		src/glad.cpp
		src/sdl_window.cpp
		src/system_time.cpp)

target_link_libraries(analogue_clock ${SDL2_LIBRARIES} ${CMAKE_DL_LIBS})
