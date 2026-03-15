#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace gdev {
	class World;
	class Application
	{
	public:
		Application();
		Application(const std::string& title, int height, int weight);
		void Run();
		
		template<typename WorldType>
		weak<WorldType> LoadWorld();

	private:
		void TickInternal(float deltaTime);
		void RenderInternal();

		virtual void Render();
		virtual void Tick(float deltaTime);
		sf::RenderWindow mWindow;
		float mTargetFrame;
		sf::Clock mTickClock;

		shared<World> mCurrentWord;
	};

	template<typename WorldType>
	weak<WorldType> Application::LoadWorld()
	{
		shared<WorldType> newWorld{ new WorldType{this} };
		mCurrentWord = newWorld;
		mCurrentWord->BeginPlayInternal();
		return newWorld;
	}
}