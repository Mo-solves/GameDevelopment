#include "framework/Application.h"

namespace gdev {
	Application::Application() : mWindow{ sf::VideoMode(1024,1440), "Space Ship" }
	{
	}
	Application::Application(const std::string& title, int height, int weight)
		: mWindow{ sf::VideoMode(height,weight), title }
	{
	}

	void Application::Run()
	{
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::Closed()) {
					mWindow.close();
				}
			}
		}
	}
}