#pragma once

namespace gdev
{
	class Application;
	class World
	{
	public:
		World(Application* owningApp);
		void BeginPlayInternal();
		void TickInternal(float deltaTime);

		virtual ~World();
	private:
		void BeginPlay();
		void Tick(float deltaTime);
		Application* mOwningApp;
		bool mBeganPlay;
	};
}