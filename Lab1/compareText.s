STDIN = 0
STDOUT = 1
SYSWRITE = 4
SYSREAD = 3
SYSEXIT = 1
EXIT_SUCCESS = 0

.text
	msg: .ascii "Write text (5): \n "
	msg_len = . - msg
	
	word: .ascii "siema"
	word_len = . - word

	msg2: .ascii "Texts are the same \n"
	msg2_len = . - msg2

	msg3: .ascii "Texts are different \n"
	msg3_len = . - msg3
.data
	buf: .ascii "     "
	buf_len = . - buf

.global _start

_start:
        mov $SYSWRITE, %eax
        mov $STDOUT, %ebx
        mov $msg, %ecx
        mov $msg_len, %edx
        int $0x80

        mov $SYSREAD, %eax
        mov $STDIN, %ebx
        mov $buf, %ecx
        mov $buf_len, %edx
        int $0x80

	mov $0, %ecx  #zerowanie rejestru, który będzie licznikiem
	mov $word, %edx # przypisanie adresu początku słowa word
	mov $buf, %ebp #przypisanie adresu początku  słowa buf

loop:
	movb (%edx, %ecx, 1), %al
	movb (%ebp, %ecx, 1), %bl
	cmp %al, %bl
	jne false
	inc %ecx
	cmp $word_len, %ecx
	jne loop
	jmp true

false:
        mov $SYSWRITE, %eax
        mov $STDOUT, %ebx
        mov $msg3, %ecx
        mov $msg3_len, %edx
        int $0x80
	jmp end

true:
	mov $SYSWRITE, %eax
        mov $STDOUT, %ebx
        mov $msg2, %ecx
        mov $msg2_len, %edx
        int $0x80
	jmp end

end:
	mov $SYSEXIT, %eax
	mov $EXIT_SUCCESS, %ebx
	int $0x80

