#include "RingEffect.h"

#include <iostream>

#include "definitions.h"

namespace GE
{
	RingEffect::RingEffect()
	{
		_on = 0;
		_Fc = 500;
	}

	void RingEffect::process(sf::SoundBuffer &buffer)
	{
		std::vector <sf::Int16> Y;
		double Fc = _Fc;

		const sf::Int16* _samples = buffer.getSamples();

		for (unsigned int i = 0; i < buffer.getSampleCount(); i++)
		{
			double xh = (_samples[i] / power2) ;
			Y.push_back((sf::Int16)  ( xh * sin(2 * pi* (i+1)  *(Fc / (double) buffer.getSampleRate())) * power2 ));
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

	int RingEffect::edit(sf::Event event)
	{
		if (event.type == sf::Event::TextEntered)
		{
			if ((char)event.text.unicode == 8)
			{
				_Fc /= 10;
				_Fc = (int)_Fc;
			}
			else if ((char)event.text.unicode == 13)
			{
				_Fc = std::max(_Fc, (double)0);
				_Fc = std::min(_Fc, (double)1000);
				return 1;
			}
			else if ((char)event.text.unicode >= '0' && (char)event.text.unicode <= '9')
			{
				if (_Fc <= 1000) _Fc = _Fc * 10 + (int)(char)event.text.unicode - 48;
			}
		}
		return 0;
	}

	double RingEffect::getW()
	{
		return _Fc;
	}
}