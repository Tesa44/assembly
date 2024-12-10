.code32
SYSEXIT = 1
EXIT_SUCCESS = 0

.data
liczba1:
	.long 0x275af57a, 0x298a5c79, 0x2757fba6, 0x3567bb6a
liczba2:
	.long 0x7536a63b, 0x1575a5f4, 0x47457ba3, 0x1459aa43
wynik:
	.long 0, 0, 0, 0, 0
len = 4

.text

.global _start
_start:
	movl $liczba1, %esi
	movl $liczba2, %edi
	movl $len, %ecx
	movl $0, %ebx
	movl $0, %edx
	
petla:
	movl (%esi), %eax
	subl %edx, %eax	#Odejmij przeniesienie z poprzedniej iteracji
	subl (%edi), %eax 	#Odejmij fragmenty liczby
	setc %dl

	pushl %eax
	movl %eax, wynik(,%ebx,4)
	add $1, %ebx
	
	add $4, %esi
	add $4, %edi

	loop petla

	addl $0, %edx    #sprawdzmy czy jest przeniesienie
	jz koniec
	
	movl $wynik, %esi
	movl (%esi), %eax
	movl $0, %ebx
	movl $0xffffffff, %edx
	subl %eax, %edx
	addl $1, %edx
	movl %edx, wynik
	pushl %edx
	movl $len, %ecx
	sub $1, %ecx

petla2:
	add $1, %ebx
	add $4, %esi
	movl $0xffffffff, %edx
	movl (%esi), %eax
	subl %eax, %edx
	pushl %edx
	movl %edx, wynik(,%ebx,4)

	loop petla2

	movl $0xffffffff, wynik(,%ebx,4) 	#jako komunikat wyniku -

koniec:
	mov $SYSEXIT, %eax
	mov $EXIT_SUCCESS, %ebx
	int $0x80
