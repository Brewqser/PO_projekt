#pragma once

#include "effect.h"

namespace GE
{
	class overdrive_effect : public effect
	{
	public:
		overdrive_effect();

		void process(sf::SoundBuffer &buffer);

	protected:

	};
}
