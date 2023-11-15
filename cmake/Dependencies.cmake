include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

######################
## SFML
######################
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_PROGRESS TRUE
    GIT_SHALLOW TRUE
    EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(SFML)


######################
## ImGui
######################
FetchContent_Declare(imgui
	GIT_REPOSITORY https://github.com/ocornut/imgui.git
	GIT_TAG v1.89.9
	GIT_PROGRESS TRUE
	EXCLUDE_FROM_ALL
	GIT_SHALLOW TRUE
	EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(imgui)


######################
## ImGui-SFML
######################
FetchContent_Declare(imgui_sfml
	GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
	GIT_TAG v2.6
	GIT_PROGRESS TRUE
	GIT_SHALLOW TRUE
	EXCLUDE_FROM_ALL)