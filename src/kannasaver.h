/***************************************************************************
 *   Kannasaver - A Screensaver for KDE showing Japanese Characters        *
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

#ifndef KANNASAVER_H
#define KANNASAVER_H

#include <kscreensaver.h>


class Kannasaver : public KScreenSaver
{
    Q_OBJECT
    public:
        Kannasaver(QWidget *parent = 0);
        Kannasaver(WId drawable);
        ~Kannasaver();

    public slots:
        void loadSettings();

        int timerSeconds() const;
        void setTimerSeconds(int value);

        int mode() const;
        void setMode(int value);

        int style() const;
        void setStyle(int value);

        QColor backgroundColor() const;
        void setBackgroundColor(const QColor &color);

        QString fontName() const;
        void setFontName(const QString &name);

        int fontSize() const;
        void setFontSize(int value);

        QColor fontColor() const;
        void setFontColor(const QColor &color);

        QString kanaFontName() const;
        void setKanaFontName(const QString &name);

        int kanaFontSize() const;
        void setKanaFontSize(int value);

        QColor kanaFontColor() const;
        void setKanaFontColor(const QColor &color);

    protected:
        void paintEvent(QPaintEvent *e);

    private slots:
        void updateSign();

    private:
        class Private;
        Private * const d;
};

#endif

// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
