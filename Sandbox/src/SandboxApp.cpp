#include <Globalika.h>

#include <../vendor/glm/glm/vec3.hpp> // glm::vec3
#include <../vendor/glm/glm/vec4.hpp> // glm::vec4
#include <../vendor/glm/glm/mat4x4.hpp> // glm::mat4
#include <../vendor/glm/glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}

class ExampleLayer : public Globalika::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

		auto cam = camera(5.0f, { 0.5f, 0.5f });

	}

	void OnUpdate() override
	{
		if (Globalika::Input::IsKeyPressed(GLOB_KEY_TAB))
			GLOB_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Globalika::Event& event) override
	{
		if (event.GetEventType() == Globalika::EventType::KeyPressed)
		{
			Globalika::KeyPressedEvent& e = (Globalika::KeyPressedEvent&)event;
			if (e.GetKeyCode() == GLOB_KEY_TAB)
				GLOB_TRACE("Tab key is pressed (event)!");
			GLOB_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Globalika::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Globalika::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

Globalika::Application* Globalika::CreateApplication()
{
	return new Sandbox();
}