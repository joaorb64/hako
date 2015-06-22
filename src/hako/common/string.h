#ifndef HAKO_COMMON_STRING_H
#define HAKO_COMMON_STRING_H


#include <string.h>


namespace Hako
{
	// Holds a sequence of Unicode characters, encoded as UTF-8.
	class String
	{
	public:
		String()
		{
			this->is_static = true;
			this->data      = nullptr;
			this->length    = 0;
		}


        static String make_static(const char* c_str)
		{
			String result;
			result.is_static = true;
			result.data      = reinterpret_cast<unsigned char*>(const_cast<char*>(c_str));
			result.length    = strlen(c_str);
			return result;
		}


		char* get_c_str()
			{ return reinterpret_cast<char*>(data); }


		unsigned int get_byte_length()
			{ return length; }


		bool operator == (const Hako::String& other) const
		{
			if (this->is_static && other.is_static)
			{
				return (
					this->data != nullptr &&
					other.data != nullptr &&
					this->data == other.data &&
					this->length == other.length);
			}
			else
				return false;
		}


	protected:
		bool           is_static;
		unsigned char* data;
		unsigned int   length;
	};
}


#endif
