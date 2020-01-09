.section .data
	.global op1 					#int
	.global op2 					#int

.section .text
	.global test_flags  			#char

test_flags:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx 						# guarda o registo %ebx na stack

	movl op1, %ecx 					# copia o valor de op1 para o registo %ecx
	movl op2, %eax 					# copia o valor de op2 para o registo %eax

	addl %ecx, %eax 				# adiciona o valor contido em %ecx ao contido em %eax e guarda o resultado em %eax

	jc returnIfCarry 				# verifica se a operação de soma anterior ativa uma flag carry e se ativar salta para returnIfCarry
	jo returnIfOverFlow 			# verifica se a operação de soma anterior ativa uma flag overflow e se ativar salta para returnIfOverflow
	movl $0, %eax 					# caso não ative nenhuma das flags ateriormente mencionadas mete o registo %eax igual a 0
	jmp end 						# salta para end

	returnIfCarry:
	movl $1, %eax 					# mete o registo %eax igual a 1
	jmp end 						# salta para end

	returnIfOverFlow:
	movl $1, %eax 					# mete o registo %eax igual a 1
	jmp end 						# salta para end

	end:
	
	# epilogue
	popl %ebx 						# restaura o valor de #ebx
	movl %ebp, %esp
	popl %ebp
	ret
