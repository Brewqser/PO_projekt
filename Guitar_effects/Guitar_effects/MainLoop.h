#pragma once

#include "SFML/Graphics.hpp"
#include "definitions.h"
#include "string"
#include "FileManager.h"
#include "EffectManager.h"

namespace GE
{
	struct Data
	{
		sf::RenderWindow window;
	};

	typedef std::shared_ptr<Data> DataRef;

	class MainLoop
	{

	public:
		MainLoop(int width, int height, std::string title);

	private:
		void run();
		void init();

		bool _loaded;
		bool _saveReady;
		bool _saved;
		bool _isplaying;
		int _edi;

		DataRef _data = std::make_shared<Data>();
		MainLoop_state _state;
		std::string _filename;

		std::vector <sf::Text> _texts;
		std::vector <sf::Sprite> _buttons;

		sf::Texture _texture[10];
		sf::Font _font;
		sf::Sound sound;
		sf::Clock _clock;

		FileManager _fManager;
		EffectManager _eManager;

	};
}