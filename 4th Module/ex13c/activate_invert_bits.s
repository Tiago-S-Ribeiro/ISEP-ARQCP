.section .data

.section .text

	.global activate_invert_bits	# int

activate_invert_bits:

	# prologue
	pushl %ebp
	movl %esp, %ebp
	
	pushl 16(%ebp)					# passa o valor contido em 16(%ebp) (valor de right) por parâmetro pois é necessário para a função activate_bits
	pushl 12(%ebp)					# passa o valor contido em 12(%ebp) (valor de left) por parâmetro pois é necessário para a função activate_bits
	pushl 8(%ebp)					# passa o valor contido em 8(%ebp) (valor de a) por parâmetro pois é necessário para a função activate_bits
	call activate_bits				# chama a função activate_bits
	addl $12, %esp					# adiciona 12 ao %esp para que a stack pointer volte a apontar para a posição inicial
				
	notl %eax						# inverte todos os bits de %eax
		
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
