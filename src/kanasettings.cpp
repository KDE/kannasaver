/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include "kanasettings.h"

#include <KConfigGroup>
#include <KGlobal>
#include <KSharedConfig>


KanaSettings::KanaSettings()
{
  SetDefaults();
  load();
}

void KanaSettings::SetDefaults()
{
  CharSetToUse=0;
  Style=0;
  TheFont=QString();
}

void KanaSettings::load()
{
    KConfigGroup config( KGlobal::config(), "Settings" );
    CharSetToUse=config.readEntry("CharSetToUse", 0);
    Style=config.readEntry("Style", 0);
    TheFont=config.readEntry("TheFont", "");
}

void KanaSettings::save()
{
    KConfigGroup config( KGlobal::config(), "Settings" );
    config.writeEntry("CharSetToUse", CharSetToUse);
    config.writeEntry("Style", Style);
    config.writeEntry("TheFont",TheFont);
}
