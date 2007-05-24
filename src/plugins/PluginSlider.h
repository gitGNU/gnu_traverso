/*
Copyright (C) 2006 Remon Sijrier

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

$Id: PluginSlider.h,v 1.3 2007/05/24 23:24:03 r_sijrier Exp $
*/


#ifndef PLUGIN_SLIDER_H
#define PLUGIN_SLIDER_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class LV2ControlPort;

class PluginSlider : public QWidget
{
	Q_OBJECT
	
public:
	PluginSlider(LV2ControlPort* port);
	~PluginSlider(){};
	
	void paint(QPainter *);
	void update_slider_position();
	
protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
        void leaveEvent( QEvent* );
        void enterEvent( QEvent* );
        void wheelEvent(QWheelEvent* e );
	
private:
	LV2ControlPort* m_port;
	float	m_max;
	float	m_min;
	float	m_value;
	float	m_stepvalue;
	int	m_xpos;
	bool	highlight;
	bool 	dragging;
	
	void calculate_new_value(int mouseX);
	
signals:
	void sliderValueChanged(float value);
	void sliderValueChangedDouble(double value);
	
};
 
#endif

//eof
