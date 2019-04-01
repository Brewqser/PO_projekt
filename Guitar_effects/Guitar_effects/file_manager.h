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
		sf::SoundBuffer &playorg();

		std::string getFileName();

	private:

		std::string _filename;

		std::string _ext;
		sf::SoundBuffer _buffer;
	};
}
