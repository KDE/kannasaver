
set( kannasaver.kss_SRCS
    kannasaver.cpp
    settingswidget.cpp
    main.cpp
)

kde4_add_ui_files( kannasaver.kss_SRCS
    settingswidget.ui
)

kde4_add_kcfg_files( kannasaver.kss_SRCS preferences.kcfgc )

include_directories( ${KDE4_INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR}
           ${CMAKE_CURRENT_BINARY_DIR} ${QT_INCLUDE_DIR} )

kde4_add_executable( kannasaver.kss ${kannasaver.kss_SRCS} )

target_link_libraries( kannasaver.kss
    ${KDE4_KDEUI_LIBS}
    ${KSCREENSAVER_LIBRARY}
)

install( TARGETS kannasaver.kss ${INSTALL_TARGETS_DEFAULT_ARGS} )
install( FILES kannasaver.desktop DESTINATION ${SERVICES_INSTALL_DIR}/ScreenSavers )
install( FILES kannasaver.kcfg    DESTINATION ${KCFG_INSTALL_DIR} )
#install( FILES kannasaverui.rc    DESTINATION ${DATA_INSTALL_DIR}/kannasaver )

