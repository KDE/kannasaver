project( kannasaver )

cmake_minimum_required( VERSION 2.6.0 FATAL_ERROR )

find_package( KDE4 REQUIRED )
include( KDE4Defaults )
include( MacroLibrary )

add_definitions( ${QT_DEFINITIONS} ${KDE4_DEFINITIONS} -pedantic -std=c++98 -Wstrict-null-sentinel -Wold-style-cast -Woverloaded-virtual -fexceptions )
remove_definitions( -DQT3_SUPPORT_WARNINGS -DQT3_SUPPORT )

ADD_SUBDIRECTORY( src )
ADD_SUBDIRECTORY( l10n )
ADD_SUBDIRECTORY( doc )

