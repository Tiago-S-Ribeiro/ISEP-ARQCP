.section .data

	.global A 							# int
	.global B 							# int
	.global C 							# int
	.global D 							# int
	
.section .text

	.global compute 					# int
	
compute:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl A, %ecx 						# copia A para %ecx
	movl B, %eax 						# copia B para %eax
	imull %ecx, %eax 					# faz a multiplicação de dois inteiros com sinal e guarda o valor em %eax
	
	addl C, %eax 						# soma C ao valor que está guardado em %eax e guarda esse valor novamente em %eax
	cdq 								# estende o sinal para %edx
	
	movl D, %ecx 						# muda o valor de %ecx para o valor de D
	cmpl $0, %ecx 						# compara o valor que está em %ecx com 0
	je divisorZero 						# salta para divisorZero se %ecx for igual a 0
	idivl %ecx 							# divide, caso %ecx seja diferente de 0, o valor que está contido em %edx : %eax pelo contido em %ecx e guarda o resultado em %edx : %eax
	jmp end 							# salta para end
	
	divisorZero:
	movl $0, %eax 						# mete %eax igual 0
	jmp end 							# salta para end

	end:

	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
