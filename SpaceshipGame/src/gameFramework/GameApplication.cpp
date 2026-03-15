#include "gameFramework/GameApplication.h"
#include "framework/World.h"

gdev::Application* GetApplication()
{
	return new gdev::GameApplication();
}

namespace gdev {
	GameApplication::GameApplication()
	{
		LoadWorld<World>();
	}
}