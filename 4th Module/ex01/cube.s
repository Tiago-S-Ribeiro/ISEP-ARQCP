.section .text

	.global cube		# int
	
cube:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl 8(%ebp), %ecx	# copia o valor da primeira variavel apontada por %ebp para o registo %ecx
	movl 8(%ebp), %eax	# copia o valor da primeira variavel apontada por %ebp para o registo %eax
	mull %ecx			# multiplica o valor guardado em %ecx pelo guardado %eax e guarda o resultado em %eax
	mull %ecx			# multiplica o valor guardado em %ecx pelo guardado %eax e guarda o resultado em %eax
	
	end:
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
