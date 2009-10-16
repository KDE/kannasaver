project( kannasaver.kss )

cmake_minimum_required( VERSION 2.6.0 FATAL_ERROR )

find_package( KDE4 REQUIRED )
include( KDE4Defaults )
include( MacroLibrary )

add_definitions( ${QT_DEFINITIONS} ${KDE4_DEFINITIONS} -pedantic -std=c++98 -Wstrict-null-sentinel -Wold-style-cast -Woverloaded-virtual -fexceptions )
remove_definitions( -DQT3_SUPPORT_WARNINGS -DQT3_SUPPORT )

set ( kscreensaver_FIND_REQUIRED TRUE )

find_path( KSCREENSAVER_INCLUDE_DIR kscreensaver.h ${KDE4_INCLUDE_DIR} )
find_library( KSCREENSAVER_LIBRARY NAMES kscreensaver PATHS ${KDE4_LIB_DIR} )

include( FindPackageHandleStandardArgs )
find_package_handle_standard_args( kscreensaver DEFAULT_MSG KSCREENSAVER_LIBRARY KSCREENSAVER_INCLUDE_DIR )
find_package_handle_standard_args( libGLU DEFAULT_MSG OPENGL_glu_LIBRARY OPENGL_INCLUDE_DIR )
find_package_handle_standard_args( QtOpenGL DEFAULT_MSG QT_QTOPENGL_LIBRARY QT_QTOPENGL_INCLUDE_DIR )

ADD_SUBDIRECTORY( src )
#ADD_SUBDIRECTORY( l10n )
#ADD_SUBDIRECTORY( doc )

