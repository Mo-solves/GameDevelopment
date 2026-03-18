#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

gdev::Application* GetApplication()
{
	return new gdev::GameApplication();
}

namespace gdev {
	GameApplication::GameApplication()
	{
		 weak<World> newWorld = LoadWorld<World>();
		 newWorld.lock()->SpawnActor<Actor>();
		 actorToDestroy =  newWorld.lock()->SpawnActor<Actor>();
		 counter = 0;
	}

	void GameApplication::Tick(float deltaTime)
	{
		counter += deltaTime;
		if (counter > 2.f)
		{
			if (!actorToDestroy.expired())
			{
				actorToDestroy.lock()->Destroy();
			}
		}
	}
}