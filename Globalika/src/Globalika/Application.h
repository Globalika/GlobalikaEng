#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Globalika {
	class GLOBALIKA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:

	};
	// To be defined in CLIENT
	Application* CreateApplication();
}

