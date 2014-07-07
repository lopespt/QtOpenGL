
PRO   = QOglTest.pro
QMAKE = /Users/wachs/Qt/5.2.1/clang_64/bin/qmake

all:	QtMakefile
	$(MAKE) -f QtMakefile

clean:
	rm -fr QtMakefile QtMakefile.debug QtMakefile.release debug release

createPro:
	$(QMAKE) -project "QT+=core gui widgets sql network opengl" "CONFIG += console" 

QtMakefile: createPro
	$(QMAKE) -o QtMakefile $(PRO) CONFIG+=debug_and_release

debug:	QtMakefile
	$(MAKE) -f QtMakefile debug

release:	QtMakefile
	$(MAKE) -f QtMakefile release

.PHONY: all clean debug clean-debug release clean-release
