.section .text

	.global add_byte		# void

add_byte:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	pushl %ebx				# guarda o registo %ebx na stack
	pushl %esi				# guarda o registo %esi na stack
	
	movb 8(%ebp), %al		# copia o valor contido na primeira variável (x) para o registo %al
	movl 12(%ebp), %ecx		# copia o valor contido na segunda variável (vec1) para o registo %ecx
	movl 16(%ebp), %edx		# copia o valor contido na terceira variável (vec2) para o registo %edx
	
	movl (%ecx), %ebx		# copia o valor apontado por %ecx para o registo %ebx
	movl %ebx, (%edx)		# copia o valor contido em %ebx para o endereço para o qual %edx aponta
	
	movl (%ecx), %esi		# copia o valor apontado por %ecx para o registo %esi para guardar o número de elementos do vetor
	
	addl $4, %ecx			# incrementa %ecx para este passar a apontar para o próximo elemento do vetor
	addl $4, %edx			# incrementa %edx para este passar a apontar para o próximo elemento do vetor
	
	add_bytes:
	
	cmpl $0, %esi			# compara o valor contido em %esi com 0 para verificar se todos os elementos do vetor vec1 foram percorridos
	jle end					# caso o valor contido em %esi seja menor ou igual a 0 salta para end
	
	movl (%ecx), %ebx		# copia o valor apontado por %ecx para o registo %ebx
	addb %al, %bl			# adiciona ao primeiro byte de %ebx (%bl) o valor contido em %al e guarda o resultado em %bl
	movl %ebx, (%edx)		# copia o valor contido em %ebx para o endereço para o qual %edx aponta
	addl $4, %ecx			# incrementa %ecx para este passar a apontar para o próximo elemento do vetor
	addl $4, %edx			# incrementa %edx para este passar a apontar para o próximo elemento do vetor
	decl %esi				# decrementa %esi que contém o número de elementos do vetor vec1
	jmp add_bytes			# volta para add_bytes para adicionar %al ao primeiro byte do próximo elemento do vetor

	end:
	popl %esi				# restaura o valor de %esi
	popl %ebx				# restaura o valor de %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
