#pragma once

const double pi = 3.14159265359;
const double power2 = std::pow(2, 15) - 1;

#define SCREEN_WIDHT 500
#define SCREEN_HEIGHT 600

#define Play_Button_Filepath "Resources/Textures/Play.jpg"
#define Pause_Button_Filepath "Resources/Textures/Pause.jpg"
#define Load_Button_Filepath "Resources/Textures/Load.jpg"
#define Save_Button_Filepath "Resources/Textures/Save.jpg"

#define Font_Filepath "Comic Sans.ttf"

#define gray sf::Color(80,80,80)

enum MainLoop_state
{
	read,
	work,
	playing,
	processing
};

enum buttons
{
	playorg,
	playout,
	pause,
	load,
	save
};

