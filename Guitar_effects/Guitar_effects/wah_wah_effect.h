#pragma once

#include <SFML/Audio.hpp>
#include "effect.h"

namespace GE
{
	class wah_wah_effect : public effect
	{
	public:
		wah_wah_effect();

		void process( sf::SoundBuffer &buffer );
		bool getOn();
		void flipOn();

	protected:
		bool _on;
	};
}
