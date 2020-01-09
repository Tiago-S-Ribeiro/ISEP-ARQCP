.section .data

	.global ptr1			# char*
	.global ptr2			# char*
	
.section .text

	.global str_copy_porto	# void
	
str_copy_porto:

	# Prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl ptr1, %edx			# copia o valor de ptr1 para o registo %edx
	movl ptr2, %ecx			# copia o valor de ptr2 para o registo %ecx
	
	start:
	movb (%edx), %al		# copia o valor do (primeiro caracter) apontado por %edx, ou seja, o apontado por ptr1 para %al (8 bites)
	movb %al, (%ecx)		# copia o valor contido em %al para o apontado por %ecx, ou seja, para o apontado por ptr2
	
	cmpb $0, %al			# compara o valor contido em %al com 0
	je end					# se %al for igual a 0, salta para end
	
	cmpb $'v', %al			# compara o valor contido em %al com v
	je v_occurence			# se %al for igual a v, salta para v_occurence

	jmp next_character		# salta para next_character se nenhum dos casos anteriores se verificar
	
	v_occurence:
	movb $'b', (%ecx)		# se houver uma ocorrência de v, mete b no bite para o qual %ecx está a apontar
	jmp next_character		# salta para next_character
	
	next_character:
	addl $1, %edx			# incrementa %edx para que o próximo caracter seja analisado
	addl $1, %ecx			# incrementa %ecx
	jmp start				# salta para start
	
	end:
	# Epilogue
	movl %ebp, %esp
	popl %ebp
	ret
