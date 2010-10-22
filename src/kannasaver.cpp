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
#include "kana.h"
#include "preferences.h"

#include <QTimer>
#include <QPainter>

#include <cstdlib>
#include <ctime>


Kannasaver::Kannasaver( WId id ) : KScreenSaver ( id )
{
    setAttribute ( Qt::WA_OpaquePaintEvent, true );

    std::srand( std::time( 0 ) );

    QTimer *timer = new QTimer( this );
    connect( timer, SIGNAL ( timeout() ), SLOT ( update() ) );
    timer->start( Preferences::timer() * 1000 );
}


void Kannasaver::paintEvent( QPaintEvent *e )
{
    Q_UNUSED( e );

    int randomIndex = 0;
    switch( Preferences::mode() ) {
        case Preferences::EnumMode::Basic:
            randomIndex = std::rand() % 46;
            break;
        case Preferences::EnumMode::BasicExtended:
            randomIndex = std::rand() % 74;
            break;
        case Preferences::EnumMode::BasicExtendedCompound:
            randomIndex = std::rand() % 104;
            break;
    }

    QPainter paint( this );
    paint.setClipping ( false );
    paint.fillRect ( rect(), Preferences::backgroundColor() );

    const double coefficient = qMin( width(), height() ) / 100.0;

    QFont kanaFont( Preferences::kanaFont() );
    kanaFont.setPixelSize( Preferences::kanaFontSize() * coefficient );
    paint.setFont( kanaFont );

    paint.setPen( Preferences::kanaFontColor() );
    paint.drawText( rect(), Qt::AlignCenter,
                    Preferences::style() == Preferences::EnumStyle::Hiragana
                      ? QString::fromUtf8( kanatable[ randomIndex ].pKatakana )
                      : QString::fromUtf8( kanatable[ randomIndex ].pHiragana )
                  );

    QFont romajiFont( Preferences::font() );
    romajiFont.setPixelSize( Preferences::fontSize() * coefficient );
    paint.setFont( romajiFont );

    const int border = 5 * coefficient;
    paint.setPen( Preferences::fontColor() );
    paint.drawText( rect().adjusted( border, border, -border, -border ),
                    Qt::AlignBottom | Qt::AlignRight,
                    QString::fromUtf8 ( kanatable[ randomIndex ].pRomaji, -1 )
                  );
}



// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
