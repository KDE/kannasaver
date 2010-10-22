/***************************************************************************
 *   Kannasaver - A screensaver for KDE showing Japanese Characters        *
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

#include "kannasaver.h"
#include "setupdlg.h"
#include "kana.h"
#include "preferences.h"

#include <kapplication.h>
#include <kconfig.h>
#include <kconfigdialog.h>
#include <kdebug.h>
#include <kglobal.h>
#include <klocale.h>

#include <QCheckBox>
#include <QFontDatabase>
#include <QMessageBox>
#include <QTimer>
#include <QPainter>

#include <stdlib.h>
#include <time.h>


Kannasaver::Kannasaver( WId id ) : KScreenSaver ( id )
{
    setAttribute ( Qt::WA_OpaquePaintEvent, true );

    srand ( time ( 0 ) );

    QTimer *timer = new QTimer( this );
    connect( timer, SIGNAL ( timeout() ), SLOT ( update() ) );
    timer->start( 5000 );
}


void Kannasaver::paintEvent( QPaintEvent *e )
{
    Q_UNUSED ( e );

    int mywidth = width();
    int myheight = height();

    int randomIndex = 0;
    switch( Preferences::mode() ) {
        case Preferences::EnumMode::Basic:
            randomIndex = rand() % 46;
            break;
        case Preferences::EnumMode::BasicExtended:
            randomIndex = rand() % 74;
            break;
        case Preferences::EnumMode::BasicExtendedCompound:
            randomIndex = rand() % 104;
            break;
    }

    QPainter paint( this );
    paint.setClipping ( false );
    paint.setPen ( Qt::white );
    paint.fillRect ( 0, 0, mywidth, myheight, Qt::black );

    QFont kanaFont;
    kanaFont.setPixelSize( height() / 4 );
    paint.setFont ( kanaFont );
    paint.drawText ( mywidth/3, myheight/3,
                     mywidth/3, myheight/3,
                     Qt::AlignCenter,
                     Preferences::style() == Preferences::EnumStyle::Hiragana
                       ? QString::fromUtf8( kanatable[ randomIndex ].pKatakana )
                       : QString::fromUtf8( kanatable[ randomIndex ].pHiragana )
                   );

    QFont romajiFont;
    romajiFont.setPixelSize( height() / 10 );
    paint.setFont ( romajiFont );
    paint.drawText ( 3* ( mywidth/4 ),3* ( myheight/4 ),mywidth/4,myheight/4,
                     Qt::AlignCenter,
                     QString::fromUtf8 ( kanatable[ randomIndex ].pRomaji, -1 ) );
}



// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
