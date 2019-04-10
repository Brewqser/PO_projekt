#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace GE
{
	class Effect
	{
	public:

		virtual void process( sf::SoundBuffer &buffer ) = 0;
		virtual void flipOn() = 0;
		virtual bool getOn() = 0;
		virtual int edit(sf::Event event) = 0;
		virtual double getW() = 0;

	};
}