#ifndef GK_GRAPHKASTEN_H
#define GK_GRAPHKASTEN_H

#include "searchbar.h"
#include "graphview.h"

#include <gtkmm/window.h>
#include <gtkmm/grid.h>

class Graphkasten : public Gtk::Window {
	public:
		Graphkasten();
		~Graphkasten();

	protected:
		Gtk::Grid m_grid;

		Searchbar m_searchbar;
		Graphview m_graphview;
};

#endif
