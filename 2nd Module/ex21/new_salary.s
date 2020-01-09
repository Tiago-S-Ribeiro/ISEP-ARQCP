.section .data

	.global code 						# int
	.global currentSalary 				# int

.section .text

	.global new_salary 					# int

new_salary:
	
	# prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx 							# guarda o registo %ebx na stack

	movl currentSalary, %eax 			# copia o valor de currentSalary para o registo %eax
	movl code, %ebx 					# copia o valor de code para o registo %ebx

	cmpl $10, %ebx 						# compara o valor contido em %ebx com 10
	je code_10 							# caso o valor contido em %ebx seja igual a 10 salta para code_10
	
	cmpl $11, %ebx 						# compara o valor contido em %ebx com 11
	je code_11 							# caso o valor contido em %ebx seja igual a 11 salta para code_11
	
	cmpl $12, %ebx 						# compara o valor contido em %ebx com 12
	je code_12 							# caso o valor contido em %ebx seja igual a 12 salta para code_12
	
	addl $100, %eax 					# caso o código não seja nenhum dos anteriores, soma 100 ao valor contido em %eax onde o resultado da soma fica guardado
	jmp end 							# salta para end

	code_10:
	addl $300, %eax 					# soma 300 ao valor contido em %eax onde o resultado da soma fica guardado
	jmp end 							# salta para end

	code_11:
	addl $250, %eax 					# soma 250 ao valor contido em %eax onde o resultado da soma fica guardado
	jmp end 							# salta para end

	code_12:
	addl $150, %eax 					# soma 150 ao valor contido em %eax onde o resultado da soma fica guardado
	jmp end 							# salta para end

	end:

	# epilogue
	popl %ebx 							# restaura o valor de %ebx
	movl %ebp, %esp
	popl %ebp

	ret
