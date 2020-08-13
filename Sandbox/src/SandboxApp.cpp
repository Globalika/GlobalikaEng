#include <Globalika.h>

class Sandbox : public Globalika::Application
{
public:
	Sandbox() 
	{

	}
	~Sandbox()
	{

	}
};

Globalika::Application* Globalika::CreateApplication()
{
	return new Sandbox();
}