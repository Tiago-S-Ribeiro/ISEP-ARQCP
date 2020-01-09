.section .data

	v1: 
	.int 0						# declaração da variável v1
	
	v2: 
	.int 0						# declaração da variável v2
	
	v3: 
	.int 0						# declaração da variável v3
	
	.global v1					# int
	.global v2					# int
	.global v3					# int
	.global ptrvec				# int*
	.global num					# int
	
.section .text

	.global count_seq			# int
	.global generate_sequence	# void
	.global verify_condition	# int
	
count_seq:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx					# guarda o registo %ebx na stack
	
	movl $0, %ebx				# mete %ebx igual a 0 pois este registo vai guardar o número de conjuntos de três números consecutivos que existem no array
	movl ptrvec, %ecx			# copia o valor de ptrvec para o registo %ecx
	movl num, %edx				# copia o valor de num para o registo %edx
	subl $2, %edx				# subtrai 2 ao valor contido em %edx pois existem, num - 2, conjuntos de três números
	
	check:
	
	cmpl $0, %edx				# compara o valor contido em %edx com 0 para verificar se já todos os conjuntos de três números contidos no array foram percorridos
	jle end						# caso o valor contido em %edx seja menor ou igual a 0 salta para end (menor pois o vetor pode ter um ou zero elementos e ao fazer a subtração de 2 ao valor de %edx vai dar um número negativo)
	
	movl %ecx, ptrvec			# copia o valor contido em %ecx (muda com incremento) para ptrvec pois é um parâmetro requirido para a função generate_sequence
	pushl %ecx					# guarda o registo %ecx na stack para garantir que depois da função generate_sequence ser chamada o valor de %ecx não é alterado nesta função
	pushl %edx					# guarda o registo %edx na stack para garantir que depois da função generate_sequence ser chamada o valor de %edx não é alterado nesta função
	call generate_sequence		# chama a função generate_sequence
	popl %edx					# restaura o valor de %edx
	popl %ecx					# restaura o valor de %ecx
	
	pushl %ecx					# guarda o registo %ecx na stack para garantir que depois da função generate_sequence ser chamada o valor de %ecx não é alterado nesta função
	pushl %edx					# guarda o registo %edx na stack para garantir que depois da função generate_sequence ser chamada o valor de %edx não é alterado nesta função
	call verify_condition		# chama a função verify_condition
	popl %edx					# restaura o valor de %edx
	popl %ecx					# restaura o valor de %ecx
	
	cmpl $1, %eax				# compara o valor contido em %eax (retorno da função verify_condition) com 1 (1 - indica que os 3 números são consecutivos)
	je add_to_counter			# caso o valor contido em %eax seja igual a 1 salta para add_to_counter
	addl $4, %ecx				# caso contrário incrementa o apontador %ecx
	decl %edx					# decrementa %edx que contém o número de conjuntos de três números contidos no array
	jmp check					# volta para check para verificar o próximo conjunto de três números
	
	add_to_counter:
	addl $1, %ebx				# incrementa o contador %ebx
	addl $4, %ecx				# caso contrário incrementa o apontador %ecx
	decl %edx					# decrementa %edx que contém o número de conjuntos de três números contidos no array
	jmp check					# volta para check para verificar o próximo conjunto de três números
	
	end:
	movl %ebx, %eax				# copia o valor contido em %ebx para %eax pois este é o registo de retorno da função
	popl %ebx					# restaura o valor de %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
	
generate_sequence:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx					# guarda o registo %ebx na stack
	
	movl ptrvec, %ecx			# copia o valor de ptrvec para $ecx
	
	movl (%ecx), %ebx			# copia o valor apontado por %ecx para o registo %ebx
	movl 4(%ecx), %eax			# copia o valor contido 4 bytes à frente do valor apontado por %ecx para o registo %eax
	movl 8(%ecx), %edx			# copia o valor contido 8 bytes à frente do valor apontado por %ecx para o registo %edx
	movl %ebx, v1				# copia o valor contido em %ebx para v1 
	movl %eax, v2				# copia o valor contido em %eax para v2
	movl %edx, v3				# copia o valor contido em %edx para v3
	
	popl %ebx					# restaura o valor de %ebx
	movl %ebp, %esp
	popl %ebp        
	ret

verify_condition:
	
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx					# guarda o registo %ebx na stack
	pushl %esi					# guarda o registo %esi na stack
	pushl %edi					# guarda o registo %edi na stack

	movl $0, %eax				# mete o registo %eax igual a 0 pois este é o registo de retorno da função que retorna 0, caso os 3 números não sejam consecutivos e retorna 1 caso os números sejam consecutivos
	movl v1, %edx				# copia o valor de v1 para o registo %edx
	movl v2, %ecx				# copia o valor de v2 para o registo %ecx
	movl v3, %ebx				# copia o valor de v3 para o registo %ebx
	
	subl $1, %ecx				# subtrai 1 ao valor contido em %ecx para tentar igualá-lo ao valor contido em %edx no caso de serem números consecutivos
	subl $2, %ebx				# subtrai 2 ao valor contido em %ebx para tentar igualá-lo ao valor contido em %edx no caso de v3 ser igual a v1 + 2
	
	condition:
	
	cmpl %edx, %ecx				# compara o valor contido em %edx com o contido em %ecx para se verificar se são números consecutivos
	je first_is_true			# caso sejam números consecutivos salta para first_is_true
	jmp end_verify_condition	# caso contrário salta para end_verify_condition
	
	first_is_true:
	
	cmpl %edx, %ebx				# compara o valor contido em %edx com o contido em %ebx para se verificar os três números são consecutivos
	je second_is_true			# caso os três números sejam consecutivos salta para second_is_true
	jmp end_verify_condition	# caso contrário salta para end_verify_condition
	
	second_is_true:
	
	movl $1, %eax				# mete %eax igual a 1 o que indica que o conjunto dos três números passados por parâmetro são consecutivos

	end_verify_condition:
	popl %edi					# restaura o valor de %edi
	popl %esi					# restaura o valor de %esi
	popl %ebx					# restaura o valor de %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
