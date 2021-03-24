#include "options.h"
#include "graphkasten.h"
#include <gtkmm/filefilter.h>
#include <gtkmm/label.h>
#include <iostream>

GUI::Options::Options() : m_filechooser("Set folder...")
{
	pack_start(m_filechooser);
	m_filechooser.set_action(Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);

	m_filechooser.signal_file_set().connect(sigc::mem_fun(*this, &Options::filechooser_on_confirm));

	show_all_children();
	show();
}

void GUI::Options::filechooser_on_confirm()
{
	Graphkasten::getInstance().ReloadGraphModel(m_filechooser.get_filename());
}
