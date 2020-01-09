.section .data
	.global height						#int
	.global base    					#int

.section .text
	.global getArea  					#int

getArea:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	movl height, %ecx 					# copia o valor da altura do triângulo para %ecx
	movl base, %eax   					# copia o valor da base do triângulo para %eax

	mull %ecx							# multiplica a base pela altura e guarda o valor em %eax

	movl $2, %ecx 						# muda o valor de %exc para 2

	divl %ecx   						# divide o resultado da multiplicação anterior que está em %eax por 2 e guarda esse resultado novamente em %eax

	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
