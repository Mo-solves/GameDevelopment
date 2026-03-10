#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "framework/Application.h"

using namespace gdev;

int main() {
	// old way of making pointer
	//Application* app = new Application{"My Game", 800, 800};
	
	// new way of making pointer
	std::unique_ptr<Application> app = std::make_unique<Application>("My Game", 1000, 800);
	app->Run();

}