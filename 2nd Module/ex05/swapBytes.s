.section .data
	.global s						# short

.section .text
	.global swapBytes 				# short


swapBytes:
	#prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx						# guarda o registo %ebx na stack

	movw s, %bx 					# copia o valor de s para o registo %bx (16 bits)
	movb %bl, %ah    				# copia o valor contido em %bl para o registo %ah (8 bits)
	movb %bh, %al    				# copia o valor contido em %bh para o registo %al (8 bits)
	
	# epilogue
	popl %ebx 						# restaura o valor de %ebx
	movl %ebp, %esp
	popl %ebp
	ret
