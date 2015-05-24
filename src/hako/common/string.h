#ifndef HAKO_COMMON_STRING_H
#define HAKO_COMMON_STRING_H


#include <string.h>


namespace Hako
{
	// Holds a sequence of Unicode characters, encoded as UTF-8.
	class String
	{
	public:
        void init_static(const char* c_str)
		{
			data = reinterpret_cast<unsigned char*>(const_cast<char*>(c_str));
			length = strlen(c_str);
		}

		char* get_c_str()
			{ return reinterpret_cast<char*>(data); }

		unsigned int get_byte_length()
			{ return length; }


	protected:
		unsigned char* data;
		unsigned int   length;
	};
}


#endif
