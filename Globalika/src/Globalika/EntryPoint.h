#pragma once
#ifdef GLOB_PLATFORM_WINDOWS

extern Globalika::Application* Globalika::CreateApplication();

int main(int argc, char** argv)
{
	Globalika::Log::Init();
	GLOB_CORE_WARN("Initialized Log!");
	int a = 5;
	GLOB_INFO("Hello! Var={0}", a);

	auto app = Globalika::CreateApplication();
	app->Run();
	delete app;
}


#endif
