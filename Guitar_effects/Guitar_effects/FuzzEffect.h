#pragma once

#include "Effect.h"

namespace GE
{
	class FuzzEffect : public Effect
	{
	public:
		FuzzEffect();

		void process(sf::SoundBuffer &buffer);
		bool getOn();
		void flipOn();

	protected:
		bool _on;

	};
}
