//
// Creator Name: Eli Gurevich
// Date: 29/01/2020
// Contact at: elig2001@gmail.com
//

#include <iostream>

#include "KeyboardInputActionMaker.h"
#include "keyboardInputCreator.h"

#define SINGLE_KEY_ACTION_AMOUNT 2
#define SHOW_DESKTOP_ACTION_AMOUNT 4
#define ALT_ASCII_VALUE 0x12
#define TAB_ASCII_VALUE 0x9
#define D_ASCCI_VALUE 0x44


//
// Description: simulates a keyboard press of alt tab to focus another program
// input: tab_amount - amount of tabs to press inside the alt tab procedure
//
void KeyboardInputActionMaker::alt_tab(unsigned int tab_amount)
{
	KeyboardInputCreator input_creator = KeyboardInputCreator();
	struct KeyboardInput alt = input_creator.create_keyboard_input(ALT_ASCII_VALUE);
	struct KeyboardInput tab = input_creator.create_keyboard_input(TAB_ASCII_VALUE);
	INPUT alt_press[SINGLE_KEY_ACTION_AMOUNT - 1] = { alt.press };
	INPUT alt_release[SINGLE_KEY_ACTION_AMOUNT - 1] = { alt.release };
	INPUT tab_inputs[SINGLE_KEY_ACTION_AMOUNT] = { tab.press, tab.release };

	UINT uSent = SendInput(ARRAYSIZE(alt_press), alt_press, sizeof(INPUT));

	for (unsigned int i = 0; i < tab_amount; i++)
	{
		uSent = SendInput(ARRAYSIZE(tab_inputs), tab_inputs, sizeof(INPUT));
	}
	uSent = SendInput(ARRAYSIZE(alt_release), alt_release, sizeof(INPUT));
}


//
// Description: Simulates a press of winkey + D to show desktop
//
void KeyboardInputActionMaker::show_desktop()
{
	KeyboardInputCreator input_creator = KeyboardInputCreator();
	struct KeyboardInput winkey = input_creator.create_keyboard_input(VK_LWIN);
	struct KeyboardInput d = input_creator.create_keyboard_input(D_ASCCI_VALUE);

	INPUT inputs[SHOW_DESKTOP_ACTION_AMOUNT] = { winkey.press, d.press, d.release, winkey.press };
	UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}


//
// Description: simulates a press of alt + shift to switch language
//
void KeyboardInputActionMaker::change_language()
{

	KeyboardInputCreator input_creator = KeyboardInputCreator();
	struct KeyboardInput alt = input_creator.create_keyboard_input(VK_MENU);
	struct KeyboardInput shift = input_creator.create_keyboard_input(VK_LSHIFT);

	INPUT inputs[SHOW_DESKTOP_ACTION_AMOUNT] = { alt.press, shift.press, shift.release, alt.press };
	UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}


//
// Description: simulates a key press on caps_lock to change the case of the letters
//
void KeyboardInputActionMaker::caps_lock()
{
	KeyboardInputCreator input_creator = KeyboardInputCreator();
	struct KeyboardInput caps_lock = input_creator.create_keyboard_input(VK_CAPITAL);

	INPUT inputs[SINGLE_KEY_ACTION_AMOUNT] = { caps_lock.press, caps_lock.release };
	UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

