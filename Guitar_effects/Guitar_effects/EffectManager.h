#pragma once 

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

#include "Effect.h"
#include "WahWahEffect.h"
#include "FuzzEffect.h"
#include "DelayEffect.h"
#include "RingEffect.h"
#include "definitions.h"

namespace GE
{
	class EffectManager
	{
	public:
		EffectManager();

		bool clicked(sf::RenderWindow &window);
		bool pressed(sf::RenderWindow &window, sf::Keyboard::Key key);
		int pressedE(sf::RenderWindow &window, sf::Keyboard::Key key);
		int check(sf::RenderWindow &window);
		int edit(int ef , sf::Event event);
		std::string getW(int ef);

		void process(sf::SoundBuffer &sound);

		void draw(sf::RenderWindow &window);

	private:
		sf::Font _font;
		std::vector < std::unique_ptr<Effect> > _Effects;
		std::vector < std::pair <sf::Text, int> > _txt;
	};
}