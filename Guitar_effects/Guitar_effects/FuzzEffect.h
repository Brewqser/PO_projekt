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
		int edit(sf::Event event);
		double getW();

	protected:
		bool _on;
		double _mix;
	};
}
