#include "FileManager.h"

namespace GE
{
	FileManager::FileManager()
	{
		_filename = "test";
		_ext = ".wav";
	}

	int FileManager::loadfile(sf::Event event)
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

	sf::SoundBuffer &FileManager::getbufforg()
	{
		return _buffer;
	}
	
	sf::SoundBuffer &FileManager::getbuffpro()
	{
		return _out;
	}

	sf::SoundBuffer &FileManager::loadpro()
	{
		_out.loadFromFile(_filename + _ext);
		return _out;
	}

	void FileManager::savepro()
	{
		_out.saveToFile(_filename + "_processed" + _ext);
	}

	std::string FileManager::getFileName()
	{
		return _filename;
	}
}