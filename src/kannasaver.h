/***************************************************************************
 *   Copyright (C) 2004 by Mathias Homann                                  *
 *   Mathias.Homann@eregion.de                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef __kannasaver_H__
#define __kannasaver_H__

#include "kscreensaver.h"
#include "kannasaverui.h"

class kannasaver : public KScreenSaver
{
    Q_OBJECT
public:
    kannasaver( WId drawable );
    virtual ~kannasaver();
private:
    void readSettings();
    void blank();
    int SaverMode;
    int CharSetToUse;
    QString KanaFontName;
    QStringList UsableFontList;
    
protected:
    QTimer * the_timer;
    int counter;
    QFont * kanaFont;
    QFont * romajiFont;
protected slots:
    void draw_kana();
};

class kannasaverSetup : public kannasaverUI
{
    Q_OBJECT
public:
    kannasaverSetup( QWidget *parent = NULL, const char *name = NULL );

private slots:
    void slotOkPressed();
    void slotCancelPressed();
    void FontChanged();
private:
    void readSettings();
    kannasaver *saver;
    QStringList UsableFontList;
    int SaverMode;
    int CharSetToUse;
    
};

#endif
