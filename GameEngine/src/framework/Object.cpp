#include "framework/Object.h"
#include "framework/Core.h"

namespace gdev
{
	Object::Object()
		: mIsPendingDestroy{false}
	{
	}

	Object::~Object()
	{
		LOG("Object destroyed");
	}

	void Object::Destroy()
	{
		mIsPendingDestroy = true;
	}
}