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


Kannasaver::Kannasaver ( WId id ) : KScreenSaver ( id )
{
    setAttribute ( Qt::WA_OpaquePaintEvent, true );

    QFontDatabase fdb;
    // FIXME: Is there a way to tell katakana and hiragana apart here? (schwarzer)
    QStringList KatakanaFonts ( fdb.families ( QFontDatabase::Japanese ) );
    QStringList HiraganaFonts ( fdb.families ( QFontDatabase::Japanese ) );

    // find all fonts that have both charsets, and are smoothly scalable
    for ( QStringList::Iterator s = HiraganaFonts.begin(); s != HiraganaFonts.end(); ++s )
        if ( fdb.isSmoothlyScalable ( *s ) && ! ( KatakanaFonts.filter ( *s ).empty() ) )
        {
            kDebug() << *s;
            UsableFontList+=*s;
        }

    srand ( time ( 0 ) );
    readSettings();
    blank();
}

Kannasaver::~Kannasaver()
{
    delete kanaFont;
    delete romajiFont;
}


void Kannasaver::paintEvent ( QPaintEvent *e )
{
    Q_UNUSED ( e );

    QPainter paint ( this );

    int mywidth = width();
    int myheight = height();
    SaverMode = Preferences::style();
    int counter = static_cast<int> ( rand() % ( (SaverMode==2)?104: ( (SaverMode==1)?74:46 ) ) );

    kDebug() << "Stil: " << ( CharSetToUse==1 ) << "; Range: " << SaverMode << "; Char: " << kanatable[counter].pRomaji << ( ( CharSetToUse==1 )?kanatable[counter].pKatakana:kanatable[counter].pHiragana );

    paint.setClipping ( false );
    paint.setPen ( Qt::white );
    paint.fillRect ( 0, 0, mywidth, myheight, Qt::black );

    paint.setFont ( *kanaFont );
    paint.drawText ( mywidth/3,myheight/3,
                     mywidth/3,myheight/3,
                     Qt::AlignCenter,
                     ( ( CharSetToUse==1 ) ?
                       ( QString::fromUtf8 ( kanatable[counter].pKatakana ) ) :
                       ( QString::fromUtf8 ( kanatable[counter].pHiragana ) ) ) );

    paint.setFont ( *romajiFont );
    paint.drawText ( 3* ( mywidth/4 ),3* ( myheight/4 ),mywidth/4,myheight/4,
                     Qt::AlignCenter,
                     QString::fromUtf8 ( kanatable[counter].pRomaji, -1 ) );
}

void Kannasaver::readSettings()
{
}


void Kannasaver::blank()
{
    if ( UsableFontList.empty() )
    {
        QMessageBox mb ( i18n ( "Kannasaver" ),
                         i18n ( "There are no usable (That is, capable of Hiragana or Katakana, and\nsoft-scalable) fonts on your system. You must get and install\nsome before using this screensaver. SuSE comes with several\nsuitable fonts, you just have to install them in yast. Users\nof other Linux distributions should google for one of the following:\n\"Kochi Gothic\" or \"Baekmuk Gulim\"." ),
                         QMessageBox::Critical, QMessageBox::Ok, Qt::NoButton, Qt::NoButton );
        if ( mb.exec() ==QMessageBox::Ok )
        {
            exit ( 1 );
        }
    }

    kanaFont = new QFont ( KanaFontName );

    // use the systemwide default font for the romaji
    romajiFont = new QFont();

    int myheight = height();

    // kana are shown in 1/4 of screen height
    kanaFont->setPixelSize ( myheight/4 );

    // romaji are shown in 1/10 of screen height
    romajiFont->setPixelSize ( myheight/10 );

    kDebug() << "Kana Font: " << kanaFont->family();
    kDebug() << "Romaji Font: " << romajiFont->family();

    QTimer *the_timer = new QTimer();
    connect ( the_timer, SIGNAL ( timeout() ), SLOT ( update() ) );
    the_timer->start ( 5000 );
}

// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
