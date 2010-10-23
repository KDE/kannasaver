/***************************************************************************
 *   Kannasaver - A screensaver for KDE showing Japanese Characters        *
 *   Copyright 2004  Mathias Homann <Mathias.Homann@eregion.de>            *
 *   Copyright 2009  Frederik Schwarzer <schwarzerf@gmail.com>             *
 *   Copyright 2010  Stefan Böhmann <kde@hilefoks.org>                     *
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


struct Kannasaver::Private
{
    Private()
      : timerSeconds( 0 ),
        mode( 0 ),
        style( 0 ),
        fontSize( 0 ),
        kanaFontSize( 0 )
    {
        std::srand( std::time( 0 ) );
    }

    QTimer timer;
    int timerSeconds;
    int mode;
    int style;
    QColor backgroundColor;

    QString fontName;
    int fontSize;
    QColor fontColor;

    QString kanaFontName;
    int kanaFontSize;
    QColor kanaFontColor;

    QPair<QString, QString> sign;
};



Kannasaver::Kannasaver(QWidget *parent)
  : KScreenSaver(),
    d( new Kannasaver::Private )
{
    Q_UNUSED( parent );

    setAttribute ( Qt::WA_OpaquePaintEvent, true );

    connect( &(d->timer), SIGNAL ( timeout() ), SLOT ( updateSign() ) );

    loadSettings();
}


Kannasaver::Kannasaver(WId id)
  : KScreenSaver( id ),
    d( new Kannasaver::Private )
{
    setAttribute ( Qt::WA_OpaquePaintEvent, true );

    connect( &(d->timer), SIGNAL ( timeout() ), SLOT ( updateSign() ) );

    loadSettings();
}


Kannasaver::~Kannasaver()
{
    delete d;
}


void Kannasaver::loadSettings()
{
    d->timerSeconds = Preferences::timer();
    d->mode = Preferences::mode();
    d->style = Preferences::style();
    d->backgroundColor = Preferences::backgroundColor();
    d->fontName = Preferences::font();
    d->fontSize = Preferences::fontSize();
    d->fontColor = Preferences::fontColor();
    d->kanaFontName = Preferences::kanaFont();
    d->kanaFontSize = Preferences::kanaFontSize();
    d->kanaFontColor = Preferences::kanaFontColor();

    d->timer.start( d->timerSeconds * 1000 );

    updateSign();
}


int Kannasaver::timerSeconds() const
{
    return d->timerSeconds;
}


void Kannasaver::setTimerSeconds(int value)
{
    d->timerSeconds = qBound( 1, value, 60 );
    d->timer.start( d->timerSeconds * 1000 );
}


int Kannasaver::mode() const
{
    return d->mode;
}


void Kannasaver::setMode(int value)
{
    d->mode = value;
    updateSign();
}


int Kannasaver::style() const
{
    return d->style;
}


void Kannasaver::setStyle(int value)
{
    d->style = value;
    updateSign();
}


QColor Kannasaver::backgroundColor() const
{
    return d->backgroundColor;
}


void Kannasaver::setBackgroundColor(const QColor &color)
{
    d->backgroundColor = color;
    update();
}


QString Kannasaver::fontName() const
{
    return d->fontName;
}


void Kannasaver::setFontName(const QString &name)
{
    d->fontName = name;
    update();
}


int Kannasaver::fontSize() const
{
    return d->fontSize;
}


void Kannasaver::setFontSize(int value)
{
    d->fontSize = qBound( 0, value, 100 );
    update();
}


QColor Kannasaver::fontColor() const
{
    return d->fontColor;
}


void Kannasaver::setFontColor(const QColor &color)
{
    d->fontColor = color;
    update();
}


QString Kannasaver::kanaFontName() const
{
    return d->kanaFontName;
}


void Kannasaver::setKanaFontName(const QString &name)
{
    d->kanaFontName = name;
    update();
}


int Kannasaver::kanaFontSize() const
{
    return d->kanaFontSize;
}


void Kannasaver::setKanaFontSize(int value)
{
    d->kanaFontSize = qBound( 0, value, 100 );
    update();
}


QColor Kannasaver::kanaFontColor() const
{
    return d->kanaFontColor;
}


void Kannasaver::setKanaFontColor(const QColor &color)
{
    d->kanaFontColor = color;
    update();
}


void Kannasaver::paintEvent(QPaintEvent *event)
{
    Q_UNUSED( event );

    QPainter paint( this );
    paint.setClipping ( false );
    paint.fillRect ( rect(), backgroundColor() );

    const double coefficient = qMin( width(), height() ) / 100.0;

    QFont kanaFont( kanaFontName() );
    kanaFont.setPixelSize( kanaFontSize() * coefficient );
    paint.setFont( kanaFont );

    paint.setPen( kanaFontColor() );
    paint.drawText( rect(), Qt::AlignCenter, d->sign.first );

    QFont romajiFont( fontName() );
    romajiFont.setPixelSize( fontSize() * coefficient );
    paint.setFont( romajiFont );

    const int border = 5 * coefficient;
    const QRect borderedRect = rect().adjusted( border, border, -border, -border );

    paint.setPen( fontColor() );
    paint.drawText( borderedRect, Qt::AlignBottom | Qt::AlignRight, d->sign.second );
}


void Kannasaver::updateSign()
{
    int randomIndex = 0;
    switch( mode() ) {
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

    d->sign.first = style() == Preferences::EnumStyle::Hiragana
                   ? QString::fromUtf8( kanatable[ randomIndex ].pKatakana )
                   : QString::fromUtf8( kanatable[ randomIndex ].pHiragana );

    d->sign.second = QString::fromUtf8( kanatable[ randomIndex ].pRomaji, -1 );

    update();
}


// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
