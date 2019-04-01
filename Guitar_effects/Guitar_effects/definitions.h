#pragma once

const double pi = 3.14159265359;
const double power2 = std::pow(2, 15) - 1;

#define SCREEN_WIDHT 500
#define SCREEN_HEIGHT 600

enum main_loop_state
{
	read,
	work,
	process,
	save,
};

