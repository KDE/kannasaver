project( kannasaver.kss )

find_package( KDE4 REQUIRED )
include( KDE4Defaults )
include( MacroLibrary )

add_definitions( ${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
add_definitions( -DQT_NO_CAST_FROM_ASCII )
add_definitions( -DQT_NO_CAST_TO_ASCII )


set ( kscreensaver_FIND_REQUIRED TRUE )

find_path( KSCREENSAVER_INCLUDE_DIR kscreensaver.h ${KDE4_INCLUDE_DIR} )
find_library( KSCREENSAVER_LIBRARY NAMES kscreensaver PATHS ${KDE4_LIB_DIR} )

include( FindPackageHandleStandardArgs )
find_package_handle_standard_args( kscreensaver DEFAULT_MSG KSCREENSAVER_LIBRARY KSCREENSAVER_INCLUDE_DIR )

add_subdirectory( src )

