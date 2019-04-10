#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <memory>

#include "Effect.h"
#include "WahWahEffect.h"
#include "FuzzEffect.h"
#include "DelayEffect.h"
#include "RingEffect.h"
#include "MainLoop.h"
#include "EffectManager.h"

#include "definitions.h"

using namespace std;

//string path = "Sounds/test_gs.wav";

int main()
{
	GE::MainLoop( SCREEN_WIDHT, SCREEN_HEIGHT , "Guitar Effect");

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

	std::unique_ptr<GE::Effect> eff;


	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	
	//sound.play();

	int a;
	cin >> a;


	//eff = make_unique <GE::DelayEffect>();

	//eff->process(buffer);
	eff = make_unique <GE::WahWahEffect> ();
	eff->process(buffer);
	//eff = make_unique <GE::FuzzEffect>();
	//eff->process(buffer);
	//eff = make_unique <GE::RingEffect>(); 
	//eff->process(buffer);

	sound.setBuffer(buffer);
	sound.play();

	system("pause");
	
	*/
}

