.section .text

	.global greatest		#int
	
greatest:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	pushl %ebx				# guarda o registo %ebx na stack
	
	movl 8(%ebp), %ecx		# copia o valor inteiro que está 8 bytes à frente do apontado por %ebp para o registo %ecx
	movl 12(%ebp), %edx		# copia o valor inteiro que está 12 bytes à frente do apontado por %ebp para o registo %edx
	movl 16(%ebp), %ebx		# copia o valor inteiro que está 16 bytes à frente do apontado por %ebp para o registo %ebx
	
	cmpl %ecx, %edx			# compara o valor guardado em %ecx com o guardado em %edx
	jg second_comparation	# caso o valor guardado em %edx seja maior salta para second_comparation
	jmp not_greater			# caso o valor guardado em %ecx seja maior salta para not_greater
	
	second_comparation:
	cmpl %edx, %ebx			# compara o valor guardado em %edx com o guardado em %ebx
	jg third_is_greater		# caso o valor guardado em %ebx seja maior salta para third_is_greater pois o terceiro número é o maior dos três números recebidos por parâmetro
	jmp second_is_greater	# caso o valor guardado em %edx seja maior salta para second_is_greater pois o segundo número é o maior dos três números recebidos por parâmetro
	
	third_is_greater:
	movl %ebx, %eax			# copia o valor contido em %ebx para o registo %eax pois este é o registo de retorno da função
	jmp end					# salta para end
	
	second_is_greater:
	movl %edx, %eax			# copia o valor contido em %edx para o registo %eax pois este é o registo de retorno da função
	jmp end					# salta para end
	
	not_greater:
	cmpl %ecx, %ebx			# compara o valor contido em %ecx com o contido em %ebx
	jg third_is_greater		# caso o valor guardado em %ebx seja maior salta para third_is_greater pois o terceiro número é o maior dos três números recebidos por parâmetro
	jmp first_is_greater	# caso o valor guardado em %ebx seja maior salta para first_is_greater pois o primeiro número é o maior dos três números recebidos por parâmetro
	
	first_is_greater:
	movl %ecx, %eax			# copia o valor contido em %ecx para o registo %eax pois este é o registo de retorno da função
	jmp end					# salta para end
	
	end:
	popl %ebx				# restaura o valor de %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
