#ifndef HAKO_ENGINE_GFX_MESH_H
#define HAKO_ENGINE_GFX_MESH_H


namespace Hako
{
	class Engine;


	namespace Gfx
	{
		enum class MeshAttributeFormat
		{
			Float,
			Float2,
			Float3,
			Float4
		};


		class Mesh_Generic
		{
		public:
			virtual ~Mesh_Generic() { /* Do nothing. */ };

			virtual void init(
				Hako::Engine*    engine,
				unsigned int     attrib_number,
				MeshAttributeFormat* attrib_formats,
				unsigned int     vertex_number,
				unsigned int     index_number) = 0;

			virtual void set_data_float  (unsigned int attrib_index, float* data) = 0;
			virtual void set_data_float2 (unsigned int attrib_index, float* data) = 0;
			virtual void set_data_float3 (unsigned int attrib_index, float* data) = 0;
			virtual void set_data_float4 (unsigned int attrib_index, float* data) = 0;
			virtual void set_indices     (unsigned int* indices) = 0;
			virtual void finish          () = 0;
		};
	}
}


#endif




