#pragma once

#include "SFML/Graphics.hpp"
#include "definitions.h"
#include "string"

namespace GE
{
	struct Data
	{
		sf::RenderWindow window;
	};

	typedef std::shared_ptr<Data> DataRef;

	class main_loop
	{

	public:
		main_loop(int width, int height, std::string title);

	private:
		void run();
		void init();

		DataRef _data = std::make_shared<Data>();
		main_loop_state _state;
		std::string _filename;

		std::vector <sf::Text> _texts;
		std::vector <sf::RectangleShape> _buttons;
		sf::Font _font;
	};
}