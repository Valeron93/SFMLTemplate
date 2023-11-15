cmake_minimum_required(VERSION 3.15)
project(SfmlTemplate LANGUAGES CXX)

include("cmake/Dependencies.cmake")

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

set_target_properties(Application PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    INSTALL_RPATH "@executable_path")


target_link_libraries(Application PRIVATE sfml-system sfml-graphics)
target_link_libraries(Application PUBLIC ImGui-SFML::ImGui-SFML)

install(TARGETS Application
		ARCHIVE DESTINATION lib
		LIBRARY DESTINATION lib
		RUNTIME DESTINATION bin)

