#pragma once

#include "effect.h"

namespace GE
{
	class delay_effect : public effect
	{
	public:
		delay_effect();

		void process(sf::SoundBuffer &buffer);

	protected:

	};
}
