#include "delay_effect.h"

#include "definitions.h"
#include <iostream>

namespace GE
{
	delay_effect::delay_effect()
	{

	}

	void delay_effect::process(sf::SoundBuffer &buffer)
	{
		std::vector <sf::Int16> Y;
		double BL = 0.5 ;
		double FB = -0.5;
		double FF = 1.0;
		double M = 0.1;

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
}