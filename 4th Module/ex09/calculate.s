.section .text

	.global calculate		# int
	.global print_result	# void

calculate:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	subl $8, %esp			# subtrai 8 ao %esp para reservar lugar para duas variaveis locais na stack
	
	pushl %ebx				# guarda o registo %ebx na stack
	pushl %esi				# guarda o registo %esi na stack
	pushl %edi				# guarda o registo %edi na stack
	
	movl 8(%ebp), %ebx		# copia o valor contido na primeira variável (a) para o registo %ebx
	movl 12(%ebp), %esi		# copia o valor contido na segunda variável (b) para o registo %esi
	movl 12(%ebp), %edi		# copia o valor contido na segunda variável (b) para o registo %edi
	addl %ebx, %esi			# adiciona o valor contido em %ebx ao contido em %esi e guarda o resultado da soma em %esi
	movl %esi, -4(%ebp)		# copia o valor da soma para o lugar reservado à primeira variável local da função
	pushl %esi				# passa o valor contido em %esi (valor da soma) por parâmetro pois é necessário para a função print_result
	pushl %edi				# passa o valor contido em %edi (valor de b) por parâmetro pois é necessário para a função print_result
	pushl %ebx				# passa o valor contido em %ebx (valor de a) por parâmetro pois é necessário para a função print_result
	pushl $'+'				# passa o valor do caracter + por parâmetro pois é necessário para a função print_result (indica que foi uma soma)
	call print_result		# chama a função print_result
	addl $16, %esp			# adiciona 16 ao %esp para que a stack pointer volte a apontar para a posição inicial
	
	movl 12(%ebp), %esi		# mete novamente o registo %esi com o valor da segunda variável (b)
	imull %ebx, %edi		# multiplica o valor contido em %ebx pelo contido em %edi e guarda o resultado em %edi
	movl %edi, -8(%ebp)		# copia o valor da multiplicação para o lugar reservado à segunda variável local da função
	pushl %edi				# passa o valor contido em %edi (valor da multiplicação) por parâmetro pois é necessário para a função print_result
	pushl %esi				# passa o valor contido em %esi (valor de b) por parâmetro pois é necessário para a função print_result
	pushl %ebx				# passa o valor contido em %ebx (valor de a) por parâmetro pois é necessário para a função print_result
	pushl $'*'				# passa o valor do caracter * por parâmetro pois é necessário para a função print_result (indica que foi uma multiplicação)
	call print_result		# chama a função print_result
	addl $16, %esp			# adiciona 16 ao %esp para que a stack pointer volte a apontar para a posição inicial
	
	movl -4(%ebp), %eax		# copia o valor guardado na primeira variável local (valor da soma) para o registo %eax
	movl -8(%ebp), %ecx		# copia o valor guardado na segunda variável local (valor da multiplicação) para o registo %ecx
	subl %ecx, %eax			# subtrai o valor contido em %eax ao valor contido em %ecx e guarda o resultado em %eax
	
	end:
	popl %edi				# restaura o valor de %edi
	popl %esi				# restaura o valor de %esi
	popl %ebx				# restaura o valor de %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
