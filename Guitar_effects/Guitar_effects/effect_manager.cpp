#include "effect_manager.h"
#include <iostream>

namespace GE
{
	effect_manager::effect_manager()
	{
		_font.loadFromFile(Font_Filepath);

		std::unique_ptr<effect> eff;
		eff = std::make_unique <wah_wah_effect>();
		_effects.push_back(std::move(eff) );
		eff = std::make_unique <delay_effect>();
		_effects.push_back(std::move(eff));
		eff = std::make_unique <fuzz_effect>();
		_effects.push_back(std::move(eff));
		eff = std::make_unique <ring_effect>();
		_effects.push_back(std::move(eff));

		sf::Text txt;
		txt.setFillColor( gray ) ;
		txt.setFont(_font);

		txt.setString("Wah-Wah");
		_txt.push_back(std::make_pair(txt,0));
		
		txt.setString("Delay");
		_txt.push_back(std::make_pair(txt, 1));

		txt.setString("FuZz");
		_txt.push_back(std::make_pair(txt, 2));

		txt.setString("Ring Modulation");
		_txt.push_back(std::make_pair(txt, 3));

		for (unsigned int i = 0; i < _txt.size(); i++)
		{
			_txt[i].first.setOrigin(_txt[i].first.getGlobalBounds().width / 2, _txt[i].first.getGlobalBounds().height / 2);
			_txt[i].first.setPosition(SCREEN_WIDHT / 2, (SCREEN_HEIGHT * (i + 1) / (_txt.size() + 4)));
		}

		/*
		for (unsigned int i = 0; i < _txt.size(); i++)
		{
			_txt[i].first.setPosition((SCREEN_WIDHT / 2) - (_txt[i].first.getGlobalBounds().width / 2), (SCREEN_HEIGHT * (i + 1) / (_txt.size() + 4)) - _txt[i].first.getGlobalBounds().height / 2);
		}
		*/
	}

	bool effect_manager::clicked(sf::RenderWindow &window)
	{
		int choise = this->check(window);
		if ( choise != -1)
		{
			_effects[_txt[choise].second]->flipOn();
			return 1;
		}
		
		return 0;
	}

	bool effect_manager::pressed(sf::RenderWindow &window, sf::Keyboard::Key key)
	{
		int pre = this->check(window);
		if (pre != -1)
		{
			sf::Vector2f tmp = _txt[pre].first.getPosition();
			if (key == sf::Keyboard::Key::Num1 )
			{
				_txt[pre].first.setPosition(_txt[0].first.getPosition());
				_txt[0].first.setPosition(tmp);

				std::swap(_txt[pre], _txt[0]);
				return 1;
			}
			if (key == sf::Keyboard::Key::Num2)
			{
				_txt[pre].first.setPosition(_txt[1].first.getPosition());
				_txt[1].first.setPosition(tmp);

				std::swap(_txt[pre], _txt[1]);
				return 1;
			}
			if (key == sf::Keyboard::Key::Num3)
			{
				_txt[pre].first.setPosition(_txt[2].first.getPosition());
				_txt[2].first.setPosition(tmp);

				std::swap(_txt[pre], _txt[2]);
				return 1;
			}
			if (key == sf::Keyboard::Key::Num4)
			{
				_txt[pre].first.setPosition(_txt[3].first.getPosition());
				_txt[3].first.setPosition(tmp);

				std::swap(_txt[pre], _txt[3]);
				return 1;
			}
		}
		return 0;
	}

	int effect_manager::check(sf::RenderWindow &window)
	{
		for (unsigned int i = 0; i < _txt.size(); i++)
		{
			if (_txt[i].first.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				return i;
			}
		}

		return -1;
	}

	void effect_manager::process(sf::SoundBuffer &sound)
	{
		for (unsigned int i = 0; i < _txt.size(); i++)
		{
			if (_effects[_txt[i].second]->getOn() == 1)
			{
				_effects[_txt[i].second]->process(sound);
			}
		}
	}

	void effect_manager::draw(sf::RenderWindow &window)
	{
		for (unsigned int i = 0; i < _txt.size(); i++)
		{
			if (_effects[_txt[i].second]->getOn() == 0) _txt[i].first.setFillColor(gray);
			else _txt[i].first.setFillColor(sf::Color::Green);

			window.draw(_txt[i].first);
		}
	}
}