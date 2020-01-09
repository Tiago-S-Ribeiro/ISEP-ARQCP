.section .data

	.global ptr1			# char*
	
.section .text

	.global encrypt			# int
	
encrypt:

	pushl %ebp
	movl %esp, %ebp
	
	movl $0, %eax			# inicia o contador (%eax) a 0
	movl ptr1, %edx			# copia o valor de ptr1 para o registo %edx
	
	start:
	movb (%edx), %cl		# copia o valor apontado por %edx (um caracter de str1) para %cl
	
	cmpb $'a', %cl			# compara o valor contido em %cl com a letra a
	je a_space_occurence	# se o valor contido em %cl for igual a, a, salta para a_space_occurence
	
	cmpb $' ', %cl			# compara o valor contido em %cl com um espaço
	je a_space_occurence	# se o valor contido em %cl for igual a um espaço salta para a_space_occurence
	
	cmpb $0, %cl			# compara o valor contido em %cl com 0
	je end					# se o valor contido em %cl for igual a 0, salta para end
	
	addl $1, %eax			# incrementa 1 ao valor contido em %eax
	addl $2, (%edx)			# adiciona 2 ao caracter apontado por %edx
	addl $1, %edx			# incrementa o apontador %edx
	jmp start				# chama novamente start para verificar o próximo caracter contido na string
	
	a_space_occurence:
	add $1, %edx			# incrementa o apontador %edx
	jmp start				# chama novamente start para verificar o próximo caracter contido na string
	
	end:
	movl %ebp, %esp
	popl %ebp
	ret
