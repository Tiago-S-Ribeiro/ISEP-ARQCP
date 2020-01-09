.section .data
	.global ptrvec			# int*
	.global num				# int

.section .text
	.global vec_add_one		# void

vec_add_one:


	#prologue
	pushl %ebp
	movl %esp, %ebp

	movl ptrvec, %edx		# copia o valor de ptrvec para o registo %edx
	movl num, %ecx			# copia o valor de num para o registo %ecx

	add_one:
		cmpl $0, %ecx 		# verifica se o vetor chegou ao fim
		je end				# salta para end se o vetor tiver chegado ao fim
		
		addl $1, (%edx)  	# adiciona 1 ao valor apontado por %edx
		decl %ecx		 	# decrementa o número de elementos do vetor
		addl $4, %edx		# incrementa o apontador para passar para o próximo inteiro (4 bytes)
		jmp add_one			# volta a chamar add_one

	end:
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
