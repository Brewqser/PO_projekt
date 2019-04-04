#pragma once

#include "SFML/Graphics.hpp"
#include "definitions.h"
#include "string"
#include "file_manager.h"
#include "effect_manager.h"

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

		bool _loaded;
		bool _saveReady;
		bool _saved;
		bool _isplaying;

		DataRef _data = std::make_shared<Data>();
		main_loop_state _state;
		std::string _filename;

		std::vector <sf::Text> _texts;
		std::vector <sf::Sprite> _buttons;

		sf::Texture _texture[10];
		sf::Font _font;
		sf::Sound sound;
		sf::Clock _clock;

		file_manager _fManager;
		effect_manager _eManager;

	};
}