#include "globpch.h"
#include "Application.h"

#include "Globalika/Events/ApplicationEvent.h"
#include "Globalika/Log.h"

#include <GLFW/glfw3.h>


namespace Globalika {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.4,0.2,1.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}