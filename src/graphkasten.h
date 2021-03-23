#ifndef GK_GRAPHKASTEN_H
#define GK_GRAPHKASTEN_H

#include "gui/graphview.h"
#include "gui/searchbar.h"
#include "lib/graph.h"

#include <gtkmm/grid.h>
#include <gtkmm/window.h>

class Graphkasten final : public Gtk::Window
{
  public:
	Graphkasten();
	~Graphkasten();

  private:
	Gtk::Grid m_grid;

	GUI::Searchbar m_searchbar;
	GUI::Graphview m_graphview;

	GraphModel::Graph *m_graph;
};

#endif
