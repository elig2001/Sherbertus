//
// Creator Name: Eli Gurevich
// Date: 29/01/2020
// Contact at: elig2001@gmail.com
//

#pragma once

#include <windows.h>

//
// Description: Simulates key presses to annoy people
//
class KeyboardInputActionMaker
{
public:

	void alt_tab(unsigned int tab_amount); // simulate key presses alt + tab to focus another program
	void show_desktop(); // simulate key presses winkey + D to focus the Desktop
	void change_language(); // simulate key presses shift + alt to change language
	void caps_lock(); // simulate key press of caps lock to change case

private:

};

