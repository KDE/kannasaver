/***************************************************************************
 *   Kannasaver - A Screensaver for KDE showing Japanese Characters        *
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
#include "preferences.h"
#include "settingswidget.h"

#include <kaboutdata.h>
#include <KConfigDialog>


class KannasaverInterface : public KScreenSaverInterface
{
    public:
        KannasaverInterface();
        ~KannasaverInterface();

        KAboutData *aboutData();
        KScreenSaver *create(WId id);

        QDialog *setup(); // krazy:exclude=qclasses

    private:
        KAboutData* m_about;
};


KannasaverInterface::KannasaverInterface()
  : m_about( 0 )
{
    m_about = new KAboutData( "kannasaver.kss", 0, ki18n( "Kannasaver" ), "1.2-dev" );

    m_about->setShortDescription( ki18n( "A screensaver that shows Japanese characters." ) );
    m_about->setLicense( KAboutData::License_GPL );
    m_about->setCopyrightStatement( ki18n( "Copyright 2004 Mathias Homann<br/>Copyright 2009, 2010 The Kannasaver Developers" ) );

    m_about->addAuthor( ki18n( "Mathias Homann" ), ki18n( "Original author of Kannasaver." ), "Mathias.Homann@eregion.de" );
    m_about->addAuthor( ki18n( "Frederik Schwarzer" ), ki18n( "Initiated the port to KDE4." ), "schwarzerf@gmail.com" );
    m_about->addAuthor( ki18n( "Stefan Böhmann" ), ki18n( "Fixed up the mess left after the KDE4 port." ), "kde@hilefoks.org" );
}


KannasaverInterface::~KannasaverInterface()
{
    delete m_about;
}


KAboutData* KannasaverInterface::aboutData()
{
    return m_about;
}


KScreenSaver* KannasaverInterface::create(WId id)
{
    return new Kannasaver( id );
}


QDialog* KannasaverInterface::setup() // krazy:exclude=qclasses
{
    KConfigDialog *dialog = new KConfigDialog( 0, "SettingsDialog", Preferences::self() );
    dialog->setFaceType( KPageDialog::Plain );
    dialog->addPage( new SettingsWidget, i18n( "General" ) );

    return dialog;
}



int main( int argc, char *argv[] )
{
    KannasaverInterface kss;
    return kScreenSaverMain ( argc, argv, kss );
}

// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
