.section .text

	.global greater_date	# unsigned int

greater_date:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl 8(%ebp), %ecx		# copia o valor contido na primeira variável (date1) para o registo %ecx
	movl 12(%ebp), %edx		# copia o valor contido na primeira variável (date2) para o registo %edx
	
	rorl $8, %ecx			# roda 8 bits de %ecx para a direita
	rorl $8, %edx			# roda 8 bits de %edx para a direita
	
	cmpw %cx, %dx			# compara o valor contido em %cx com o contido em %dx para saber qual das duas datas tem um ano maior
	jg second_is_greater	# caso o valor contido em %dx seja maior que o contido em %cx salta para second_is_greater
	jl first_is_greater		# caso o valor contido em %cx seja maior que o contido em %dx salta para first_is_greater
	
	rorl $8, %ecx			# roda 8 bits de %ecx para a direita
	rorl $8, %edx			# roda 8 bits de %edx para a direita
	
	cmpb %ch, %dh			# compara o valor contido em %ch com o contido em %dh para saber qual das duas datas tem um mês maior
	jg second_is_greater	# caso o valor contido em %dh seja maior que o contido em %ch salta para second_is_greater
	jl first_is_greater		# caso o valor contido em %ch seja maior que o contido em %dh salta para first_is_greater
	
	rorl $8, %ecx			# roda 8 bits de %ecx para a direita
	rorl $8, %edx			# roda 8 bits de %edx para a direita
	
	cmpb %ch, %dh			# compara o valor contido em %ch com o contido em %dh para saber qual das duas datas tem um mês maior
	jg second_is_greater	# caso o valor contido em %dh seja maior que o contido em %ch salta para second_is_greater
	jl first_is_greater		# caso o valor contido em %ch seja maior que o contido em %dh salta para first_is_greater
	
	second_is_greater:
	movl 12(%ebp), %eax		# se a segunda data for a maior das duas datas, copia o valor de date2 para o registo %eax que é o registo de retorno da função
	jmp end					# salta para end
	
	first_is_greater:
	movl 8(%ebp), %eax		# se a primeira data for a maior das duas datas, copia o valor de date1 para o registo %eax que é o registo de retorno da função
	jmp end					# salta para end

	end:
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
