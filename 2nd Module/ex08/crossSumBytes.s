.section .data

s1:
	.short 0xFAA						# declaração de s1
s2:
	.short 0x111						# declaração de s2
	
	.global s1
	.global s2

.section .text

	.global crossSumBytes				# short

crossSumBytes:
	
	# Prologue
	pushl %ebp 
	movl %esp, %ebp
	push %ebx 							# guarda o registo %ebx na stack

	movw s1, %ax						# copia o valor de s1 para o registo %ax (16 bits)
	movw s2, %bx						# copia o valor de s2 para o registo %bx (16 bits)
	addb %bh, %al 						# adiciona o valor contido em %bh ao contido em %al e guarda o resultado em %al
	addb %bl, %ah						# adiciona o valor contido em %bl ao contido em %ah e guarda o resultado em %ah


	# Epilogue
	popl %ebx							# restaura o valor de %ebx
	movl %ebp, %esp
	popl %ebp


	ret
