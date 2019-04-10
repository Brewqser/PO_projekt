#pragma once

#include "Effect.h"

namespace GE
{
	class RingEffect : public Effect
	{
	public:
		RingEffect();

		void process(sf::SoundBuffer &buffer);
		bool getOn();
		void flipOn();

	protected:
		bool _on;

	};
}
