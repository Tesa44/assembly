all: writeText compareText 

writeText: writeText.o
	ld writeText.o -o writeText

wirteText.o: writeText.s
	as writeText.s -o writeText.o

compareText: compareText.o
	ld compareText.o -o compareText

compareText.o: compareText.s
	as compareText.s -o compareText.o
