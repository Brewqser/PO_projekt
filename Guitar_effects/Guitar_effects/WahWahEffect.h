#pragma once

#include <SFML/Audio.hpp>

#include "Effect.h"

namespace GE
{
	class WahWahEffect : public Effect
	{
	public:
		WahWahEffect();

		void process( sf::SoundBuffer &buffer );
		bool getOn();
		void flipOn();

	protected:
		bool _on;
	};
}
