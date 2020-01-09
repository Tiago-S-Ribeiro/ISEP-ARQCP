.section .data
	.global current 					#short
	.global desired 					#short


.section .text
	.global needed_time 				#int

needed_time:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movsxw current, %edx 				# copia o valor de current (16 bits) para o registo %edx (32 bits)
	movsxw desired, %ecx 				# copia o valor de desired (16 bits) para o registo %ecx (32 bits)

	cmpl %edx, %ecx 					# compara o valor contido em %edx com o contido em %ecx
	jg timeForIncreasing 				# caso o valor contido em %edx seja maior que o contido em %ecx salta para timeForIncreasing
	jl timeForDecreasing 				# caso o valor contido em %edx seja maior que o contido em %ecx salta para timeForDecreasing
	je noTemperatureChange 				# caso o valor contido em %edx seja igual ao contido em %ecx salta para noTeperatureChange

	timeForIncreasing:
	subl %edx, %ecx 					# subtrai ao valor da tempratura desejada o valor da temperatura atual e guarda o resultado em %ecx
	movl %ecx, %eax 					# copia a diferença das temperaturas para %eax
	imull $2, %eax 						# multiplica 2 pelo valor contido em %eax para calcular o tempo que leva em minutos a alcançar a temperatura desejada
	imull $60, %eax 					# multiplica 60 pelo valor contido em %eax para calcular o tempo que leva em segundos a alcançar a temperatura desejada
	jmp end 							# salta para end

	timeForDecreasing:
	subl %ecx, %edx 					# subtrai ao valor da tempratura atual o valor da temperatura desejada e guarda o resultado em %edx
	movl %edx, %eax 					# copia a diferença das temperaturas para %eax
	imull $3, %eax 						# multiplica 3 pelo valor contido em %eax para calcular o tempo que leva em minutos a alcançar a temperatura desejada
	imull $60, %eax 					# multiplica 60 pelo valor contido em %eax para calcular o tempo que leva em segundos a alcançar a temperatura desejada
	jmp end 							# salta para end

	noTemperatureChange:
	movl $0, %eax 						# mete %eax igual a 0 pois não há diferença de tempraturas
	jmp end 							# salta para end


	end:

	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
