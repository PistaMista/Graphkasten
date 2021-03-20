#ifndef GK_GRAPHKASTEN_H
#define GK_GRAPHKASTEN_H

#include "gui/searchbar.h"
#include "gui/graphview.h"

#include <gtkmm/window.h>
#include <gtkmm/grid.h>

class Graphkasten : public Gtk::Window {
	public:
		Graphkasten();

	protected:
		Gtk::Grid m_grid;

		Searchbar m_searchbar;
		Graphview m_graphview;
};

#endif
