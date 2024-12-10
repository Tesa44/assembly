.code32
SYSEXIT = 1
EXIT_SUCCESS = 0

.data
liczba1: 
	.long 0x10304008, 0x701100ff, 0x45100020, 0x48570030
liczba2:
	.long 0xf040500c, 0x00220026, 0xd21000cb, 0xe4520032
wynik:
	.long 0, 0, 0, 0, 0
len = 4

.text

.global _start

_start:
	mov $liczba1, %esi
	mov $liczba2, %edi
	mov $len, %ecx
	mov $0, %ebx
	mov $0, %edx

petla:
	movl (%esi), %eax
	addl %edx, %eax 	#Dodaj przeniesienie
	addl (%edi), %eax	#dodaj fragmenty liczby
	setc %dl		#zapisz przeniesienie na kolejna iteracje
	pushl %eax

	movl %eax, wynik(,%ebx,4) 	#zapisz wynik w pamieci od dolu
	add $1, %ebx

	addl $4, %esi		#przesun adresy na kolejne 4 bajty
	addl $4, %edi		# czyli na kolejny fragment liczby

	loop petla

	pushl %edx
	movl %edx, wynik(,%ebx,4)	#zapisz ostatnie przeniesienie

	mov $SYSEXIT, %eax
	mov $EXIT_SUCCESS, %ebx
	int $0x80
