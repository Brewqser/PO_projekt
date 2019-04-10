#pragma once

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
		int edit(sf::Event event) { return 0; }
		double getW() { return 0; }

	protected:
		bool _on;
	};
}
