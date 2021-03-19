#include "graphkasten.h"

Graphkasten::Graphkasten() {
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

Graphkasten::~Graphkasten() {

}
