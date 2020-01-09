.section .data

	.global even			# int
	.global num				# int
	.global ptrvec			# int*
	
.section .text

	.global test_even		# int
	.global vec_sum_even	# int
	
test_even:

	pushl %ebp
	movl %esp, %ebp
	
	movl $0, %edx			# mete o registo %edx (que fica com o resto da divisão) igual a 0 para não dar floating point exception
	movl even, %eax			# copia o valor de even para o registo %eax
	movl $2, %ecx			# mete o registo %ecx igual a 2
	idivl %ecx				# divide o valor contido em %eax por 2 e guarda o resultado em %eax e resto em %edx
	
	cmpl $0, %edx			# compara %edx com 0 para verificar se o número contido em even é par
	je even_number			# caso %edx seja igual a 0 salta para even_number
	jmp odd_number			# caso %edx seja diferente de 0 salta para odd_number
	
	even_number:
	movl $1, %eax			# mete o registo %eax igual a 1
	jmp end					# salta para end
	
	odd_number:
	movl $0, %eax			# mete o registo %eax igual a 0
	jmp end					# salta para end
	
	end:
	movl %ebp, %esp
	popl %ebp
	ret

vec_sum_even:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx				# guarda o registo %ebx na stack
	
	movl $0, %ebx			# mete o registo %eax igual a 0 pois é onde vai ser guardada a soma dos números pares do vetor
	movl ptrvec, %ecx		# copia o valor de ptrvec para o registo %ecx
	movl num, %edx			# copia o valor de num para o registo %edx
	
	check_number:
	
	cmpl $0, %edx			# compara %edx a 0 para saber quando já percorreu todos os valores do vetor
	je end_vec_sum			# caso %edx seja igual a 0 salta para end_vec_sum
	
	movl (%ecx), %eax		# copia o vaor apontado por %ecx (= inteiro apontado por ptrvec) para o registo %eax
	movl %eax, even			# copia o valor contido em %eax para a variável global even
	
	pushl %ecx				# guarda o registo %ecx na stack antes de fazer a chamada da função test_even pois não há certezas de que os valores dos registos se mantenham depois da função ser chamada
	pushl %edx				# guarda o registo %edx na stack antes de fazer a chamada da função test_even pois não há certezas de que os valores dos registos se mantenham depois da função ser chamada
	call test_even			# chama a função test_even para testar se um número (testa todos os apontados por ptrvec) é par ou impar
	popl %edx				# restaura o valor de %edx
	popl %ecx				# restaura o valor de %ecx
	
	cmpl $1, %eax			# compara %eax a 1 para ver se o número é par ou impar
	je sum_even				# caso o número seja par salta para sum_even
	
	decl %edx				# decrementa o valor contido em %edx
	addl $4, %ecx			# adiciona 4 a %ecx (incrementa o apontador em 4 bytes (32 bits)) para passar a apontar para o próximo inteiro do vetor
	jmp check_number		# salta para check_number para verificar o próximo inteiro
	
	sum_even: 
	addl (%ecx), %ebx		# adiciona o valor apontado por %ecx ao valor contido em %ebx
	decl %edx				# decrementa o valor contido em %edx
	addl $4, %ecx			# adiciona 4 a %ecx (incrementa o apontador em 4 bytes (32 bits)) para passar a apontar para o próximo inteiro do vetor
	jmp check_number		# salta para check_number para verificar o próximo inteiro
	
	end_vec_sum:
	movl %ebx, %eax			# copia o resultado da soma contido em %ebx para %eax pois é o registo do retorno
	#epilogue
	popl %ebx				# restaura o valor de %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
