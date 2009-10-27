project( kannasaver.kss )

find_package( Qt4 REQUIRED )
find_package( KDE4 REQUIRED )

include( KDE4Defaults )

set( kannasaver.kss_SRCS kanasettings.cpp
    kannasaver.cpp
    setupdlg.cpp
)

kde4_add_ui_files( kannasaver.kss_SRCS
    setupdlgwidget.ui
)

kde4_add_kcfg_files( kannasaver.kss_SRCS settings.kcfgc )



add_definitions( ${QT_DEFINITIONS} ${KDE4_DEFINITIONS} )


remove_definitions( -DQT3_SUPPORT_WARNINGS -DQT3_SUPPORT )

include_directories( ${KDE4_INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR}
           ${CMAKE_CURRENT_BINARY_DIR} ${QT_INCLUDE_DIR} )

kde4_add_executable( kannasaver.kss ${kannasaver.kss_SRCS} )

target_link_libraries( kannasaver.kss
    ${QT_AND_KDECORE_LIBS}
    ${QT_LIBRARIES}
    ${KDE4_KDEUI_LIBS}
    ${KDE4_KIO_LIBS}
    ${KSCREENSAVER_LIBRARY}
)

install( TARGETS kannasaver.kss DESTINATION ${INSTALL_TARGETS_DEFAULT_ARGS} )
install( FILES kannasaver.desktop DESTINATION ${SERVICES_INSTALL_DIR}/ScreenSavers )
install( FILES kannasaver_settings.kcfg    DESTINATION ${KCFG_INSTALL_DIR} )
#install( FILES kannasaverui.rc    DESTINATION ${DATA_INSTALL_DIR}/kannasaver )

