#include "file_manager.h"

namespace GE
{
	filemanager::filemanager()
	{
		_filename = "test";
		_ext = ".wav";
	}

	int filemanager::loadfile(sf::Event event)
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
				if (_buffer.loadFromFile(_filename + _ext) == 1)
				{
					return (int)_processed.loadFromFile(_filename + _ext);
				}
				else return 0;
			}
			else 
			{
				_filename = _filename + (char)event.text.unicode;
			}
		}
		return 2;
	}

	sf::SoundBuffer &filemanager::getbufforg()
	{
		return _buffer;
	}
	
	sf::SoundBuffer &filemanager::getbuffpro()
	{
		return _processed;
	}

	std::string filemanager::getFileName()
	{
		return _filename;
	}
}