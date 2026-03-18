#include "framework/Actor.h"
#include "framework/Core.h"

namespace gdev
{
	Actor::Actor(World* owningWorld)
		: mOwningWorld{ owningWorld },
		mHasBeganPlay{ false }
	{
	}

	Actor::~Actor()
	{
		LOG("Actor Destroyed");
	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBeganPlay)
		{
			mHasBeganPlay = true;
			BeginPlay();
		}
	}

	void Actor::BeginPlay()
	{
		LOG("Actor begin play");
	}

	void Actor::Tick(float deltaTime)
	{
		LOG("Actor Ticking");
	}
}