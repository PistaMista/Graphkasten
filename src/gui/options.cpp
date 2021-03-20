#include "options.h"
#include <gtkmm/filefilter.h>

Options::Options() : m_filechooser("Set folder...") {
	pack_start(m_filechooser);
	auto filter = Gtk::FileFilter::create();

	filter->set_name("Directories");
	filter->add_mime_type("inode/directory");

	m_filechooser.set_filter(filter);

	show_all_children();
	show();
}
