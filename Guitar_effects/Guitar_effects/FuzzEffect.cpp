#include "FuzzEffect.h"

#include <iostream>
#include <math.h>

#include "definitions.h"

namespace GE
{
	FuzzEffect::FuzzEffect()
	{
		_on = 0;
	}

	void FuzzEffect::process(sf::SoundBuffer &buffer)
	{
		std::vector <sf::Int16> Y;
		std::vector <double> Z;
		std::vector <double> W;

		const sf::Int16* _samples = buffer.getSamples();
	
		double gain = 5;
		double mix = 0.1;

		sf::Int16 maxs = std::abs(_samples[0]);

		for (int i = 1; i < buffer.getSampleCount(); i++)
		{
			maxs = std::max(maxs, _samples[i]);
		}

		double sample;
		double maxz = -1000000;

		for (int i = 0; i < buffer.getSampleCount(); i++)
		{
			sample = ( (double)_samples[i] / maxs )* gain ;
			Z.push_back((sample / std::abs(sample)) * (1.f - std::exp((sample / std::abs(sample)) * sample)));

			maxz = std::max(maxz, Z[i]);
		}
		double maxy = -1000000;

		for (int i = 0; i < buffer.getSampleCount(); i++)
		{
			sample = ((double)_samples[i]  / maxs)* gain;
			W.push_back((mix * Z[i] * maxs / maxz) + (1 - mix) * sample);

			maxy = std::max(maxy, W[i]);
		}

		for (int i = 0; i < buffer.getSampleCount(); i++)
		{
			
			Y.push_back( (sf::Int16) (W[i]  / maxy *power2 ) );
		}
		
		
		//mix*z*max(abs(x)) / max(abs(z)) + (1 - mix)*x;
		/*

		for (int i = 0; i < buffer.getSampleCount(); i++)
		{
			sample = (double)_samples[i] / power2;
			double q = sample / std::abs(sample);

			double tmp = q * (1.f - exp(gain * (q * sample)));
			Y.push_back( (sf::Int16) (mix * tmp + (1.f - mix) * sample * power2 ));
		}
		*/

		buffer.loadFromSamples(&Y[0], buffer.getSampleCount(), 1, buffer.getSampleRate());

	}

	bool FuzzEffect::getOn()
	{
		return _on;
	}

	void FuzzEffect::flipOn()
	{
		_on = !_on;
	}
}