#include <SFML/Graphics.hpp>

namespace gdev {
	class Application
	{
	public:
		Application();
		Application(const std::string& title, int height, int weight);
		
		void Run();
		void Tick(float deltaTime);

	private:
		sf::RenderWindow mWindow;
		float mTargetFrame;
		sf::Clock mTickClock;
	};
}