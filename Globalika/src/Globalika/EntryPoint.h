#pragma once
#ifdef GLOB_PLATFORM_WINDOWS

extern Globalika::Application* Globalika::CreateApplication();

int main(int argc, char** argv)
{
	printf("Globalika Engine\n");
	auto app = Globalika::CreateApplication();
	app->Run();
	delete app;
}


#endif
