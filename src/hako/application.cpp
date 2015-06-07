#include <hako/application.h>
#include <hako/common/debug.h>
#include <hako/engine/bindings.h>
#include <stdio.h>


void test_fixed_task(void* unused, Hako::Engine* engine);


Hako::Options* Hako::Application::on_startup(Hako::Engine* engine)
{
	HAKO_UNUSED(engine);

	printf("Hako::Application::on_startup\n");

	return nullptr;
}


void Hako::Application::on_ready(Hako::Engine* engine)
{
	printf("Hako::Application::on_ready\n");

	//
	// Create a material.
	//
	const char* vshader_source = "in vec3 position; void main() { gl_Position = vec4(position, 1); }";
	const char* pshader_source = "out vec4 color; void main() { color = vec4(1, 0, 0, 1); }";
	void* vshader_data = (void*)const_cast<char*>(vshader_source);
	void* pshader_data = (void*)const_cast<char*>(pshader_source);

	Hako::Gfx::ShaderData vshader;
	vshader.init(engine);
	vshader.add_attribute(Hako::Gfx::ShaderData::Attribute::Format::Float3, 0);
	vshader.set_program_data(vshader_data, strlen(vshader_source));
	vshader.finish();

	Hako::Gfx::ShaderData pshader;
	pshader.init(engine);
	pshader.set_program_data(pshader_data, strlen(pshader_source));
	pshader.finish();

	Hako::Gfx::Material material;
	material.init(engine);
	material.set_shaders(&vshader, &pshader);
	material.set_ztest(Hako::Gfx::MaterialZTest::AlwaysPass);
	material.finish();

	//
	// Create a mesh.
	//
	float mesh_vertices[] =
		{ 0, 0, 0,   1, 0, 0,   0, 1, 0 };
	unsigned int mesh_indices[] =
		{ 0, 1, 2 };
	Hako::Gfx::MeshAttributeFormat mesh_attribs[] =
		{ Hako::Gfx::MeshAttributeFormat::Float3 };

	Hako::Gfx::Mesh mesh;
	mesh.init(engine, 1, mesh_attribs, 3, 3);
	mesh.set_data_float3(0, mesh_vertices);
	mesh.set_indices(mesh_indices);
	mesh.finish();



	//
	// Create a fixed-sync task.
	//
	Hako::Callback<void, Hako::Engine*> fixed_task_callback;
	fixed_task_callback.init(nullptr, test_fixed_task);

	Hako::Task fixed_task;
	fixed_task.init(engine, fixed_task_callback);

	engine->task_add_fixedsync(fixed_task);
}


void test_fixed_task(void* unused, Hako::Engine* engine)
{
	HAKO_UNUSED(unused);
	HAKO_UNUSED(engine);

	static int last_ms = 0;

	if (engine->get_fixed_milliseconds_since_startup() - last_ms > 1000)
	{
		last_ms = engine->get_fixed_milliseconds_since_startup();
		printf("Hako::Application::test_fixed_task (%4d frames/s, %4d fixed/s, %10.3f s since start)\n",
			engine->get_frame_steps_per_second(),
			engine->get_fixed_steps_per_second(),
			engine->get_fixed_milliseconds_since_startup() / 1000.0f);
	}

	Hako::Input::Request input_req;
	input_req.key_code = Hako::Input::KeyCode::KeyboardSpace;
	if (engine->get_input()->GetButton(&input_req))
		printf("Spacebar is held down!\n");
}
