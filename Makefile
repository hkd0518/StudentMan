#############################################################################
# Makefile for building: StudentMan
# Generated by qmake (2.01a) (Qt 4.7.0) on: ?? ?? 27 22:52:57 2011
# Project:  StudentMan.pro
# Template: app
# Command: d:\qt\qtsdk\qt\bin\qmake.exe -spec d:\QT\QtSDK\qt\mkspecs\win32-g++ -o Makefile StudentMan.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = d:\qt\qtsdk\qt\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: StudentMan.pro  d:/QT/QtSDK/qt/mkspecs/win32-g++/qmake.conf d:/QT/QtSDK/qt/mkspecs/qconfig.pri \
		d:/QT/QtSDK/qt/mkspecs/modules/qt_webkit_version.pri \
		d:/QT/QtSDK/qt/mkspecs/features/qt_functions.prf \
		d:/QT/QtSDK/qt/mkspecs/features/qt_config.prf \
		d:/QT/QtSDK/qt/mkspecs/features/exclusive_builds.prf \
		d:/QT/QtSDK/qt/mkspecs/features/default_pre.prf \
		d:/QT/QtSDK/qt/mkspecs/features/win32/default_pre.prf \
		d:/QT/QtSDK/qt/mkspecs/features/debug.prf \
		d:/QT/QtSDK/qt/mkspecs/features/debug_and_release.prf \
		d:/QT/QtSDK/qt/mkspecs/features/default_post.prf \
		d:/QT/QtSDK/qt/mkspecs/features/win32/default_post.prf \
		d:/QT/QtSDK/qt/mkspecs/features/win32/rtti.prf \
		d:/QT/QtSDK/qt/mkspecs/features/win32/exceptions.prf \
		d:/QT/QtSDK/qt/mkspecs/features/win32/stl.prf \
		d:/QT/QtSDK/qt/mkspecs/features/shared.prf \
		d:/QT/QtSDK/qt/mkspecs/features/warn_on.prf \
		d:/QT/QtSDK/qt/mkspecs/features/qt.prf \
		d:/QT/QtSDK/qt/mkspecs/features/win32/thread.prf \
		d:/QT/QtSDK/qt/mkspecs/features/moc.prf \
		d:/QT/QtSDK/qt/mkspecs/features/win32/windows.prf \
		d:/QT/QtSDK/qt/mkspecs/features/resources.prf \
		d:/QT/QtSDK/qt/mkspecs/features/uic.prf \
		d:/QT/QtSDK/qt/mkspecs/features/yacc.prf \
		d:/QT/QtSDK/qt/mkspecs/features/lex.prf \
		d:/QT/QtSDK/qt/mkspecs/features/include_source_dir.prf \
		d:/QT/QtSDK/qt/lib/qtmaind.prl
	$(QMAKE) -spec d:\QT\QtSDK\qt\mkspecs\win32-g++ -o Makefile StudentMan.pro
d:\QT\QtSDK\qt\mkspecs\qconfig.pri:
d:\QT\QtSDK\qt\mkspecs\modules\qt_webkit_version.pri:
d:\QT\QtSDK\qt\mkspecs\features\qt_functions.prf:
d:\QT\QtSDK\qt\mkspecs\features\qt_config.prf:
d:\QT\QtSDK\qt\mkspecs\features\exclusive_builds.prf:
d:\QT\QtSDK\qt\mkspecs\features\default_pre.prf:
d:\QT\QtSDK\qt\mkspecs\features\win32\default_pre.prf:
d:\QT\QtSDK\qt\mkspecs\features\debug.prf:
d:\QT\QtSDK\qt\mkspecs\features\debug_and_release.prf:
d:\QT\QtSDK\qt\mkspecs\features\default_post.prf:
d:\QT\QtSDK\qt\mkspecs\features\win32\default_post.prf:
d:\QT\QtSDK\qt\mkspecs\features\win32\rtti.prf:
d:\QT\QtSDK\qt\mkspecs\features\win32\exceptions.prf:
d:\QT\QtSDK\qt\mkspecs\features\win32\stl.prf:
d:\QT\QtSDK\qt\mkspecs\features\shared.prf:
d:\QT\QtSDK\qt\mkspecs\features\warn_on.prf:
d:\QT\QtSDK\qt\mkspecs\features\qt.prf:
d:\QT\QtSDK\qt\mkspecs\features\win32\thread.prf:
d:\QT\QtSDK\qt\mkspecs\features\moc.prf:
d:\QT\QtSDK\qt\mkspecs\features\win32\windows.prf:
d:\QT\QtSDK\qt\mkspecs\features\resources.prf:
d:\QT\QtSDK\qt\mkspecs\features\uic.prf:
d:\QT\QtSDK\qt\mkspecs\features\yacc.prf:
d:\QT\QtSDK\qt\mkspecs\features\lex.prf:
d:\QT\QtSDK\qt\mkspecs\features\include_source_dir.prf:
d:\QT\QtSDK\qt\lib\qtmaind.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec d:\QT\QtSDK\qt\mkspecs\win32-g++ -o Makefile StudentMan.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile

check: first

debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
