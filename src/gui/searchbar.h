#ifndef GK_SEARCHBAR_H
#define GK_SEARCHBAR_H

#include <gtkmm/searchentry.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/popover.h>

class Searchbar : public Gtk::Box {
	public:
		Searchbar();
		~Searchbar();

	protected:
		Gtk::SearchEntry m_searchbox;
		Gtk::Button m_options;
		Gtk::Popover m_options_popover;

	private:
		void options_on_click();

};

#endif
