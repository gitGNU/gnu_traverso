/*
    Copyright (C) 2005-2006 Remon Sijrier 
 
    This file is part of Traverso
 
    Traverso is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
 
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA.
 
    $Id: Zoom.h,v 1.7 2008/01/22 20:47:16 r_sijrier Exp $
*/

#ifndef ZOOM_H
#define ZOOM_H

#include "Command.h"

class SheetView;
class TrackView;
class QPoint;

class Zoom : public Command
{
	Q_OBJECT
	Q_CLASSINFO("vzoom_in", tr("Zoom Vertical In"));
	Q_CLASSINFO("vzoom_out", tr("Zoom Vertical Out"));
        Q_CLASSINFO("hzoom_in", tr("Zoom Horizontal In"));
        Q_CLASSINFO("hzoom_out", tr("Zoom Horizontal Out"));
        Q_CLASSINFO("toggle_vertical_horizontal_jog_zoom", tr("Toggle Vertical / Horizontal"));
        Q_CLASSINFO("toggle_expand_all_tracks", tr("Expand/Collapse Tracks"));
        Q_CLASSINFO("track_vzoom_in", tr("Track Vertical Zoom In"));
        Q_CLASSINFO("track_vzoom_out", tr("Track Vertical Zoom Out"));


public :
        Zoom(SheetView* sv, QVariantList args);
        Zoom(TrackView* view, QVariantList args);
        ~Zoom() {};

        int begin_hold();
        int finish_hold();
        int prepare_actions();
	int do_action();
	int undo_action();

        int jog();

        void set_cursor_shape(int useX, int useY);
        void set_collected_number(const QString & collected);

private :
        int m_horizontalJogZoomLastX;
        int m_verticalJogZoomLastY;
	bool m_jogVertical;
	bool m_jogHorizontal;
	qreal m_xScalefactor;
	qreal m_yScalefactor;
        QPoint	m_mousePos;
        QPointF	m_origPos;

        void init(SheetView* sv, TrackView* tv, QVariantList args);
	
        SheetView* m_sv;
        TrackView* m_tv;
	
public slots:
	void vzoom_in(bool autorepeat);
	void vzoom_out(bool autorepeat);
        void hzoom_in(bool autorepeat);
        void hzoom_out(bool autorepeat);
        void track_vzoom_in(bool autorepeat);
        void track_vzoom_out(bool autorepeat);
	void toggle_vertical_horizontal_jog_zoom(bool autorepeat);
        void toggle_expand_all_tracks(bool autorepeat);
};

#endif

