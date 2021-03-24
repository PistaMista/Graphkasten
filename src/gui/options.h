#ifndef GK_OPTIONS_H
#define GK_OPTIONS_H

#include <gtkmm/box.h>
#include <gtkmm/filechooserbutton.h>

namespace GUI
{
class Options final : public Gtk::Box
{
  public:
	Options();

  private:
	Gtk::FileChooserButton m_filechooser;
	void filechooser_on_confirm();
};
} // namespace GUI

#endif
