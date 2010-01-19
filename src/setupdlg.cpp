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

/**
 * @file setupdlg.cpp
 * @author Frederik Schwarzer <schwarzerf@gmail.com>
 * @brief Class implementation for the setup dialog
 */

#include "setupdlg.h"
#include "ui_setupdlgwidget.h"
#include "settings.h"

#include <QWidget>
#include <KConfigDialog>

#include <KDebug>

/**
 * @brief Class to set up the setup dialog
 */
class SetupDlgWidget : public QWidget, public Ui::SetupDlgWidget
{
    public:
        SetupDlgWidget( QWidget *parent = 0 ) : QWidget( parent )
    {
        setupUi( this );
    }
};


/**
 * @brief Constructor
 */
SetupDlg::SetupDlg( QWidget *parent ) : KConfigDialog( parent, "preferences", MySettings::self() )
{
    
//An instance of your dialog could be already created and could be
// cached, in which case you want to display the cached dialog 
// instead of creating another one
//   if ( KConfigDialog::showDialog( "preferences" ) )  return; 
 
// KConfigDialog didn't find an instance of this dialog, so lets
// create it : 
//    KConfigDialog* dialog = new KConfigDialog(this, "preferences", MySettings::self()); 

    SetupDlgWidget* confWdg = new SetupDlgWidget( 0 ); 
 
    this->addPage( confWdg, i18n("General"), "preferences" ); 
 
//User edited the configuration - update your local copies of the 
//configuration data 

    connect( this, SIGNAL(settingsChanged()), this, SLOT(updateConfiguration()) ); 
 
    this->show();  
//    init();
}

SetupDlg::~SetupDlg()
{
    delete ui;
}


/**
 * @brief Initialises the dialog's common properties
 */
void SetupDlg::init()
{
//    setButtons( KDialog::Ok | KDialog::Cancel | KDialog::Help );
//    ui = new SetupDlgWidget( this );
//    ui_setupdlgwidget.setupUi(ui);
//    dialog->addPage(generalSettingsDlg, i18n("General"), "package_setting");
//    connect(dialog, SIGNAL(settingsChanged(QString)), m_view, SLOT(settingsChanged()));
//    dialog->setAttribute( Qt::WA_DeleteOnClose );
//    dialog->show();
}


// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
