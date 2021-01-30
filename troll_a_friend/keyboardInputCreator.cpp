//
// Creator Name: Eli Gurevich
// Date: 29/01/2020
// Contact at: elig2001@gmail.com
//

#include "keyboardInputCreator.h"


//
// Description: initiates a KeyboardInput struct to simulate a single key input 
// input: key - the ascii value of the key to simulate
//
struct KeyboardInput KeyboardInputCreator::create_keyboard_input(int key)
{
	struct KeyboardInput input = { this->create_keyboard_press(key), this->create_keyboard_release(key) };
	return input;
}


//
// Description: Creates a key press 
// input:key - the ascii value of the key to simulate
//
INPUT KeyboardInputCreator::create_keyboard_press(int key)
{
	INPUT input; 
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = key;
	input.ki.wScan = 0;
	input.ki.dwFlags = 0;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;
	return input;
}

//
// Description: Creates a key release
// input: key - the ascii value of the key to simulate
//
INPUT KeyboardInputCreator::create_keyboard_release(int key)
{
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = key;
	input.ki.wScan = 0;
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;
	return input;
}
