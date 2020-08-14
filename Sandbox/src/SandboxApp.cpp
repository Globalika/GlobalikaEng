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
		GLOB_INFO("ExampleLayer::Update");
	}

	void OnEvent(Globalika::Event& event) override
	{
		GLOB_TRACE("{0}", event);
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