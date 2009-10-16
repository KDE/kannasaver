FIND_PROGRAM( GETTEXT_MSGFMT_EXECUTABLE msgfmt )

IF( NOT GETTEXT_MSGFMT_EXECUTABLE )
        MESSAGE( "NOTE: msgfmt not found. Translations will *not* be installed" )
ELSE( NOT GETTEXT_MSGFMT_EXECUTABLE )
        SET( catalogname kannasaver )
        ADD_CUSTOM_TARGET( translations ALL )
        FILE( GLOB PO_FILE de.po )

        GET_FILENAME_COMPONENT( _lang ${PO_FILE} NAME_WE )
        SET( _gmoFile ${CMAKE_CURRENT_BINARY_DIR}/${_lang}.gmo )
        ADD_CUSTOM_COMMAND( TARGET translations
           COMMAND ${GETTEXT_MSGFMT_EXECUTABLE} --check -o ${_gmoFile} ${PO_FILE}
           DEPENDS ${PO_FILE} )
        INSTALL( FILES ${_gmoFile} DESTINATION ${LOCALE_INSTALL_DIR}/${_lang}/LC_MESSAGES/ RENAME ${catalogname}.mo )
ENDIF( NOT GETTEXT_MSGFMT_EXECUTABLE )
