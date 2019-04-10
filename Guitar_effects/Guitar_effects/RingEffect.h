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
		int edit(sf::Event event) { return 0; }
		double getW() { return 0; }
	protected:
		bool _on;

	};
}
