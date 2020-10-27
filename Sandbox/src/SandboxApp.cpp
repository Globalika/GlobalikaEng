#include <Globalika.h>

#include "../../imgui/imgui.h"

class ExampleLayer : public Globalika::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		if (Globalika::Input::IsKeyPressed(GLOB_KEY_TAB))
			GLOB_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
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
	}
	~Sandbox()
	{

	}
};

Globalika::Application* Globalika::CreateApplication()
{
	return new Sandbox();
}