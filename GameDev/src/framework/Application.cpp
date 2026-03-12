#include <iostream>
#include "framework/Application.h"

namespace gdev {
	Application::Application()
		: mWindow{ sf::VideoMode(1000,800), "Space Ship" },
		mTargetFrame{60.f},
		mTickClock{}
		
	{
	}
	Application::Application(const std::string& title, int height, int weight)
		: mWindow{ sf::VideoMode(height,weight), title },
		mTargetFrame{ 60.f },
		mTickClock{}
	{
	}

	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / mTargetFrame;
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::Closed()) {
					mWindow.close();
				}
			}
			accumulatedTime += mTickClock.restart().asSeconds();
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				Tick(targetDeltaTime);
				RenderInternal();
			}
		}
	}
	void Application::Tick(float deltaTime)
	{
		
	}

	void Application::RenderInternal()
	{
		mWindow.clear();
		
		Render();

		mWindow.display();
	}

	void Application::Render()
	{
		sf::RectangleShape rect{ sf::Vector2f{100, 100} };
		rect.setFillColor(sf::Color::Cyan);
		rect.setOrigin(50, 50);
		rect.setPosition(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f);

		mWindow.draw(rect);
	}
}