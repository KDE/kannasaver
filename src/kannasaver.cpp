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

#include <stdlib.h>
#include <kapplication.h>
#include <klocale.h>
#include <kconfig.h>
#include <qcheckbox.h>
#include <qcolor.h>
#include <qfontdatabase.h>
#include <qlabel.h>
#include <qmessagebox.h>
#include <qtimer.h>
#include <qpainter.h>
#include <kglobal.h>
#include <kfontcombo.h>
#include <qradiobutton.h>
#ifdef DEBUG
#include <iostream.h>
#endif
#include "kannasaver.h"
#include "kannasaverui.h"
#include "kana.h"

//! libkscreensaver interface
extern "C"
{
    const char *kss_applicationName = "kannasaver.kss";
    const char *kss_description = I18N_NOOP( "kannasaver" );
    const char *kss_version = "2.2.0";

    kannasaver *kss_create( WId id )
    {
        KGlobal::locale()->insertCatalogue("kannasaver");
        return new kannasaver( id );
    }

    QDialog *kss_setup()
    {
        KGlobal::locale()->insertCatalogue("kannasaver");
        return new kannasaverSetup();
    }
}

//-----------------------------------------------------------------------------
//! dialog to setup screen saver parameters
kannasaverSetup::kannasaverSetup( QWidget *parent, const char *name )
        : kannasaverUI( parent, name, TRUE )
{
    if(UsableFontList.empty()) {
    	QFontDatabase fdb;
	QStringList KatakanaFonts(fdb.families(QFont::Katakana));
    	QStringList HiraganaFonts(fdb.families(QFont::Hiragana));
    
    // find all fonts that have both charsets, and are smoothly scalable
    	for(QStringList::Iterator s = HiraganaFonts.begin(); s != HiraganaFonts.end(); ++s) 
    		if(fdb.isSmoothlyScalable(*s) && !(KatakanaFonts.grep(*s).empty())) {
#ifdef DEBUG
			cout << *s << endl; 
#endif
			UsableFontList+=*s;
		};
    }
    		
    if(!(UsableFontList.empty())) FontSelector->setFonts(UsableFontList);
    
    //Connect your signals and slots here to configure the screen saver.
    connect( (QObject *)OkayPushButton, SIGNAL( released() ),
             SLOT( slotOkPressed() ) );
    connect( (QObject *)CancelPushButton, SIGNAL( released() ),
             SLOT( slotCancelPressed() ) );
	     
    
    readSettings();     

}


//! read settings from config file
void kannasaverSetup::readSettings()
{
    KConfig *config = KGlobal::config();
    config->setGroup( "Settings" );
    // Add your config options here...
    FontSelector->setCurrentFont( config->readEntry("defaultFontFamily", UsableFontList[0]) );
    CharSetToUse = config->readNumEntry("CharSetToUse",0);
    SaverMode = config->readNumEntry("SaverMode", 0);

#ifdef DEBUG
	cout << "SaverMode: " << SaverMode << endl;
	cout << "CharsetToUse: " << CharSetToUse << endl;
#endif
    
    switch(CharSetToUse) {
    	case 2: Mixed->setChecked(true);
    		break;
	case 1: Katakana->setChecked(true);
		break;
	case 0: Hiragana->setChecked(true);
		break;
    };

    switch(SaverMode){
	case 2: CompoundChars->setChecked(true);
                break;
	case 1: ExtendedChars->setChecked(true);
		break;
	case 0: BasicChars->setChecked(true);
		break;
    };    
}


//! Ok pressed - save settings and exit
void kannasaverSetup::slotOkPressed()
{
    KConfig *config = KGlobal::config();
    config->setGroup( "Settings" );
    
    // Add your config options here.
    CharSetToUse=(Mixed->isChecked()?2:(Katakana->isChecked()?1:0));
    SaverMode=(CompoundChars->isChecked()?2:(ExtendedChars->isChecked()?1:0));
    config->writeEntry( "defaultFontFamily", FontSelector->currentFont() );
    config->writeEntry( "SaverMode", SaverMode);
    config->writeEntry( "CharSetToUse", CharSetToUse); 

    config->sync();
    accept();
}

void kannasaverSetup::slotCancelPressed()
{
    reject();
}
//-----------------------------------------------------------------------------



