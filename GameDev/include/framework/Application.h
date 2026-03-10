#include <SFML/Graphics.hpp>

namespace gdev {
	class Application
	{
	public:
		Application();
		Application(const std::string& title, int height, int weight);
		
		void Run();

	private:
		sf::RenderWindow mWindow;
	};
}