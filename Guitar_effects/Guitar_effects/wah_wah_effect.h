#pragma once

#include "effect.h"

namespace GE
{
	class wah_wah_effect : public effect
	{
	public:
		wah_wah_effect();

		void process( sf::SoundBuffer &buffer );

	protected:

	};
}
