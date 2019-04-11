#include "DelayEffect.h"

#include <iostream>

#include "definitions.h"

namespace GE
{
	DelayEffect::DelayEffect()
	{
		_on = 0;
		_M = 100;
	}

	void DelayEffect::process(sf::SoundBuffer &buffer)
	{
		std::vector <sf::Int16> Y;
		double BL = 0.5 ;
		double FB = -0.5;
		double FF = 1.0;
		double M = _M / 1000;
		

		int delaysize = (int) (buffer.getSampleRate() * M);

		std::vector < double > delay;
		for (int i = 0; i < delaysize; i++) delay.push_back(0);

		const sf::Int16* _samples = buffer.getSamples();

		for (unsigned int i = 0; i < buffer.getSampleCount(); i++)
		{
			double xh = (_samples[i] / power2) + FB * delay[0];
			Y.push_back (( sf::Int16) ( (FF * delay[0] + BL * xh) * power2));
			delay.erase(delay.begin());
			delay.push_back(xh);
		}
		
		buffer.loadFromSamples(&Y[0], buffer.getSampleCount(), 1, buffer.getSampleRate());

	}

	bool DelayEffect::getOn()
	{
		return _on;
	}

	void DelayEffect::flipOn()
	{
		_on = !_on;
	}

	int DelayEffect::edit(sf::Event event)
	{
		if (event.type == sf::Event::TextEntered)
		{
			if ((char)event.text.unicode == 8)
			{
				_M /= 10;
				_M = (int)_M;
			}
			else if ((char)event.text.unicode == 13)
			{
				_M = std::max(_M, (double)0);
				_M = std::min(_M, (double)1000);
				return 1;
			}
			else if ((char)event.text.unicode >= '0' && (char)event.text.unicode <= '9')
			{
				if (_M <= 1000) _M = _M * 10 + (int)(char)event.text.unicode - 48;
			}
		}
		return 0;
	}

	double DelayEffect::getW()
	{
		return _M;
	}
}