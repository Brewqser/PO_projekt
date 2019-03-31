#pragma once

#include "effect.h"

namespace GE
{
	class ring_effect : public effect
	{
	public:
		ring_effect();

		void process(sf::SoundBuffer &buffer);

	protected:

	};
}
