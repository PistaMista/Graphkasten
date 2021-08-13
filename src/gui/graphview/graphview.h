#ifndef GK_GRAPHVIEW_H
#define GK_GRAPHVIEW_H

#include <gtkmm/drawingarea.h>

namespace GUI::Graphview
{
/**
 * @brief The viewport that displays the wiki graph.
 */
class Graphview : public Gtk::DrawingArea
{
  public:
	Graphview();

  protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;
	bool OnClick(GdkEventButton *event);
};
} // namespace GUI::Graphview

#endif
