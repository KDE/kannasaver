project( kannasaver )

find_package( Qt4 REQUIRED )
find_package( KDE4 REQUIRED )

include( KDE4Defaults )

set( kannasaver_SRCS
)

kde4_add_ui_files( kannasaver_SRCS
)

add_definitions( ${QT_DEFINITIONS} ${KDE4_DEFINITIONS} )
remove_definitions( -DQT3_SUPPORT_WARNINGS -DQT3_SUPPORT )

include_directories( ${KDE4_INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR}
           ${CMAKE_CURRENT_BINARY_DIR} ${QT_INCLUDE_DIR} )

kde4_add_executable( kannasaver ${kannasaver_SRCS} )

target_link_libraries( kannasaver
    ${QT_AND_KDECORE_LIBS}
    ${QT_LIBRARIES}
    ${KDE4_KDEUI_LIBS}
    ${KDE4_KIO_LIBS}
)

install( TARGETS kannasaver DESTINATION ${BIN_INSTALL_DIR} )

install( FILES kannasaver.desktop DESTINATION ${XDG_APPS_INSTALL_DIR} )
install( FILES kannasaver.kcfg    DESTINATION ${KCFG_INSTALL_DIR} )
install( FILES kannasaverui.rc    DESTINATION ${DATA_INSTALL_DIR}/kannasaver )

