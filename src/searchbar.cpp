#include "searchbar.h"
#include "gtkmm/box.h"
#include <gdkmm/rgba.h>


Searchbar::Searchbar() 
: m_button("Options") {
	// Decorate the searchbox
	
	// Add the searchbox, allowing it to stretch
	pack_start(m_searchbox, Gtk::PACK_EXPAND_WIDGET, 20);
	m_searchbox.set_max_width_chars(999999);

	// Add the Options button
	pack_end(m_button);

	show_all_children();
}

Searchbar::~Searchbar() {

}
