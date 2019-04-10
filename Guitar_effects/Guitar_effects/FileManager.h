#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace GE
{
	class FileManager
	{
	public:
		FileManager();

		int loadfile(sf::Event event);
		sf::SoundBuffer &getbufforg();
		sf::SoundBuffer &getbuffpro();

		sf::SoundBuffer &loadpro();

		void savepro();

		std::string getFileName();

	private:

		std::string _filename;

		std::string _ext;
		sf::SoundBuffer _buffer;
		sf::SoundBuffer _out;
	};
}
