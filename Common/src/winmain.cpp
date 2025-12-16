#include <windows.h>
#include "user_application.h"
#include "application_engine.h"

#ifdef WIN32_APP
int WINAPI WinMain (HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR	  lpCmdLine,
					int		  nCmdShow) {
	using namespace wwist;

	ApplicationEngine engine;
	auto app = std::make_unique<UserApplication>();

	if (!engine.Initialize(std::move(app), "TestApp")) {
		MessageBox(nullptr, "Initialize failed.", "Error", MB_OK);
		return -1;
	}

	engine.Run();
	engine.Quit();

	return 0;
}
#endif
