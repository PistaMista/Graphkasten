#ifndef GK_OPTIONS_H
#define GK_OPTIONS_H

#include <gtkmm/box.h>
#include <gtkmm/filechooserbutton.h>

namespace GUI
{
class Options : public Gtk::Box
{
  public:
	Options();

  protected:
	Gtk::FileChooserButton m_filechooser;
};
} // namespace GUI

#endif
