#include "MainLoop.h"
#include <iostream>

namespace GE
{
	MainLoop::MainLoop(int width, int height, std::string title)
	{
		_state = MainLoop_state::work;
		_filename = "";
		_isplaying = 0;
		_loaded = 0;
		_saveReady = 0;
		_saved = 0;

		sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
		_data->window.create(sf::VideoMode(width, height, desktop.bitsPerPixel), title, sf::Style::Close | sf::Style::Titlebar);
		
		this->run();
	}

	void MainLoop::run()
	{
		_font.loadFromFile(Font_Filepath);

		sf::Text filename;
		filename.setFont(_font);
		filename.setString(_filename);

		// init 
		this->init();

		// end init 


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

				if (event.type == sf::Event::MouseButtonPressed) _saved = 0;

				if (_state == MainLoop_state::work)
				{
					// button check
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if ((_buttons[buttons::load].getColor() != sf::Color::Transparent ) && _buttons[buttons::load].getGlobalBounds().contains(_data->window.mapPixelToCoords(sf::Mouse::getPosition(_data->window))))
						{
							_saveReady = 0;
							_state = MainLoop_state::read;
						}

						if ((_buttons[buttons::save].getColor() != sf::Color::Transparent) && _buttons[buttons::save].getGlobalBounds().contains(_data->window.mapPixelToCoords(sf::Mouse::getPosition(_data->window))))
						{
							std::cout << "Pressed Save button" << std::endl;
							_fManager.savepro();
							_saved = 1;
						}

						if ((_buttons[buttons::playorg].getColor() != sf::Color::Transparent) && _buttons[buttons::playorg].getGlobalBounds().contains(_data->window.mapPixelToCoords(sf::Mouse::getPosition(_data->window))))
						{
							//std::cout << "Pressed playorg button" << std::endl;
							_state = MainLoop_state::playing;
							sound.setBuffer( _fManager.getbufforg() ) ;
							sound.play();
							_clock.restart();
						}

						if ((_buttons[buttons::playout].getColor() != sf::Color::Transparent) && _buttons[buttons::playout].getGlobalBounds().contains(_data->window.mapPixelToCoords(sf::Mouse::getPosition(_data->window))))
						{
							//std::cout << "Pressed playout button" << std::endl;
							_eManager.process(_fManager.loadpro());
							_state = MainLoop_state::playing;
							_saveReady = 1;
							sound.setBuffer(_fManager.getbuffpro());
							sound.play();
							_clock.restart();
						}

					}

					// Effectcheck 
					if (event.type == sf::Event::MouseButtonPressed && _saved == 0)
					{
						if (_eManager.clicked(_data->window))_saveReady = 0 ;
						
						//std::cout << _eManager.check(_data->window) << std::endl;

						std::cout << _saveReady << std::endl;
					}

					if (event.type == sf::Event::KeyPressed && _saved == 0)
					{
						if (_eManager.pressed(_data->window, event.key.code)) _saveReady = 0;
						
						//_eManager.clicked(_data->window, );
						//std::cout << _eManager.check(_data->window) << std::endl;
					}


				}

				if (_state == MainLoop_state::read)
				{
					if (_fManager.loadfile(event) != 2)
					{
						if (_fManager.loadfile(event) == 1)
						{
							_loaded = 1;
						}
						else
						{
							_loaded = 0;
							_texts[2].setFillColor(sf::Color::Red);
						}

						_state = MainLoop_state::work;
					}
				}

				if (_state == MainLoop_state::playing)
				{
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if ((_buttons[buttons::pause].getColor() != sf::Color::Transparent) && _buttons[buttons::pause].getGlobalBounds().contains(_data->window.mapPixelToCoords(sf::Mouse::getPosition(_data->window))))
						{
							_state = MainLoop_state::work;
							sound.stop();
						}
					}

