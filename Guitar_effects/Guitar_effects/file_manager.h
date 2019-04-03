#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace GE
{
	class filemanager
	{
	public:
		filemanager();

		int loadfile(sf::Event event);
		sf::SoundBuffer &getbufforg();
		sf::SoundBuffer &getbuffpro();

		std::string getFileName();

	private:

		std::string _filename;

		std::string _ext;
		sf::SoundBuffer _buffer;
		sf::SoundBuffer _processed;
	};
}
