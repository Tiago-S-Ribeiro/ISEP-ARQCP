.section .text

	.global inc_and_square	#int
	
inc_and_square:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl 8(%ebp), %ecx		# copia o valor inteiro que está 8 bytes à frente do apontado por %ebp para o registo %ecx
	movl 12(%ebp), %edx		# copia o valor inteiro que está 12 bytes à frente do apontado por %ebp para o registo %edx
	movl 12(%ebp), %eax		# copia o valor inteiro que está 12 bytes à frente do apontado por %ebp para o registo %eax
	
	addl $1, (%ecx)			# adiciona 1 ao valor apontado por %ecx
	mull %edx				# multiplica o valor contido em %edx por ele mesmo e guarda o resultado em %eax
	
	end:
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
