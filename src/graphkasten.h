#ifndef GK_GRAPHKASTEN_H
#define GK_GRAPHKASTEN_H

#include "gui/graphview/graphview.h"
#include "gui/searchbar.h"
#include "lib/graph.h"

#include <gtkmm/grid.h>
#include <gtkmm/window.h>

/**
 * @brief The main application window.
 *
 * This is the main controller of the application. It implements the Singleton pattern to receive messages from other objects.
 */
class Graphkasten final : public Gtk::Window
{
  public:
	/**
	 * @brief Gets the Singleton instance.
	 */
	static Graphkasten &getInstance()
	{
		static Graphkasten instance;
		return instance;
	};

	/**
	 * @brief Copying an instance of this class is prohibited.
	 */
	Graphkasten(Graphkasten const &) = delete;
	/**
	 * @brief Copying an instance of this class is prohibited.
	 */
	void operator=(Graphkasten const &) = delete;

	/**
	 * @brief Reloads the note graph model.
	 * @param folder_path The path of the folder containing the notes (.wiki files)
	 */
	void ReloadGraphModel(std::string folder_path);

  private:
	Graphkasten();
	~Graphkasten();


	Gtk::Grid m_grid;

	GUI::Searchbar m_searchbar;
	GUI::Graphview::Graphview m_graphview;

	/**
	 * @brief The currently loaded note graph model.
	 */
	GraphModel::Graph *m_graphmodel;
};

#endif
