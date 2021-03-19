#ifndef GK_SEARCHBAR_H
#define GK_SEARCHBAR_H

#include <gtkmm/searchentry.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>

class Searchbar : public Gtk::Box {
	public:
		Searchbar();
		~Searchbar();

	protected:
		Gtk::SearchEntry m_searchbox;
		Gtk::Button m_button;

};

#endif
