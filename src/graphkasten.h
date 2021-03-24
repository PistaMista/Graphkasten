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
	static Graphkasten &getInstance()
	{
		static Graphkasten instance;
		return instance;
	};

	Graphkasten(Graphkasten const &) = delete;
	void operator=(Graphkasten const &) = delete;

	void ReloadGraphModel(std::string folder_path);

  private:
	Graphkasten();
	~Graphkasten();


	Gtk::Grid m_grid;

	GUI::Searchbar m_searchbar;
	GUI::Graphview m_graphview;

	GraphModel::Graph *m_graph;
};

#endif
