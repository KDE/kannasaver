/***************************************************************************
 *   Kannasaver - A screensaver for KDE showing Japanese Characters        *
 *   Copyright (C) 2009  Frederik Schwarzer <schwarzerf@gmail.com>    *
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

#include <QWidget>

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
SetupDlg::SetupDlg( QWidget *parent ) : KDialog( parent )
{
    init();
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
    setButtons( KDialog::Ok | KDialog::Cancel | KDialog::Help );
    ui = new SetupDlgWidget( this );
    setMainWidget( ui );
    showButtonSeparator( true );
    enableButtonOk( false );
}


// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
