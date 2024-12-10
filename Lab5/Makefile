all: cprogram asmprogram lcprogram

cprogram: cprogram.c
	gcc -m32 cprogram.c -o cprogram

asmprogram: asmprogram.c
	gcc -mmmx -msse2 -m32 asmprogram.c -o asmprogram

lcprogram: lcprogram.c
	gcc -m32 lcprogram.c -o lcprogram
