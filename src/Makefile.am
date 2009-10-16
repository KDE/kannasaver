# Makefile.am for kannasaver.
#

AM_CPPFLAGS = -UQT_NO_ASCII_CAST
METASOURCES = AUTO

INCLUDES = $(all_includes)
AM_LDFLAGS = $(all_libraries) $(KDE_RPATH)
LDADD = $(LIB_KDEUI) -lkscreensaver -lm
bin_PROGRAMS = kannasaver.kss

kannasaver_kss_SOURCES = kannasaverui.ui kannasaver.cpp
kannasaver_kss_LDADD = $(LIB_QT) $(LIB_KDECORE) $(LDADD)  $(LIB_KSYCOCA)

datadir = $(prefix)/share

desktop_DATA = kannasaver.desktop
desktopdir = $(kde_appsdir)/System/ScreenSavers

EXTRA_DIST = $(desktop_DATA)

messages: rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/kannasaver.pot
noinst_HEADERS =  kana.h
