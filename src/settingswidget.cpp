/*
 * Copyright 2010 by Stefan Böhmann <kde@hilefoks.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "settingswidget.h"
#include "ui_settingswidget.h"


SettingsWidget::SettingsWidget(QWidget *parent)
  : QWidget( parent ),
    ui( new Ui::SettingsWidget )
{
    ui->setupUi( this );

    connect( ui->kcfg_mode, SIGNAL( currentIndexChanged(int) ), ui->preview, SLOT( setMode(int) ) );
    connect( ui->kcfg_style, SIGNAL( currentIndexChanged(int) ), ui->preview, SLOT( setStyle(int) ) );
    connect( ui->kcfg_backgroundColor, SIGNAL( changed(QColor) ), ui->preview, SLOT( setBackgroundColor(QColor) ) );
    connect( ui->kcfg_timer, SIGNAL( valueChanged(int) ), ui->preview, SLOT( setTimerSeconds(int) ) );
    connect( ui->kcfg_font, SIGNAL( currentIndexChanged(QString) ), ui->preview, SLOT( setFontName(QString) ) );
    connect( ui->kcfg_fontSize, SIGNAL( valueChanged(int) ), ui->preview, SLOT( setFontSize(int) ) );
    connect( ui->kcfg_fontColor, SIGNAL( changed(QColor) ), ui->preview, SLOT( setFontColor(QColor) ) );
    connect( ui->kcfg_kanaFont, SIGNAL( currentIndexChanged(QString) ), ui->preview, SLOT( setKanaFontName(QString) ) );
    connect( ui->kcfg_kanaFontSize, SIGNAL( valueChanged(int) ), ui->preview, SLOT( setKanaFontSize(int) ) );
    connect( ui->kcfg_kanaFontColor, SIGNAL( changed(QColor) ), ui->preview, SLOT( setKanaFontColor(QColor) ) );
}


SettingsWidget::~SettingsWidget()
{
    delete ui;
}


// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
