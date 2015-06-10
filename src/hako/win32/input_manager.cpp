#include "input_manager.h"
#include <hako/common/debug.h>



void Hako::Win32::Input_Manager::init(Hako::Engine* engine)
{
	HAKO_UNUSED(engine);

	this->current_keyboard_buffer = 0;

	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 256; i++)
			this->keyboard_state[j][i] = 0;
	}
}



void Hako::Win32::Input_Manager::process()
{
	this->current_keyboard_buffer = (this->current_keyboard_buffer == 0 ? 1 : 0);
	GetKeyboardState(this->keyboard_state[this->current_keyboard_buffer]);
}



int Hako::Win32::Input_Manager::translate_keyboard_code(Hako::Input::KeyCode c)
{
	//
	// Translate a Hako keycode to a Win32 keyboard code.
	//
	int index = 0;
	unsigned int code = (unsigned int)c;

	if (code >= (unsigned int)Hako::Input::KeyCode::KeyboardAlphabetStart &&
		code <= (unsigned int)Hako::Input::KeyCode::KeyboardAlphabetEnd)
	{
		index = ('A' + (code - (unsigned int)Hako::Input::KeyCode::KeyboardAlphabetStart));
	}
	else if (code >= (unsigned int)Hako::Input::KeyCode::KeyboardNumberStart &&
		code <= (unsigned int)Hako::Input::KeyCode::KeyboardNumberEnd)
	{
		index = ('0' + (code - (unsigned int)Hako::Input::KeyCode::KeyboardNumberStart));
	}
	else if (code == (unsigned int)Hako::Input::KeyCode::KeyboardSpace)      index = VK_SPACE;
	else if (code == (unsigned int)Hako::Input::KeyCode::KeyboardEnter)      index = VK_RETURN;
	else if (code == (unsigned int)Hako::Input::KeyCode::KeyboardArrowUp)    index = VK_UP;
	else if (code == (unsigned int)Hako::Input::KeyCode::KeyboardArrowRight) index = VK_RIGHT;
	else if (code == (unsigned int)Hako::Input::KeyCode::KeyboardArrowDown)  index = VK_DOWN;
	else if (code == (unsigned int)Hako::Input::KeyCode::KeyboardArrowLeft)  index = VK_LEFT;

	return index;
}



bool Hako::Win32::Input_Manager::GetButton(Hako::Input::Request* req)
{
	//
	// Check if keycode is inside keyboard range.
	//
	if ((unsigned int)req->key_code >= (unsigned int)Hako::Input::KeyCode::KeyboardStart &&
		(unsigned int)req->key_code <= (unsigned int)Hako::Input::KeyCode::KeyboardEnd)
	{
		return (this->keyboard_state[this->current_keyboard_buffer]
			[this->translate_keyboard_code(req->key_code)] & 0x80) != 0;
	}
	return false;
}



float Hako::Win32::Input_Manager::GetAxis1(Hako::Input::Request* req)
{
	HAKO_UNUSED(req);
	return 0;
}



Hako::Math::Vec<2> Hako::Win32::Input_Manager::GetAxis2(Hako::Input::Request* req)
{
	HAKO_UNUSED(req);
	return Hako::Math::Vec<2>();
}



Hako::Math::Vec<3> Hako::Win32::Input_Manager::GetAxis3(Hako::Input::Request* req)
{
	HAKO_UNUSED(req);
	return Hako::Math::Vec<3>();
}



void Hako::Win32::Input_Manager::SetAxis1(Hako::Input::Request* req, float x)
{
	HAKO_UNUSED(req);
	HAKO_UNUSED(x);
	// Do nothing.
}



void Hako::Win32::Input_Manager::SetAxis2(Hako::Input::Request* req, float x, float y)
{
	HAKO_UNUSED(req);
	HAKO_UNUSED(x);
	HAKO_UNUSED(y);
	// Do nothing.
}



void Hako::Win32::Input_Manager::SetAxis3(Hako::Input::Request* req, float x, float y, float z)
{
	HAKO_UNUSED(req);
	HAKO_UNUSED(x);
	HAKO_UNUSED(y);
	HAKO_UNUSED(z);
	// Do nothing.
}




