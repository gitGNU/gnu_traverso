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

    $Id: PluginChainView.h,v 1.4 2007/01/25 19:21:20 r_sijrier Exp $
*/

#ifndef PLUGIN_CHAIN_VIEW_H
#define PLUGIN_CHAIN_VIEW_H


#include "ViewItem.h"
#include <QString>

class TrackView;
class Plugin;
class PluginChain;
class PluginView;

class PluginChainView : public ViewItem
{
        Q_OBJECT

public:
        PluginChainView(TrackView* view, PluginChain* chain);
        ~PluginChainView();

        void paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
        TrackView* 		m_trackView;
        QList<PluginView* >	m_pluginViews;

public slots:
        void add_new_pluginview(Plugin* plugin);
        void remove_pluginview(Plugin* plugin);
};

#endif

//eof

