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

$Id: ContextDialog.cpp,v 1.3 2007/01/16 15:24:17 r_sijrier Exp $
*/
 
#include "ContextDialog.h"

#include <QHBoxLayout>

#include <InputEngine.h>
#include <ViewPort.h>

#include <Debugger.h>

ContextDialog::ContextDialog()
	: ViewPort(0)
{
	PENTERCONS;
}

ContextDialog::~ContextDialog()
{
	PENTERDES;
}

void ContextDialog::keyPressEvent( QKeyEvent * e)
{
	if ( (e->key() == Qt::Key_Return) || (e->key() == Qt::Key_Escape) ) {
		close();
	}
	
	if (!e->isAutoRepeat())
		ie().catch_press(e);
	e->ignore();
}

void ContextDialog::keyReleaseEvent( QKeyEvent * e)
{
	if (!e->isAutoRepeat())
		ie().catch_release(e);
	e->ignore();
}


//eof
