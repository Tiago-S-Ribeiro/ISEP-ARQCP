.section .data

	.global ptr1		# char*
	.global ptr2		# char*
	.global num			# int
	
.section .text

	.global swap		# void
	
swap:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx			# guarda o registo %ebx na stack
	
	movl ptr1, %ecx		# copia o valor de ptr1 para o registo %ecx
	movl ptr2, %edx		# copia o valor de ptr2 para o registo %edx
	movl num, %eax		# copia o valor de num para o registo %eax
	
	copy:
	
	cmpl $0, %eax		# compara o registo %eax com 0 para saber se os vetores já foram percorridos na totalidade
	je end				# caso %eax seja igual a 0 salta para end
	
	movb (%ecx), %bl	# copia o valor apontado por %ecx para o registo %bl
	movb (%edx), %bh	# copia o valor apontado por %edx para o registo %bh
	movb %bl, (%edx)	# troca o bite que estava contido no primeiro vetor para a sua posição equivalente no segundo vetor
	movb %bh, (%ecx)	# troca o bite que estava contido no segundo vetor para a sua posição equivalente no primeiro vetor
	decl %eax			# decrementa %eax que contém o número de elementos dos vetores
	incl %ecx			# incrementa %ecx para passar para o pŕoximo bite contido no vetor
	incl %edx			# incrementa %edx para passar para o pŕoximo bite contido no vetor
	jmp copy			# volta para copy para os próximos bites
	
	end:
	#epilogue
	popl %ebx			# restaura o valor do registo %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