kannasaver::kannasaver( WId id ) : KScreenSaver( id )
{
    QFontDatabase fdb;
    QStringList KatakanaFonts(fdb.families(QFont::Katakana));
    QStringList HiraganaFonts(fdb.families(QFont::Hiragana));
    
    // find all fonts that have both charsets, and are smoothly scalable
    for(QStringList::Iterator s = HiraganaFonts.begin(); s != HiraganaFonts.end(); ++s) 
    		if(fdb.isSmoothlyScalable(*s) && !(KatakanaFonts.grep(*s).empty())) {
#ifdef DEBUG
			cout << *s << endl; // 
#endif
			UsableFontList+=*s;
		};
		

    srand(time(0));
    readSettings();
    blank();
}

kannasaver::~kannasaver()
{}


//! read configuration settings from config file
void kannasaver::readSettings()
{
    KConfig *config = KGlobal::config();
    config->setGroup( "Settings" );
    // Add your config options here...
    KanaFontName = config->readEntry("defaultFontFamily", UsableFontList[0]);
    SaverMode = config->readNumEntry("SaverMode", 0);
    CharSetToUse = config->readNumEntry("CharSetToUse",0);
#ifdef DEBUG
	cout << "Fontname from rc file: " << KanaFontName << endl;
	cout << "SaverMode: " << SaverMode << endl;
	cout << "CharsetToUse: " << CharSetToUse << endl;
#endif
}


void kannasaver::blank()
{
    
    if(UsableFontList.empty()) {
    	QMessageBox mb(tr2i18n("Kannasaver"), tr2i18n("There are no usable (That is, capable of Hiragana or Katakana, and\n soft-scalable) fonts on your system. You must get and install\nsome before using this screensaver. SuSE comes with several\nsuitable fonts, you just have to install them in yast. Users\nof other Linux distributions should google for one of the following:\n\"Kochi Gothic\" or \"Baekmuk Gulim\"."),
	QMessageBox::Critical,QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
	if(mb.exec()==QMessageBox::Ok) exit(-1);
    }
    
    kanaFont = new QFont(KanaFontName);
    
    // use the systemwide default font for the romaji
    romajiFont = new QFont();
    
    int myheight = height();
    
    // kana are shown in 1/4 of screen height
    kanaFont->setPixelSize(myheight/4);
    
    // romaji are shown in 1/10 of screen height
    romajiFont->setPixelSize(myheight/10);
    
#ifdef DEBUG
    cout << "Kana Font: " << kanaFont->family() << endl ;
    cout << "Romaji Font: " << romajiFont->family() << endl ;
#endif    
    
    setBackgroundColor( QColor(black)  );
    erase();
    counter=0;
    
    the_timer = new QTimer();
    connect(the_timer, SIGNAL(timeout()), SLOT(draw_kana())); 
    the_timer->start(5000, FALSE);
}


/*!
    \fn kannasaver::draw_kana()
 */
void kannasaver::draw_kana()
{
    QPainter paint(this);
    
    int mywidth = width();
    int myheight = height();
    bool style=(CharSetToUse==2?rand()%2:CharSetToUse);
    counter = (int) rand()%(SaverMode==2?104:(SaverMode==1?74:46));

#ifdef DEBUG
    cout  << "Stil: " << style << "; Char: " << kanatable[counter].pRomaji << " " ;
    cout << (style?kanatable[counter].pKatakana:kanatable[counter].pHiragana)<< endl;
#endif 


    paint.setClipping(false);
    paint.setPen( Qt::white );
    paint.eraseRect(0,0,mywidth,myheight);        
    
    paint.setFont(*kanaFont);
    paint.drawText(mywidth/3,myheight/3, 
    		   (mywidth/3),(myheight/3),
                   Qt::AlignCenter|Qt::DontClip,
		   (style?
		   	(QString::fromUtf8(kanatable[counter].pKatakana)):(QString::fromUtf8(kanatable[counter].pHiragana))), -1);
    
    paint.setFont(*romajiFont);    
    paint.drawText(3*(mywidth/4),3*(myheight/4),mywidth/4,myheight/4,
		   Qt::AlignCenter|Qt::DontClip,
		   QString::fromUtf8(kanatable[counter].pRomaji, -1));


}

void kannasaverSetup::FontChanged()
{
#ifdef DEBUG
	cout << "Font highlighted: " << FontSelector->currentFont() << endl;
#endif
	FontSample->setFont(QFont(FontSelector->currentFont(), 12,0,0));
}



