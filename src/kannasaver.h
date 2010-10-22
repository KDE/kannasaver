/***************************************************************************
 *   Kannasaver - A Screensaver for KDE showing Japanese Characters        *
 *   Copyright 2004  Mathias Homann <Mathias.Homann@eregion.de>            *
 *   Copyright 2009  Frederik Schwarzer <schwarzerf@gmail.com>             *
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
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#ifndef KANNASAVER_H
#define KANNASAVER_H

#include "setupdlg.h"

#include <kscreensaver.h>

#include <QPaintEvent>
#include <QString>
#include <QStringList>

class QFont;

class Kannasaver : public KScreenSaver
{
    Q_OBJECT
    public:
        Kannasaver( WId drawable );
        virtual ~Kannasaver();
        virtual void paintEvent( QPaintEvent *e );

    private:
        /** read configuration settings from config file */
        void readSettings();
        void blank();
        int SaverMode;
        int CharSetToUse;
        QString KanaFontName;
        // still needed with Qt4?
        QStringList UsableFontList;

    protected:
        QFont *kanaFont;
        QFont *romajiFont;
};

#endif

// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
