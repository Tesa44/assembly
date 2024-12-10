all: cprogram asmprogram test asmtest

cprogram: cprogram.c
	gcc -m32 cprogram.c -o cprogram

asmprogram: asmprogram.c
	gcc -m32 asmprogram.c -o asmprogram

test: test.c
	gcc -m32 test.c -o test

asmtest: asmtest.c
	gcc -m32 asmtest.c -o asmtest
