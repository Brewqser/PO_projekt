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
		int edit(sf::Event event);
		double getW();

	protected:
		bool _on;
		double _Fc;

	};
}
