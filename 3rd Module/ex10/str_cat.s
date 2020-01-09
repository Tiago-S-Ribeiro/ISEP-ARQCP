.section .data

	.global ptr1		# char*
	.global ptr2		# char*
	.global ptr3		# char*
	
.section .text

	.global str_cat		# void
	
str_cat:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx			# guarda o registo %ebx na stack
	
	movl ptr1, %ecx		# copia o valor contido em ptr1 para o registo %ecx
	movl ptr2, %edx		# copia o valor contido em ptr2 para o registo %edx
	movl ptr3, %eax		# copia o valor contido em ptr3 para o registo %eax
	
	copy_str1:
	
	movb (%ecx), %bl	# copia o valor apontado por %ecx para o registo %bl
	movb %bl, (%eax)	# copia o valor contido em %bl para o byte apontado por %eax
	
	cmpb $0, %bl		# compara o valor contido em %bl com 0
	je copy_str2		# se %bl for igual a 0 salta para copy_str2
	
	addl $1, %ecx		# incrementa o apontador %ecx
	addl $1, %eax		# incrementa o apontador %eax
	jmp copy_str1		# volta para copy_str1 para copiar o pŕoximo caracter apontado por ptr1
	
	copy_str2:
	
	movb (%edx), %bh	# copia o valor apontado por %edx para o registo %bh
	movb %bh, (%eax)	# copia o valor contido em %bh para o byte apontado por %eax
	
	cmpb $0, %bh		# compara o valor contido em %bh com 0
	je end				# se %bh for igual a 0 salta para end
	
	addl $1, %edx		# incrementa o apontador %edx
	addl $1, %eax		# incrementa o apontador %eax
	jmp copy_str2		# volta para copy_str2 para copiar o pŕoximo caracter apontado por ptr2
	
	end:
	popl %ebx			# restaura o valor do registo %ebx
	movl %ebp, %esp
	popl %ebp
	ret
