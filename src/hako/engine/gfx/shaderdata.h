#ifndef HAKO_ENGINE_GFX_SHADERDATA_H
#define HAKO_ENGINE_GFX_SHADERDATA_H


#include <hako/common/ds/vector.h>
#include <hako/common/string.h>
#include "enums.h"


namespace Hako
{
	class Engine;


	namespace Gfx
	{
		class ShaderData
		{
		public:
			struct Buffer
			{
				DataFormat    format;
				int           position;
				Hako::String  name;
			};


			~ShaderData();
			void init             (Hako::Engine* engine);
			void add_attribute    (Hako::Gfx::DataFormat format, int position, Hako::String name);
			void add_uniform      (Hako::Gfx::DataFormat format, int position, Hako::String name);
			void add_output       (Hako::Gfx::DataFormat format, int position, Hako::String name);
			void set_program_data (void* data, unsigned int length);
			void finish           ();


		public:
			Hako::DS::Vector<Buffer> attributes;
			Hako::DS::Vector<Buffer> uniforms;
			Hako::DS::Vector<Buffer> outputs;

			void*          data;
			unsigned int   length;
		};
	}
}


#endif
