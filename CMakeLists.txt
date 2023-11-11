cmake_minimum_required(VERSION 3.15)
project(SfmlTemplate LANGUAGES CXX)

set(CMAKE_EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

include(FetchContent)

######################
## SFML
######################
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


######################
## ImGui
######################
FetchContent_Declare(imgui
	GIT_REPOSITORY https://github.com/ocornut/imgui.git
	GIT_TAG v1.89.9)
FetchContent_MakeAvailable(imgui)


######################
## ImGui-SFML
######################
FetchContent_Declare(imgui_sfml
	GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
	GIT_TAG v2.6)

set(IMGUI_DIR "${imgui_SOURCE_DIR}")
set(IMGUI_SFML_FIND_SFML OFF)
set(SFML_DIR "${SFML_BINARY_DIR}")

FetchContent_MakeAvailable(imgui_sfml)

add_executable(Application WIN32 
	"src/main.cpp"
	"${IMGUI_DIR}/imgui.cpp"
	"${IMGUI_DIR}/imgui_widgets.cpp"
	"${IMGUI_DIR}/imgui_draw.cpp"
	"${IMGUI_DIR}/imgui_tables.cpp"
	"${IMGUI_DIR}/imgui_demo.cpp"
	"${imgui_sfml_SOURCE_DIR}/imgui-SFML.cpp")

target_link_libraries(Application PRIVATE sfml-system sfml-graphics)
target_link_libraries(Application PUBLIC ImGui-SFML::ImGui-SFML)
