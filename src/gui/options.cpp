#include "options.h"
#include <gtkmm/filefilter.h>
#include <gtkmm/label.h>

GUI::Options::Options() : m_filechooser("Set folder...")
{
	pack_start(m_filechooser);
	m_filechooser.set_action(Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);


	show_all_children();
	show();
}
