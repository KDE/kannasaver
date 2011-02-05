/***************************************************************************
 *   Kannasaver - A Screen Saver for KDE showing Japanese Characters        *
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

#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
    class SettingsWidget;
}


class SettingsWidget : public QWidget
{
    Q_OBJECT

    public:
        explicit SettingsWidget( QWidget *parent = 0);
        ~SettingsWidget();

    private:
        Ui::SettingsWidget *ui;
};

#endif

// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
