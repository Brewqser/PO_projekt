#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Effect.h"

namespace GE
{
	class DelayEffect : public Effect
	{
	public:
		DelayEffect();

		void process(sf::SoundBuffer &buffer);
		bool getOn();
		void flipOn();
		int edit(sf::Event event);
		double getW();

	protected:
		bool _on;
		double _M;
	};
}
