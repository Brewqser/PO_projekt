#pragma once 

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

#include "effect.h"
#include "wah_wah_effect.h"
#include "fuzz_effect.h"
#include "delay_effect.h"
#include "ring_effect.h"
#include "definitions.h"

namespace GE
{
	class effect_manager
	{
	public:
		effect_manager();

		bool clicked(sf::RenderWindow &window);
		bool pressed(sf::RenderWindow &window, sf::Keyboard::Key key);
		int check(sf::RenderWindow &window);

		void process(sf::SoundBuffer &sound);

		void draw(sf::RenderWindow &window);

	private:
		sf::Font _font;
		std::vector < std::unique_ptr<effect> > _effects;
		std::vector < std::pair <sf::Text, int> > _txt;
	};
}