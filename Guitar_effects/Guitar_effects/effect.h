#pragma once
#include "SFML/Audio.hpp"

namespace GE
{
	class Effect
	{
	public:

		virtual void process( sf::SoundBuffer &buffer ) = 0;
		virtual void flipOn() = 0;
		virtual bool getOn() = 0;

	};
}