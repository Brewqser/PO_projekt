#pragma once
#include "SFML/Audio.hpp"

namespace GE
{
	class effect 
	{
	public:

		virtual void process( sf::SoundBuffer &buffer ) = 0;

	};
}