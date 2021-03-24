#include "graphkasten.h"
#include <filesystem>

Graphkasten::Graphkasten()
{
	// Initialize the graph model
	ReloadGraphModel("/home/krystof/Wikis/zettel/text/");

	// Initialize the UI
	set_title("Graphkasten");
	set_border_width(10);
	set_default_geometry(300, 200);

	add(m_grid);
	m_searchbar.set_margin_bottom(10);
	m_graphview.set_vexpand(true);

	m_grid.attach(m_searchbar, 0, 0, 100, 1);
	m_grid.attach_next_to(m_graphview, m_searchbar, Gtk::POS_BOTTOM, 100, 1);

	m_grid.show_all_children();
	m_grid.show();
}

Graphkasten::~Graphkasten()
{
	delete m_graph;
}

void Graphkasten::ReloadGraphModel(std::string folder_path)
{
	if ( std::filesystem::is_directory(folder_path) )
	{
		delete m_graph;
		m_graph = new GraphModel::Graph(folder_path);
	}
}
