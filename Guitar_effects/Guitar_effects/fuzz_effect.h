#pragma once

#include "effect.h"

namespace GE
{
	class fuzz_effect : public effect
	{
	public:
		fuzz_effect();

		void process(sf::SoundBuffer &buffer);

	protected:

	};
}
