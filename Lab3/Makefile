all: dodawanie odejmowanie ieee

dodawanie: dodawanie.o
	ld dodawanie.o -o dodawanie -m elf_i386
dodawanie.o: dodawanie.s
	as --gstabs dodawanie.s -o dodawanie.o --32

odejmowanie: odejmowanie.o
	ld odejmowanie.o -o odejmowanie -m elf_i386
odejmowanie.o: odejmowanie.s
	as --gstabs odejmowanie.s -o odejmowanie.o --32

ieee: ieee.o
	ld ieee.o -o ieee -m elf_i386

ieee.o: ieee.s
	as --gstabs ieee.s -o ieee.o --32
