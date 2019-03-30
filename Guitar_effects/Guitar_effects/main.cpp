#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <memory>
#include "effect.h"
#include "wah_wah_effect.h"
#include "overdrive_effect.h"

using namespace std;

string path = "Sounds/test_gs.wav";

int main()
{
	sf::SoundBuffer buffer;
	if ( buffer.loadFromFile(path) )  cout << " dziala " << endl;
	else
	{
		cout << "nie dziala" << endl;
		return 0;
	}

	cout << buffer.getSampleCount() << " " << buffer.getSampleRate() << " " <<  (double)buffer.getSampleCount() / (double) buffer.getSampleRate() << " " << buffer.getChannelCount();
	cout << endl << buffer.getDuration().asMilliseconds() << endl;

	std::unique_ptr<GE::effect> eff;


	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	int a;
	cin >> a;

	//eff = make_unique <GE::wah_wah_effect> ();
	eff = make_unique <GE::overdrive_effect>();
	eff->process(buffer);
	sound.setBuffer(buffer);
	sound.play();

	system("pause");
}

