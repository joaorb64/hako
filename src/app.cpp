#include <hako/common/debug.h>
#include <hako/common/string.h>
#include <hako/engine/app.h>
#include <hako/engine/engine.h>
#include <hako/engine/bindings.h>
#include <stdio.h>
#include <hako/common/ds/refvector.h>


void test_fixed_task(void* unused, Hako::Engine* engine);
void test_frame_task(void* unused, Hako::Engine* engine);


void Hako::App::on_startup(void** userdata, Hako::Engine* engine)
{
	HAKO_UNUSED(userdata);
	HAKO_UNUSED(engine);

	printf("Hako::App::on_startup\n");

	Hako::DS::RefVector<int> my_numbers;
	my_numbers.init(engine->get_mem_callbacks(), 0);
	Hako::DS::RefVector<int>::Reference ref_1 = my_numbers.add(33);
	Hako::DS::RefVector<int>::Reference ref_2 = my_numbers.add(66);
	Hako::DS::RefVector<int>::Reference ref_3 = my_numbers.add(88);

	my_numbers.get_element(&ref_2) = 55;
	my_numbers.get_element(&ref_1) = 44;
	my_numbers.get_element(&ref_3) = 33;
}



Hako::Gfx::ShaderData vshader;
Hako::Gfx::ShaderData pshader;
Hako::Gfx::Material material;
Hako::Gfx::VertexBuffer mesh_positions;
Hako::Gfx::IndexBuffer mesh_indices;
Hako::Gfx::CommandList commandlist;


void Hako::App::on_ready(void* userdata, Hako::Engine* engine)
{
	HAKO_UNUSED(userdata);
	printf("Hako::App::on_ready\n");

	//
	// Set up command list.
	//
	commandlist.init(engine);

	//
	// Create a material.
	//
	const char* vshader_source = "#version 330\n in vec3 position; void main() { gl_Position = vec4(position, 1); }";
	const char* pshader_source = "#version 330\n out vec4 color; void main() { color = vec4(1, 0, 0, 1); }";
	void* vshader_data = (void*)const_cast<char*>(vshader_source);
	void* pshader_data = (void*)const_cast<char*>(pshader_source);

	vshader.init(engine);
	vshader.add_attribute(Hako::Gfx::DataFormat::Float3, 0, Hako::String::make_static("position"));
	vshader.set_program_data(vshader_data, strlen(vshader_source));
	vshader.finish();

	pshader.init(engine);
	pshader.add_output(Hako::Gfx::DataFormat::Float4, 0, Hako::String::make_static("color"));
	pshader.set_program_data(pshader_data, strlen(pshader_source));
	pshader.finish();

	material.init(engine);
	material.set_shaders(&vshader, &pshader);
	material.set_depthtest(Hako::Gfx::DepthTestFunction::AlwaysPass);
	material.finish();

	//
	// Create a mesh.
	//
	float mesh_positions_data[] =
		{ -0.5f, -0.5f, 0,   0, 0.5f, 0,   0.5f, -0.5f, 0 };
	unsigned int mesh_indices_data[] =
		{ 0, 1, 2 };

	mesh_positions.init(engine, Hako::Gfx::DataFormat::Float3, 3);
	mesh_positions.set_data(0, 3, mesh_positions_data);
	mesh_positions.finish();

	mesh_indices.init(engine, 3);
	mesh_indices.set_data(0, 3, mesh_indices_data);
	mesh_indices.finish();

	//
	// Create a fixed-sync task.
	//
	Hako::Callback<void, Hako::Engine*> fixed_task_callback;
	fixed_task_callback.init(nullptr, test_fixed_task);

	Hako::Task fixed_task;
	fixed_task.init(engine, fixed_task_callback);

	engine->task_add_fixedsync(fixed_task);

	//
	// Create a frame-sync task.
	//
	Hako::Callback<void, Hako::Engine*> frame_task_callback;
	frame_task_callback.init(nullptr, test_frame_task);

	Hako::Task frame_task;
	frame_task.init(engine, frame_task_callback);

	engine->task_add_framesync(frame_task);
}



void test_fixed_task(void* unused, Hako::Engine* engine)
{
	HAKO_UNUSED(unused);
	HAKO_UNUSED(engine);

	static int last_ms = 0;

	if (engine->get_fixed_milliseconds_since_startup() - last_ms > 1000)
	{
		last_ms = engine->get_fixed_milliseconds_since_startup();
		printf("Hako::App::test_fixed_task (%4d frames/s, %4d fixed/s, %10.3f s since start)\n",
			engine->get_frame_steps_per_second(),
			engine->get_fixed_steps_per_second(),
			engine->get_fixed_milliseconds_since_startup() / 1000.0f);
	}

	Hako::Input::Request input_req;
	input_req.key_code = Hako::Input::KeyCode::KeyboardSpace;
	if (engine->get_input()->GetButton(&input_req))
		printf("Spacebar is held down!\n");
}




void test_frame_task(void* unused, Hako::Engine* engine)
{
	HAKO_UNUSED(unused);

	commandlist.begin();
	commandlist.set_material(&material);
	commandlist.set_vertex_buffer(0, &mesh_positions);
	commandlist.draw_indexed(&mesh_indices);
	commandlist.finish();

	engine->get_gfx()->commandlist_add(&commandlist);
}
