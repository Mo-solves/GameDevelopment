#pragma once

namespace gdev
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		void Destroy();
		bool IsPendingDestroty() const { return mIsPendingDestroy; }

	private:
		bool mIsPendingDestroy;
	};
}