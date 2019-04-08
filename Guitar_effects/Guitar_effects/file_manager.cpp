#include "file_manager.h"

namespace GE
{
	file_manager::file_manager()
	{
		_filename = "test";
		_ext = ".wav";
	}

	int file_manager::loadfile(sf::Event event)
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
			else if ((char)event.text.unicode == 13)
			{
				return (int)_buffer.loadFromFile(_filename + _ext);
			}
			else 
			{
				_filename = _filename + (char)event.text.unicode;
			}
		}
		return 2;
	}

	sf::SoundBuffer &file_manager::getbufforg()
	{
		return _buffer;
	}
	
	sf::SoundBuffer &file_manager::getbuffpro()
	{
		return _out;
	}

	sf::SoundBuffer &file_manager::loadpro()
	{
		_out.loadFromFile(_filename + _ext);
		return _out;
	}

	void file_manager::savepro()
	{
		_out.saveToFile(_filename + "_processed" + _ext);
	}

	std::string file_manager::getFileName()
	{
		return _filename;
	}
}