.section .data

	.global ptrvec		# short int*
	.global num			# int
	
.section .text

	.global vec_zero	# int
	
vec_zero:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl $0, %eax		# mete o registo %eax igual a 0 pois %eax é o contador que retorna o número de elementos do vetor mudados
	movl ptrvec, %ecx	# copia o valor de ptrvec no registo %ecx
	movl num, %edx		# copia o valor de num no registo %edx
	
	check_short:
	
	cmpl $0, %edx		# compara %edx a 0
	je end				# se %edx for igual a 0 salta para end
	
	cmpw $100, (%ecx)	# compara 100 ao valor apontado por %ecx
	jge put_to_zero		# caso o valor apontado por %ecx seja igual ou maior que 100 salta para put_to_zero
	addl $2, %ecx		# adiciona 2 a %ecx para incrementar o apontador
	decl %edx			# decrementa %edx (número de elementos do vetor)
	jmp check_short		# volta para check_short para verificar o próximo short int inserido no vetor
	
	put_to_zero:
	
	movw $0, (%ecx)		# muda o valor apontado por %ecx para 0
	addl $2, %ecx		# adiciona 2 a %ecx para incrementar o apontador
	decl %edx			# decrementa %edx (número de elementos do vetor)
	addl $1, %eax		# incrementa o contador pois mais um elemento do vetor foi mudado
	jmp check_short		# volta para check_short para verificar o próximo short int inserido no vetor
	
	end:
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
