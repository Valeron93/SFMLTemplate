#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>


int main(int argc, char** argv) {

    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML ImGui example");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Clock delta;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, delta.restart());
        ImGui::ShowDemoWindow();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return EXIT_SUCCESS;
}


#ifdef WIN32

#include <windows.h>

int WINAPI WinMain(
    _In_ HINSTANCE hInst,
    _In_opt_ HINSTANCE hInstPrev,
    _In_ PSTR cmdline,
    _In_ int cmdshow)
{
	
	return main(__argc, __argv);
}

#endif
