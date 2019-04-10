#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

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
		int edit(sf::Event event);
		double getW();

	protected:
		bool _on;
		double _Fw;
	};
}
