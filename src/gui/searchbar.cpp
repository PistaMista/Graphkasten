#include "searchbar.h"
#include "gtkmm/box.h"
#include <gdkmm/rgba.h>
#include <iostream>


Searchbar::Searchbar() 
: m_options("Options"),
  m_options_popover(m_options) {
	// Decorate the searchbox
	
	// Add the searchbox, allowing it to stretch
	pack_start(m_searchbox, Gtk::PACK_EXPAND_WIDGET, 20);
	m_searchbox.set_max_width_chars(999999);

	// Add the Options button
	m_options.signal_clicked().connect(sigc::mem_fun(*this, &Searchbar::options_on_click));
	pack_end(m_options);

	show_all_children();
}

Searchbar::~Searchbar() {

}

void Searchbar::options_on_click() {
	m_options_popover.popup();
}
