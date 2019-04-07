#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <memory>
#include "effect.h"
#include "wah_wah_effect.h"
#include "fuzz_effect.h"
#include "delay_effect.h"
#include "ring_effect.h"
#include "main_loop.h"
#include "effect_manager.h"

#include "definitions.h"

using namespace std;

string path = "Sounds/test_gs.wav";

int main()
{

	//GE::effect_manager man;
	//GE::file_manager dada;
	GE::main_loop( SCREEN_WIDHT, SCREEN_HEIGHT , "Guitar Effect");

/*
	
	sf::SoundBuffer buffer;
	if ( buffer.loadFromFile("test.wav") )  cout << " dziala " << endl;
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

	
	//sound.play();

	int a;
	cin >> a;


	//eff = make_unique <GE::delay_effect>();

	//eff->process(buffer);
	eff = make_unique <GE::wah_wah_effect> ();
	eff->process(buffer);
	//eff = make_unique <GE::fuzz_effect>();
	//eff->process(buffer);
	//eff = make_unique <GE::ring_effect>(); 
	//eff->process(buffer);

	sound.setBuffer(buffer);
	sound.play();

	system("pause");
	
	*/
}

