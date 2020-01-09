.section .data

	.global ptrvec			# short int*
	.global x				# short int
	.global num				# int
	
.section .text

	.global exists			# int
	.global vec_diff		# int
	
exists:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx				# guarda o registo %ebx na stack
	pushl %esi				# guarda o registo %esi na stack
	
	movl $0, %eax			# mete %eax igual a 0 pois é o registo de retorno que vai retornar 0 caso x não tenha duplicados no vetor, ou 1 caso tenha
	movl $0, %esi			# mete %esi igual a 0 pois este vai ser o contador que regista quantas vezes x aparece no vetor
	movl ptrvec, %edx		# copia o valor de ptrvec para o registo %edx
	movl num, %ecx			# copia o valor de num para o registo %ecx
	movw x, %bx				# copia o valor de x para o registo %bx
	
	checks:
	
	cmpl $2, %esi			# compra %esi com 2 pois basta que x apareça duas vezes no vetor para considerarmos que existem duplicados
	je has_duplicates		# caso %esi seja igual a 2 salta para has_duplicates
	
	cmpl $0, %ecx			# compara %ecx com 0 para saber se o vetor já foi todo percorrido
	je end					# caso %ecx seja igual a 0 salta para end
	
	cmpw (%edx), %bx		# compara o valor apontado por %edx com o valor contido em %bx
	jne next_short			# caso o valor apontado por %edx não seja igual ao contido em %bx salta para next_short
	addl $1, %esi			# caso contrário incrementa o contador %esi
	
	next_short:
	addl $2, %edx			# adiciona 2 ao apontador %edx para o incrementar e assim passar a apontar para o próximo short do vertor
	decl %ecx				# decrementa %ecx que contem o número de elementos do vetor
	jmp checks				# volta para checks para verififcar o pŕoximo short
	
	has_duplicates:
	movl $1, %eax			# mete %eax igual a 1 no caso de haverem duplicados de x no vetor
	
	end:
	# epilogue
	popl %esi				# restaura o valor do registo %esi
	popl %ebx				# restaura o valor do registo %ebx
	movl %ebp, %esp
	popl %ebp
	ret
	
vec_diff:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx				# guarda o registo %ebx na stack
	
	movl $0, %ebx			# mete %ebx igual a 0 pois este vai servir para contar quantos elementos no vetor não têm duplicados
	movl ptrvec, %edx		# copia o valor de ptrvec para o registo %edx
	movl num, %ecx			# copia o valor de num para o registo %ecx
	
	checks_elements:
	
	cmpl $0, %ecx			# compara %ecx com 0 para saber se o vetor já foi todo percorrido
	je end_vec_diff			# caso %ecx seja igual a 0 salta para end_vec_diff
	
	movw (%edx), %ax		# copia o valor apontado por %edx para %ax
	movw %ax, x				# copia o valor contido em %ax para x pois x é um parâmetro da função (exists) que é chamada em baixo
	pushl %edx				# guarda o registo %edx na stack pois ptrvec é um valor que tem de ser passado por parâmetro ao chamar a função exists mas como não há certezas que o valor de %edx se mantenha depois da função ser chamada guarda-se o registo na stack
	pushl %ecx				# guarda o registo %ecx na stack pois num é um valor que tem de ser passado por parâmetro ao chamar a função exists mas como não há certezas que o valor de %ecx se mantenha depois da função ser chamada guarda-se o registo na stack
	call exists				# chama a função exists
	popl %ecx				# restaura o valor de %ecx
	popl %edx				# restaura o valor de %edx
	
	cmpl $0, %eax			# compara %eax com 0 para saber se há duplicados ou não de x no vetor
	je no_duplicates_sum	# caso %eax seja igual a 0 salta para no_duplicates_sum
	addl $2, %edx			# adiciona 2 ao apontador %edx para o incrementar e este passar a apontar para o pŕoximo short contido no vetor
	decl %ecx				# decrementa %ecx que contém o número de elementos do vetor
	jmp checks_elements		# volta para check_elements para verificar duplicações do próximo short
	
	no_duplicates_sum:
	addl $1, %ebx			# incrementa o contador %ebx quando há duplicados de um determinado short num vetor
	addl $2, %edx			# adiciona 2 ao apontador %edx para o incrementar e este passar a apontar para o pŕoximo short contido no vetor
	decl %ecx				# decrementa %ecx que contém o número de elementos do vetor
	jmp checks_elements		# volta para check_elements para verificar duplicações do próximo short
	
	end_vec_diff:
	movl %ebx, %eax			# copia o valor contido em %ebx para %eax pois este é o registo de retorno da função
	# epilogue
	popl %ebx				# restaura o valor do registo %ebx
	movl %ebp, %esp
	popl %ebp
	ret
