//
// Creator Name: Eli Gurevich
// Date: 29/01/2020
// Contact at: elig2001@gmail.com
//

#pragma once

#include <windows.h>

//
// Description: contains a whole key press and release
//
struct KeyboardInput {
	INPUT press;
	INPUT release;
};

//
// Description: contains wraps of windows api for easier and more specific use
//
class KeyboardInputCreator
{
public:

	struct KeyboardInput create_keyboard_input(int key);  //creates KeyboardInput struct for a key 
	INPUT create_keyboard_press(int key); // creates a single INPUT struct to press a given key
	INPUT create_keyboard_release(int key); // creates a single INPUT struct to release a given key

private:

};

