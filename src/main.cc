#include <memory>
#include "App.h"

/**
 * Main entry point when running the application via it's executable
 * Check PythonBindings.cc for entry via Python
 */
int main(int argc, char ** argv)
{
	std::shared_ptr<App> app = std::shared_ptr<App>();
	app->Run();
}
