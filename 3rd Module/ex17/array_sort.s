.section .data
	.global ptrvec
	.global num
	
.section .text
	.global array_sort			    #void array_sort(void)

#-----------------------------------------------------------------------
array_sort:
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx			
	pushl %esi						
	pushl %edi						

	movl ptrvec, %ecx				# coloca pointer ptrvec em ecx
	movl ptrvec, %edx				# coloca pointer ptrvec em edx 
	movl num, %edi					# copia o valor de num para o registo %edi
	movl num, %eax					# copia o valor de num para o registo %eax
	cmpl $0, %edi					# compara 0 com edi(num)
	je fim							# se for 0, salta para o fim
	jmp sort						# salta para sort


decrementar_elementos:
	addl $4, %ecx					# incrementa ecx para este registo passar a apontar para o inteiro que agora vai ser comparado com os outros inteiros que estão à sua frente no array de forma a ordenar esse array
	movl %ecx, %edx					# copia o valor contido em ecx para edx para só serem comparados os números inteiros a partir do inteiro para o qual ecx agora aponta
	decl %edi						# decrementa edi que contém o número de elementos do array
	cmpl $0, %edi					# compara edi com 0 para verificar se todos os elementos do array já foram percorridos
	je fim							# salta para fim se edi = 0
	movl %edi, %eax

sort:
	cmpl $0, %eax					# compara eax com 0 para saber se o array já foi todo percorrido
	je decrementar_elementos		# salta para decrementar_elementos se eax = 0

	movl (%ecx), %ebx				# copia o valor apontado por ecx para ebx
	movl (%edx), %esi				# copia o valor apontado por edx para esi
	cmpl %ebx, %esi					# compara o valor contido em ebx com o de esi
	jg trocar_nums					# caso esi seja menor que ebx salta para trocar_nums
	decl %eax						# decrementa eax que contém o número de elementos do array
	addl $4, %edx					# incrementa edx para passar para o pŕoximo inteiro contido no array
	jmp sort						# salta para sort

trocar_nums:
	movl %ebx, (%edx)				# copia o valor contido em ebx para o endereço apontado por edx pondo assim o inteiro maior à frente do inteiro menor no array
	movl %esi, (%ecx)				# copia o valor contido em esi para o endereço apontado por ecx pondo assim o inteiro menor atrás do inteiro maior no array
	decl %eax						# decrementa eax que contém o número de elementos do array
	addl $4, %edx					# incrementa edx para passar para o pŕoximo inteiro contido no array
	jmp sort						# salta para sort
#-----------------------------------------------------------------------
fim:
	popl %edi
	popl %esi
	popl %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
