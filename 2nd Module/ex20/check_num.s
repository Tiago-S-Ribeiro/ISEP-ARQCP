.section .data
	.global num

.section .text
	.global check_num       #char check_num(void)

check_num:	
	
	#prologue
	pushl %ebp
	movl %esp, %ebp
	push %ebx
	#----------------------------------------------------------------------------
	
	movl $0, %edx			#colocar 0 em edx (ou dá floating point exception)
	movl num, %eax      	#coloca num em eax
	movl $2, %ebx			#coloca 2 em ebx
	
	idivl %ebx				#divide eax por ebx (resto fica em edx)
	cmpl $0, %edx			#compara 0 com edx (resto da divisao anterior)
	je 	numeroPar 			#se resto = 0, é par, salta para numeroPar
	jmp numeroImpar			#salta para numeroImpar
	
	#----------------------------------------------------------------------------

numeroPar:
	movl num, %eax			#coloca num em eax	(duvida para tirar com o professor, pois falha em 2 testes na ausencia deste comando)
	cmpl $0, %eax			#compara 0 com eax (num)
	jge numeroParPositivo	#se num >= 0, salta para numeroParPositivo
	jmp numeroParNegativo   #se num <  0, salta para numeroParNegativo

numeroParPositivo:

	movl $3, %eax			#coloca 3 em eax
	jmp fim					#salta para o fim

numeroParNegativo:

	movl $1, %eax			#coloca 1 em eax
	jmp fim					#salta para o fim

#-----------------------------------------------------------------------
numeroImpar:

	movl num, %eax				#coloca num em eax (mesma duvida acima referida)
	cmpl $0, %eax				#compara 0 com eax (num)
	jge numeroImparPositivo		#se num >= 0, salta para numeroImparPositivo
	jl numeroImparNegativo		#se num <  0, salta para numeroImparNegativo

numeroImparPositivo:

	movl $4, %eax				#coloca 4 em eax
	jmp fim						#salta para o fim

numeroImparNegativo:

	movl $2, %eax				#coloca 2 em eax
	jmp fim						#salta para o fim

fim:
	#-------------------------------------------------------------------
	#epilogue
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
