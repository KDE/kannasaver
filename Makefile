.PHONY: all l10n clean mrproper

all:
	mkdir -p build install
	cd build && cmake ../ -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_BUILD_TYPE=debug && make install

l10n:
	cd l10n && ./extract-messages.sh

clean:
	$(RM) -rf build
	$(RM) -f src/*~
	$(RM) doxygen.log

mrproper: clean
	$(RM) -rf apidocs
	$(RM) -rf install
