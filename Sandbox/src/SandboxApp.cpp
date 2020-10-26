#include <Globalika.h>

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