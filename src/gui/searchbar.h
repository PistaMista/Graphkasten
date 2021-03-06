#ifndef GK_SEARCHBAR_H
#define GK_SEARCHBAR_H

#include "options.h"
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/popover.h>
#include <gtkmm/searchentry.h>

namespace GUI
{
/**
 * @brief Field for searching the wiki graph.
 */
class Searchbar : public Gtk::Box
{
  public:
	Searchbar();

  protected:
	Gtk::SearchEntry m_searchbox;

	Gtk::Button m_options_button;
	Gtk::Popover m_options_popover;
	Options m_options;

  private:
	void options_on_click();
};
} // namespace GUI

#endif
