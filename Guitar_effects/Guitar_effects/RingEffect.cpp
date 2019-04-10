#include "RingEffect.h"

#include "definitions.h"
#include <iostream>

namespace GE
{
	RingEffect::RingEffect()
	{
		_on = 0;
	}

	void RingEffect::process(sf::SoundBuffer &buffer)
	{
		std::vector <sf::Int16> Y;
		double Fc = 440;
		double Fx = 200;

		const sf::Int16* _samples = buffer.getSamples();

		for (unsigned int i = 0; i < buffer.getSampleCount(); i++)
		{
			double xh = (_samples[i] / power2) ;
			Y.push_back((sf::Int16)  ( xh * sin(2 * pi*i*(Fx / buffer.getSampleRate ())) * sin(2 * pi* i *(Fc / buffer.getSampleRate())) * power2 ));
		}

		buffer.loadFromSamples(&Y[0], buffer.getSampleCount(), 1, buffer.getSampleRate());

	}

	bool RingEffect::getOn()
	{
		return _on;
	}

	void RingEffect::flipOn()
	{
		_on = !_on;
	}
}