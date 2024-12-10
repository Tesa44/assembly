all: dodawanie odejmowanie

dodawanie: dodawanie.o
	ld dodawanie.o -o dodawanie -m elf_i386
dodawanie.o: dodawanie.s
	as --gstabs dodawanie.s -o dodawanie.o --32

odejmowanie: odejmowanie.o
	ld odejmowanie.o -o odejmowanie -m elf_i386
odejmowanie.o: odejmowanie.s
	as --gstabs odejmowanie.s -o odejmowanie.o --32
