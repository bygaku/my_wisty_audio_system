#include "user_application.h"
#include "application_engine.h"

#ifndef WIN32_APP
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
#else
/** WIN32 APP MODE */
#endif
