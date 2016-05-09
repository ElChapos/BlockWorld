#include <memory>
#include "App.h"

int main(int argc, char ** argv) {

	std::shared_ptr<App> app = std::shared_ptr<App>();
	app->Run();
}
