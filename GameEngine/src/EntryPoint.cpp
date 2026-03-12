#include <memory>
#include "framework/Application.h"
#include "EntryPoint.h"

int main()
{
	gdev::Application* app = GetApplication();
	app->Run();
	delete app;
}