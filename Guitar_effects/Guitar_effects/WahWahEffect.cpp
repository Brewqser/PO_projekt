#include "WahWahEffect.h"

//#include <iostream>

#include "definitions.h"

namespace GE
{
	WahWahEffect::WahWahEffect()
	{
		_on = 0;
		_Fw = 2000.f;
	}

	void WahWahEffect::process(sf::SoundBuffer &buffer)
	{
		double damp = 0.05;
		double minf = 500.f;
		double maxf = 3000.f;


		std::vector <double> F1;
		std::vector <double> yh;
		std::vector <double> yb;
		std::vector <double> yl;
		std::vector <sf::Int16> Y;

		double delta = _Fw / buffer.getSampleRate();

		double tmp = (maxf - minf) / delta;

		for (int i = 0; i < buffer.getSampleCount(); i++)
		{
			if ((i / ((int)tmp)) % 2 == 0)
			{
				F1.push_back(minf + (i % (int)tmp) * delta);
			}
			else
			{
				F1.push_back(maxf - (i % (int)tmp) * delta);
			}

			F1[i] = 2 * sin((pi * F1[i]) / buffer.getSampleRate());
		}


		const sf::Int16* _samples = buffer.getSamples();
	
		double Q1 = 2.f * damp;

		yh.push_back(_samples[0]);
		yb.push_back(F1[0] * yh[0]);
		yl.push_back(F1[0] * yb[0]);

		double maxb = yb[0];

		for (int i = 1; i < buffer.getSampleCount(); i++)
		{
			yh.push_back(_samples[i] - yl[i - 1] - Q1 * yb[i - 1]);
			yb.push_back(F1[i - 1] * yh[i] + yb[i - 1]);
			yl.push_back(F1[i - 1] * yb[i] + yl[i - 1]);
			maxb = std::max(maxb, yb[i]);
		}

		for (int i = 0; i < buffer.getSampleCount(); i++)
		{
			Y.push_back((sf::Int16) ((yb[i] / maxb)* power2));
		}

		buffer.loadFromSamples( &Y[0], buffer.getSampleCount(), 1, buffer.getSampleRate());
	}

	bool WahWahEffect::getOn()
	{
		return _on;
	}

	void WahWahEffect::flipOn()
	{
		_on = !_on;
	}

	int WahWahEffect::edit(sf::Event event)
	{
		if (event.type == sf::Event::TextEntered)
		{
			if ((char)event.text.unicode == 8)
			{
				_Fw /= 10;
				_Fw = (int)_Fw;
			}
			else if ((char)event.text.unicode == 13)
			{
				_Fw = std::max(_Fw, (double)1);
				_Fw = std::min(_Fw, (double)1000000);
				return 1;
			}
			else if ((char)event.text.unicode >= '0' && (char)event.text.unicode <= '9')
			{
				if ( _Fw <=1000000) _Fw = _Fw * 10 + (int)(char)event.text.unicode - 48;
			}
		}
		return 0;
	}

	double WahWahEffect::getW()
	{
		return _Fw;
	}
}