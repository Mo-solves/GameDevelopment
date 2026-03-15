#include <iostream>
#include "framework/Core.h"
#include "framework/Application.h"
#include "framework/World.h"

namespace gdev {
	Application::Application()
		: mWindow{ sf::VideoMode(1000,800), "Space Ship" },
		mTargetFrame{60.f},
		mTickClock{},
		mCurrentWord{nullptr}
		
	{
	}
	Application::Application(const std::string& title, int height, int weight)
		: mWindow{ sf::VideoMode(height,weight), title },
		mTargetFrame{ 60.f },
		mTickClock{},
		mCurrentWord{nullptr}
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
			float frameDeltaTime = mTickClock.restart().asSeconds();
			accumulatedTime += mTickClock.restart().asSeconds();
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
			
		}
	}
	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);

		if (mCurrentWord)
		{
			mCurrentWord->TickInternal(deltaTime);
		}
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

	void Application::Tick(float deltaTime)
	{
	}
}