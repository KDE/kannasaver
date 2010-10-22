/***************************************************************************
 *   Kannasaver - A Screensaver for KDE showing Japanese Characters        *
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

#include <kaboutdata.h>


class KannasaverInterface : public KScreenSaverInterface
{
    public:
        KannasaverInterface()
        {
            m_about = new KAboutData ( "kannasaver.kss", 0,
                                ki18n ( "Kannasaver" ), "1.2-dev",
                                ki18n ( "A screensaver that shows Japanese characters." ),
                                KAboutData::License_GPL,
                                ki18n ( "Copyright 2004 Mathias Homann<br/>Copyright 2009 Frederik Schwarzer" ),
                                KLocalizedString(),
                                "foo" );
            m_about->addAuthor ( ki18n ( "Mathias Homann" ),
                                    ki18n ( "Original author of Kannasaver." ),
                                    "Mathias.Homann@eregion.de" );
            m_about->addAuthor ( ki18n ( "Frederik Schwarzer" ),
                                    ki18n ( "Port to KDE4" ),
                                    "schwarzerf@gmail.com" );
        }

        ~KannasaverInterface()
        {
            delete m_about;
        }
        
        
        virtual KAboutData *aboutData()
        {
            return m_about;
        }

        virtual KScreenSaver *create(WId id)
        {
            return new Kannasaver ( id );
        }

        virtual QDialog *setup()
        {
            return new SetupDlg();
        }
        
    private:
        KAboutData* m_about;

};


int main( int argc, char *argv[] )
{
    KannasaverInterface kss;
    return kScreenSaverMain ( argc, argv, kss );
}


// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
 
