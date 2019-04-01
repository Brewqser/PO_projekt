#include "main_loop.h"
#include <iostream>

namespace GE
{
	main_loop::main_loop(int width, int height, std::string title)
	{
		_state = main_loop_state::work;
		_filename = "";

		sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
		_data->window.create(sf::VideoMode(width, height, desktop.bitsPerPixel), title, sf::Style::Close | sf::Style::Titlebar);
		
		this->run();
	}

	void main_loop::run()
	{
		_font.loadFromFile("Comic Sans.ttf");

		sf::Text filename;
		filename.setFont(_font);
		filename.setString(_filename);

		// init 
		this->init();


		while (_data->window.isOpen())
		{
			sf::Event event;
			while (_data->window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					_data->window.close();
				}


				// handle input
				if (_state == main_loop_state::read)
				{
					if (event.type == sf::Event::TextEntered)
					{
						if ((char)event.text.unicode == 8)
						{
							if (_filename.size() > 0)
							{
								_filename.erase(_filename.begin() + _filename.size() - 1);
							}
						}
						else
						{
							_filename = _filename + (char)event.text.unicode;
						}

						std::cout << event.text.unicode << " " << _filename << std::endl;
					}
				}

			}


			// update
			if (_state == main_loop_state::read)
			{
				filename.setString(_filename);
				filename.setPosition((SCREEN_WIDHT / 2) - (filename.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - 17 /* filename.getGlobalBounds().height / 2*/);
				//std::cout << filename.getGlobalBounds().height / 2 << std::endl;
			}


			//draw
			_data->window.clear(sf::Color::Black);


			if (_state == main_loop_state::read)
			{
				_data->window.draw(filename);
			}

			if (_state == main_loop_state::work )
			{
				for (unsigned int i = 0; i < _buttons.size(); i++)
				{
					_data->window.draw(_buttons[i]);
				}
				//_data->window.draw(_texts[0]);
				for (unsigned int i = 0; i < _texts.size(); i++)
				{
					_data->window.draw(_texts[i]);
				}

			}


			_data->window.display();
		}
	}

	void main_loop::init()
	{
		sf::Texture texture;
		sf::Sprite sprite;

		_buttons.push_back(sprite);
		_buttons.push_back(sprite);
		_buttons.push_back(sprite);
		_buttons.push_back(sprite);
		_buttons.push_back(sprite);
		_buttons.push_back(sprite);

		_texture[0].loadFromFile(Play_Button_Filepath);

		_buttons[0].setTexture(_texture[0]);
		_buttons[1].setTexture(_texture[0]);

		_buttons[0].setPosition(SCREEN_WIDHT - 2 * (_buttons[0].getGlobalBounds().width + 30), SCREEN_HEIGHT - 2 * (_buttons[0].getGlobalBounds().height + 20));
		_buttons[1].setPosition(SCREEN_WIDHT - 2 * (_buttons[1].getGlobalBounds().width + 30), SCREEN_HEIGHT - _buttons[1].getGlobalBounds().height - 20);
		
		_texture[1].loadFromFile(Pause_Button_Filepath);

		_buttons[2].setTexture(_texture[1]);
		_buttons[3].setTexture(_texture[1]);

		_buttons[2].setPosition(SCREEN_WIDHT - 2 * (_buttons[2].getGlobalBounds().width + 30), SCREEN_HEIGHT - 2 * (_buttons[2].getGlobalBounds().height + 20));
		_buttons[3].setPosition(SCREEN_WIDHT - 2 * (_buttons[3].getGlobalBounds().width + 30), SCREEN_HEIGHT - _buttons[3].getGlobalBounds().height - 20);

		_texture[2].loadFromFile(Load_Button_Filepath);

		_buttons[4].setTexture(_texture[2]);

		_buttons[4].setPosition(SCREEN_WIDHT - _buttons[4].getGlobalBounds().width - 30, SCREEN_HEIGHT - 2 * (_buttons[4].getGlobalBounds().height + 20));
		
		_texture[3].loadFromFile(Save_Button_Filepath);

		_buttons[5].setTexture(_texture[3]);

		_buttons[5].setPosition(SCREEN_WIDHT - _buttons[5].getGlobalBounds().width - 30, SCREEN_HEIGHT - (_buttons[5].getGlobalBounds().height + 20));

		_buttons[0].setColor(sf::Color::Transparent);
		_buttons[1].setColor(sf::Color::Transparent);
		_buttons[2].setColor(sf::Color::Transparent);
		_buttons[3].setColor(sf::Color::Transparent);
		_buttons[5].setColor(sf::Color::Transparent);

		sf::Text txt;
		txt.setFont(_font);
		txt.setString("Source File");
		_texts.push_back(txt);
		_texts[0].setPosition(SCREEN_WIDHT - 3 * (_buttons[0].getGlobalBounds().width + 40), SCREEN_HEIGHT - 3 * (_texts[0].getGlobalBounds().height + 19));
		txt.setString("Output File");
		_texts.push_back(txt);
		_texts[1].setPosition(SCREEN_WIDHT - 3 * (_buttons[0].getGlobalBounds().width + 40), SCREEN_HEIGHT - 1 * (_texts[1].getGlobalBounds().height + 32));
	}
}