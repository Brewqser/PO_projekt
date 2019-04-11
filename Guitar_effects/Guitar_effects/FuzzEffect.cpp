#include "FuzzEffect.h"

#include <iostream>
#include <math.h>

#include "definitions.h"

namespace GE
{
	FuzzEffect::FuzzEffect()
	{
		_on = 0;
		_mix = 100;
	}

	void FuzzEffect::process(sf::SoundBuffer &buffer)
	{
		std::vector <sf::Int16> Y;
		std::vector <double> Z;
		std::vector <double> W;
		std::vector <double> I;

		const sf::Int16* _samples = buffer.getSamples();
	
		double gain = 5;
		double mix = _mix / 1000;

		double maxI = 0;
		double maxZ = 0;
		double maxW = 0;

		for (int i = 0; i < buffer.getSampleCount(); i++)
		{
			I.push_back((double)_samples[i] / power2);
			maxI = std::max(maxI, std::abs(I[i]));
		}

		for (int i = 0; i < buffer.getSampleCount(); i++)
		{
			Z.push_back(I[i] * gain / maxI);
			Z[i] = sgn(-1 * Z[i]) * (1 - std::exp(sgn(-1 * Z[i]) * Z[i]));
			maxZ = std::max(maxZ, std::abs(Z[i]));
		}
		for (int i = 0; i < buffer.getSampleCount(); i++)
		{
			W.push_back((mix * Z[i] * maxI / maxZ) + ((double)1 - mix) * I[i]);
			maxW = std::max(maxW, std::abs(W[i]));
		}
		for (int i = 0; i < buffer.getSampleCount(); i++)
		{
			Y.push_back((sf::Int16) ((W[i] * maxI / maxW) * power2));
		}

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

	int FuzzEffect::edit(sf::Event event)
	{
		if (event.type == sf::Event::TextEntered)
		{
			if ((char)event.text.unicode == 8)
			{
				_mix /= 10;
				_mix = (int)_mix;
			}
			else if ((char)event.text.unicode == 13)
			{
				_mix = std::max(_mix, (double)0);
				_mix = std::min(_mix, (double)1000);
				return 1;
			}
			else if ((char)event.text.unicode >= '0' && (char)event.text.unicode <= '9')
			{
				if (_mix <= 1000) _mix = _mix * 10 + (int)(char)event.text.unicode - 48;
			}
		}
		return 0;
	}

	double FuzzEffect::getW()
	{
		return _mix;
	}
}