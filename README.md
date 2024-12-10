# assembly programs

## Lab 1
`writeText.s` is a program, that prints single word (max 5 characters) inputted from console. It uses SYSREAD and SYSREAD functions.
`compareText.s` compares two texts. First is declared in data, second is inputted from console. Program returns message if texts are the same or not.

## Lab 2
`dodawanie.s` adds two 128-bit numbers including transfer. Program uses loops to add big nums partially.
`odejmowanie.s` subtract two 128-but numbers in common way as adding.

## Lab 3
`ieee.s` displays exceptions in IEEE-754 standard. You have to set float values to generate exceptions.

## Lab 4
Testing if inline assembly speeds up arithmetic operations in C.
`asmprogram.c` program for tests with inline assembly.
`cprogram.c` program for tests without inline assemly.
Result in `wyniki.txt` and report in pdf file.

# Lab 5
Testing if XMM registers speed up arithmetic operations in C.
`asmprogram.c` program for tests with inline assembly and XMM registers
`cprogram.c` program for tests without assembly and without loop.
`lcprogram.c` program for tests without assembly, but it uses loops to add 4 pairs of numbers.
Result in `lab5Wyniki.txt` and report in pdf file.
