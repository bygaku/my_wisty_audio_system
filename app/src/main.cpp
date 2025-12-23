#ifdef WIN32_APP
#include <windows.h>
#endif

#include "user_application.h"
#include "application_engine.h"

#ifdef WIN32_APP
/** WIN32 app mode. */
int WINAPI WinMain (HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR	  lpCmdLine,
					int		  nCmdShow) {
	using namespace wwist;
#ifdef POPUP_CONSOLE
	AllocConsole();
	freopen_s(reinterpret_cast<FILE **>(stdout), "CONOUT$", "w", stdout);
	freopen_s(reinterpret_cast<FILE **>(stderr), "CONOUT$", "w", stderr);
#endif

	ApplicationEngine engine;
	auto app = std::make_unique<UserApplication>();

	if (!engine.Initialize(std::move(app), "TestApp")) {
		MessageBox(nullptr, TEXT("Initialize failed."), TEXT("Error"), MB_OK);
		return -1;
	}

	engine.Run();
	engine.Quit();

#ifdef POPUP_CONSOLE
	Sleep(2000);
	FreeConsole();
#endif
	return 0;
}

#else
/** Console mode. */
int main (int argc, char *argv[]) {
	using namespace wwist;

	ApplicationEngine engine;
	auto app = std::make_unique<UserApplication>();

	if (!engine.Initialize(std::move(app), "TestApp")) {
		printf("!! Initialize Failed !!\n");
		return -1;
	}

	engine.Run();
	engine.Quit();

	return 0;
}
#endif
