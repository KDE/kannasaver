#!bin/sh
$EXTRACTRC `find src/ -name \*.rc -o -name \*.ui -o -name \*.kcfg` > rc.cpp
$XGETTEXT src/*.cpp rc.cpp -o $podir/kannasaver.pot
rm -f rc.cpp
