#ifndef GK_GRAPHVIEW_H
#define GK_GRAPHVIEW_H

#include <gtkmm/drawingarea.h>

class Graphview : public Gtk::DrawingArea {
	public:
		Graphview();
		~Graphview();

	protected:
		bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif
