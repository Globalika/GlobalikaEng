#include "Application.h"

#include "Globalika/Events/ApplicationEvent.h"
#include "Globalika/Log.h"

namespace Globalika {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		GLOB_TRACE(e);
		while (true);
	}
}