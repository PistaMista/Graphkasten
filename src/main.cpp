#include "graphkasten.h"
#include <gtkmm/application.h>

int main(int argc, char **argv)
{
	auto app = Gtk::Application::create(argc, argv, "org.graphkasten");

	return app->run(Graphkasten::getInstance());
}