					if (_fManager.getbufforg().getDuration().asMicroseconds() <= _clock.getElapsedTime().asMicroseconds())
					{
						_state = MainLoop_state::work;
						sound.stop();
					}
				}

				// end handle input 
			}


			// update
			if (_state == MainLoop_state::work)
			{
				_buttons[buttons::load].setColor(sf::Color::White) ;
				_buttons[buttons::pause].setColor(sf::Color::Transparent);
				if (_loaded == 1)
				{
					_buttons[buttons::playorg].setColor(sf::Color::White);
					_buttons[buttons::playout].setColor(sf::Color::White);
					_texts[2].setFillColor(sf::Color::Transparent);
				}
				else
				{
					_buttons[buttons::playorg].setColor(sf::Color::Transparent);
					_buttons[buttons::playout].setColor(sf::Color::Transparent);
				}

				if (_saveReady == 1)
				{
					_buttons[buttons::save].setColor(sf::Color::White);
				}
				else
				{
					_buttons[buttons::save].setColor(sf::Color::Transparent);
				}

				if (_saved == 1)
				{
					_texts[3].setFillColor(sf::Color::Green);
				}
				else
				{
					_texts[3].setFillColor(sf::Color::Transparent);
				}
			}

			if (_state == MainLoop_state::read)
			{
				filename.setString(_fManager.getFileName());
				filename.setPosition((SCREEN_WIDHT / 2) - (filename.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - 17 /* filename.getGlobalBounds().height / 2*/);
			}

			if (_state == MainLoop_state::playing)
			{
				_buttons[buttons::playorg].setColor(sf::Color::Transparent);
				_buttons[buttons::pause].setColor(sf::Color::White);
				_buttons[buttons::playout].setColor(sf::Color::Transparent);
				_buttons[buttons::save].setColor(sf::Color::Transparent);
				_buttons[buttons::load].setColor(sf::Color::Transparent);
			}

			// end update 

			//draw

			_data->window.clear(sf::Color::Black);

			if (_state == MainLoop_state::read)
			{
				_data->window.draw(filename);
			}

			if (_state == MainLoop_state::work || _state == MainLoop_state::playing )
			{
				for (unsigned int i = 0; i < _buttons.size(); i++)
				{
					_data->window.draw(_buttons[i]);
				}

				for (unsigned int i = 0; i < _texts.size(); i++)
				{
					_data->window.draw(_texts[i]);
				}
			}

			if (_state == MainLoop_state::work && _loaded == 1 && _saved == 0) _eManager.draw(_data->window);

			_data->window.display();

			// end draw
		}
	}

	void MainLoop::init()
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

		_buttons[2].setPosition(SCREEN_WIDHT / 2 -  (_buttons[2].getGlobalBounds().width / 2), SCREEN_HEIGHT  / 2 - (_buttons[2].getGlobalBounds().height / 2));
		
		_texture[2].loadFromFile(Load_Button_Filepath);

		_buttons[3].setTexture(_texture[2]);

		_buttons[3].setPosition(SCREEN_WIDHT - _buttons[3].getGlobalBounds().width - 30, SCREEN_HEIGHT - 2 * (_buttons[3].getGlobalBounds().height + 20));
		
		_texture[3].loadFromFile(Save_Button_Filepath);

		_buttons[4].setTexture(_texture[3]);

		_buttons[4].setPosition(SCREEN_WIDHT - _buttons[4].getGlobalBounds().width - 30, SCREEN_HEIGHT - (_buttons[4].getGlobalBounds().height + 20));

		_buttons[0].setColor(sf::Color::Transparent);
		_buttons[1].setColor(sf::Color::Transparent);
		_buttons[2].setColor(sf::Color::Transparent);
		_buttons[4].setColor(sf::Color::Transparent);

		sf::Text txt;
		txt.setFont(_font);
		txt.setString("Source File");
		_texts.push_back(txt);
		_texts[0].setPosition(SCREEN_WIDHT - 3 * (_buttons[0].getGlobalBounds().width + 40), SCREEN_HEIGHT - 3 * (_texts[0].getGlobalBounds().height + 19));
		txt.setString("Output File");
		_texts.push_back(txt);
		_texts[1].setPosition(SCREEN_WIDHT - 3 * (_buttons[0].getGlobalBounds().width + 40), SCREEN_HEIGHT - 1 * (_texts[1].getGlobalBounds().height + 32));
		txt.setString("File doesn`t exist");
		_texts.push_back(txt);
		_texts[2].setPosition(SCREEN_WIDHT / 2 - _texts[2].getGlobalBounds().width / 2, SCREEN_HEIGHT / 3);
		txt.setString("File Saved");
		_texts.push_back(txt);
		_texts[3].setPosition(SCREEN_WIDHT / 2 - _texts[3].getGlobalBounds().width / 2, SCREEN_HEIGHT / 3);

		_texts[2].setFillColor(sf::Color::Transparent);
		_texts[3].setFillColor(sf::Color::Transparent);
	}
}