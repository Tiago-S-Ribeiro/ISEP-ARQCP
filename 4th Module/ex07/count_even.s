.section .text

	.global count_even	# int
	
count_even:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	pushl %ebx			# guarda o valor de %ebx na stack
	
	movl 8(%ebp), %ecx	# copia o valor inteiro que está 8 bytes à frente do apontado por %ebp para o registo %ecx
	movl 12(%ebp), %edx	# copia o valor inteiro que está 12 bytes à frente do apontado por %ebp para o registo %edx
	movl $0, %eax		# mete o registo %eax igual a 0 pois este vai servir para contar o número de elementos pares contidos no vetor
	
	count:
	
	cmpl $0, %edx		# compara o valor contido em %edx com 0 para saber se já todos os elementos do vetor foram percorridos
	je end				# caso o valor contido em %edx seja igual a 0 salta para end
	
	movw (%ecx), %bx	# copia o valor apomtado por %ecx para o registo %bx
    sarw %bx			# desloca o bit menos significativo contido em %bx para a direita para saber se o número em %bx é par ou impar
    jnc its_even		# caso não haja carray (número em %bx é par) salta para its_even
    addl $2, %ecx		# incrementa o apontador %ecx para passar a apontar para o próximo short do vetor
    decl %edx			# decrementa %edx que contém o número de elementos do vetor
    jmp count			# volta para count para analisar o próximo short do vetor
    
	its_even:
    addl $1, %eax		# caso o número seja par incrementa o contador de números pares do vetor
    addl $2, %ecx		# incrementa o apontador %ecx para passar a apontar para o próximo short do vetor
    decl %edx			# decrementa %edx que contém o número de elementos do vetor
    jmp count			# volta para count para analisar o próximo short do vetor
	
	end:
	popl %ebx			# restaura o valor de %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
