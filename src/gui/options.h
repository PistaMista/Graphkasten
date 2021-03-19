#ifndef GK_OPTIONS_H
#define GK_OPTIONS_H

#include <gtkmm/box.h>
#include <gtkmm/filechooserbutton.h>

class Options : public Gtk::Box { 
	public:
		Options();
		~Options();

	protected:
		Gtk::FileChooserButton m_filechooser;
};

#endif
