.section .data

	.global num1						#int
	.global num2    					#int
	
result:
	.int 0

.section .text
	.global sum 						#int
	.global subtraction		    		#int
	.global multiplication				#int	
	.global division					#int	
	.global modulus						#int
	.global powerOfTwo					#int
	.global powerOfThree				#int

sum:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl num1, %eax 					# copia o valor de num1 para o registo %eax
	movl num2, %ecx 					# copia o valor de num2 para o registo %ecx
	addl %ecx, %eax 					# adiciona o valor contido em %ecx ao contido em %eax e guarda o resultado em %eax
	movl %eax, result 					# copia o valor contido em %eax para result
	
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret

subtraction:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl num1, %eax 					# copia o valor de num1 para o registo %eax
	movl num2, %ecx 					# copia o valor de num2 para o registo %ecx
	subl %ecx, %eax 					# subtrai ao valor contido em %eax, o valor contido em %ecx e guarda o resultado em %eax 
	movl %eax, result 					# copia o valor contido em %eax para result
	
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret


multiplication:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl num1, %eax 					# copia o valor de num1 para o registo %eax
	movl num2, %ecx 					# copia o valor de num2 para o registo %ecx
	imull %ecx 							# multiplica %ecx por %eax e guarda o resultado em %eax
	movl %eax, result 					# copia o valor contido em %eax para result
	
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret

division:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl num1, %eax 					# copia o valor de num1 para o registo %eax
	movl num2, %ecx 					# copia o valor de num2 para o registo %ecx
	cmpl $0, %ecx 						# compara o valor que está em %ecx com 0
	je divisorZero 						# Se %ecx for igual a 0 então salta para divisorZero
	movl $0, %edx 						# mete o registo %edx igual a 0, %edx tem de ser iniciado para estender o sinal do inteiro que fica em %eax
	idivl %ecx 							# divide %eax por %ecx e guarda o resultado em %eax
	movl %eax, result 					# copia o valor contido em %eax para result
	jmp end 							# salta para end
	
	divisorZero:
	movl $0, %eax 						# mete %eax igual 0
	jmp end 							# salta para end

	end:
	
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret


modulus:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl num1, %eax 					# copia o valor de num1 para o registo %eax
	movl num2, %ecx 					# copia o valor de num2 para o registo %ecx
	cmpl $0, %ecx 						# compara o valor que está em %ecx com 0
	je divisor0 						# Se %ecx for igual a 0 então salta para divisor0
	movl $0, %edx 						# mete o registo %edx igual a 0, %edx tem de ser iniciado para estender o sinal do inteiro que fica em %eax
	idivl %ecx 							# divide %eax por %ecx e guarda o resultado em %eax
	movl %edx, %eax 					# o resto da divisão que está contido em %edx é copiado para %eax
	movl %eax, result 					# o valor contido em %eax é copiado para result
	jmp epilogue 						# salta para epilogue
	
	divisor0:
	movl $0, %eax 						# mete %eax igual 0
	jmp epilogue 						# salta para epilogue

	epilogue:
	
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret

powerOfTwo:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl num1, %eax 					# copia o valor de num1 para o registo %eax
	movl num1, %ecx 					# copia o valor de num1 para o registo %ecx
	mull %ecx 							# multiplica o valor contido em %ecx pelo contido em %eax e guarda o resultado em %eax
	movl %eax, result 					# copia o valor contido em %eax para result
	
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret

powerOfThree:

	#prologue
	pushl %ebp
	movl %esp, %ebp

	movl num1, %eax 					# copia o valor de num1 para o registo %eax
	movl num1, %ecx 					# copia o valor de num1 para o registo %ecx
	mull %ecx 							# multiplica o valor contido em %ecx pelo contido em %eax e guarda o resultado em %eax
	mull %ecx 							# volta a multiplicar o valor contido em %ecx pelo contido em %eax (resultado da operação anterior) e guarda o resultado em %eax
	movl %eax, result 					# copia o valor contido em %eax para result
	
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
