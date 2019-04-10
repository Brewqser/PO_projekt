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

	protected:
		bool _on;
	};
}
