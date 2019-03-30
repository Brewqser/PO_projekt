#include "overdrive_effect.h"

#include "definitions.h"
#include <iostream>

namespace GE
{
	overdrive_effect::overdrive_effect()
	{

	}

	void overdrive_effect::process(sf::SoundBuffer &buffer)
	{
		double th = 1.f / 3.f;
		std::vector <sf::Int16> Y;

		const sf::Int16* _samples = buffer.getSamples();

		double sample;
		double tmpsample;

		for (int i = 0; i < buffer.getSampleCount(); i++)
		{
			sample = (double)_samples[i] / power2;
			//std::cout << sample << std::endl;

			if (std::abs(sample) < th)
			{
				tmpsample = 2 * sample;
			}
			if (std::abs(sample) >= th)
			{
				if (sample > 0)
				{
					tmpsample = (3.f - (2.f - sample * 3.f) * (2.f - sample * 3.f) ) / 3.f;
				}
				else
				{
					tmpsample = -1.f * (3.f - (2.f - sample * 3.f) * (2.f - sample * 3.f)) / 3.f;
				}
			}
			if (std::abs(sample) >= 2 * th)
			{
				if (sample > 0)
				{
					tmpsample = 1.f;
				}
				else
				{
					tmpsample = -1.f;
				}
			}

			Y.push_back((sf::Int16)( tmpsample * power2));
		}
		
		buffer.loadFromSamples(&Y[0], buffer.getSampleCount(), 1, buffer.getSampleRate());
		
	}
}