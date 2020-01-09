.section .data

	x: 
	.int 0							# declaração da variável x (usada na fução exists_in_array)
	
	num_elements_ptrdest:
	.int 0							# declaração da variável num_elements_ptrdest (usada na fução exists_in_array)
	
	.global num_elements_ptrdest	# int
	.global x						# int
	.global ptrsrc					# int*
	.global ptrdest					# int*
	.global num						# int
	
.section .text

	.global sort_without_reps		# int
	.global sort_array				# void
	.global exists_in_array			# int
	
sort_without_reps:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx						# guarda o registo %ebx na stack
	pushl %esi						# guarda o registo %esi na stack
	pushl %edi						# guarda o registo %edi na stack
	
	movl $0, %edi					# mete o registo %edi igual a 0 pois este vai servir para guardar o número de elementos que foram passados do array de origem para o de destino
	movl num, %esi					# copia o valor de num para o registo %esi
	
	cmpl $0, %esi					# compara %esi com 0 para saber se o array é vazio
	je end							# se o array for vazio salta para end
	
	call sort_array					# caso contrário chama a função sort_array para ordenar o array de origem
	
	movl ptrsrc, %ecx				# copia o valor de ptrsrc para o registo %ecx
	movl ptrdest, %edx				# copia o valor de ptrdest para o registo %edx
	
	movl (%ecx), %ebx				# copia o valor apontado por %ecx para %ebx
	movl %ebx, (%edx)				# copia o valor contido em %ebx para o endereço apontado por %edx
	decl %esi						# decrementa %esi que contém o número de elementos do array de origem
	addl $1, %edi					# incrementa %edi que guarda o número de elementos que são passados para o array de destino
	addl $4, %ecx					# incrementa %ecx para passar a apontar para o próximo inteiro contido no array
	addl $4, %edx					# incrementa %edx para passar a apontar para a pŕoxima posição do array de destino
	
	next_int:
	cmpl $0, %esi					# compara %esi com 0 para saber se o array de origem já foi todo percorrido
	je end							# se %esi for igual a 0 salta para end
	
	movl (%ecx), %ebx				# copia o valor apontado por %ecx para o registo %ebx
	movl %ebx, x					# copia o valor contido em %ebx para x pois a função exists_in_array requer este parâmetro para saber qual o inteiro a avaliar
	movl %edi, num_elements_ptrdest	# copia o valor contido em %edi para num_elements_ptrdest pois a função exists_in_array requer este parâmetro para saber qual o número de elementos que já foram passados para o array de destino
	pushl %edx						# guarda %edx na stack antes de chamar a função exists_in_array para garantir que o valor de %edx não é alterado após a chamada da função
	pushl %ecx						# guarda %ecx na stack antes de chamar a função exists_in_array para garantir que o valor de %ecx não é alterado após a chamada da função
	call exists_in_array			# chama a função exists_in_array
	popl %ecx						# restaura o valor de %ecx
	popl %edx						# restaura o valor de %edx
	
	cmpl $1, %eax					# compara o restorno da função exists_in_array (que fica guardado em %eax) com 1 (se for igual a 1 significa que o inteiro já existia no array)
	je increment_and_next			# caso %eax seja igual a 1 (inteiro já existe no array) salta para increment_and_next
	movl (%ecx), %ebx				# caso contrário copia o valor apontado por %ecx para o registo %ebx
	movl %ebx, (%edx)				# copia o valor contido em %ebx para o endereço apontado por %edx
	decl %esi						# decrementa %esi que contém o número de elementos do array de origem
	addl $1, %edi					# incrementa %edi que guarda o número de elementos que são passados para o array de destino
	addl $4, %ecx					# incrementa %ecx para passar a apontar para o próximo inteiro contido no array
	addl $4, %edx					# incrementa %edx para passar a apontar para a pŕoxima posição do array de destino
	jmp next_int					# volta para next_int para verificar se passa ou não o próximo interiro do array de origem para o array de destino
	
	increment_and_next:
	decl %esi						# decrementa %esi que contém o número de elementos do array de origem
	addl $4, %ecx					# incrementa %ecx para passar a apontar para o próximo inteiro contido no array
	jmp next_int					# volta para next_int para verificar se passa ou não o próximo interiro do array de origem para o array de destino
	
	end:
	movl %edi, %eax					# copia o valor contido em %edi para %eax pois este é o registo do retorno da função
	popl %edi						# restaura o valor do registo %edi
	popl %esi						# restaura o valor do registo %esi
	popl %ebx						# restaura o valor do registo %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
	
sort_array:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx						# guarda o registo %ebx na stack
	pushl %esi						# guarda o registo %esi na stack
	pushl %edi						# guarda o registo %edi na stack
	
	movl ptrsrc, %ecx				# copia o valor de ptrsrc para o registo %ecx
	movl ptrsrc, %edx				# copia o valor de ptrsrc para o registo %edx
	movl num, %edi					# copia o valor de num para o registo %edi
	movl num, %eax					# copia o valor de num para o registo %eax
	jmp sort						# salta para sort para começar a verificar para o primeiro elemento do array se este é maior ou menor que os outros elementos contidos no array
	
	decrease_num_elements:
	addl $4, %ecx					# incrementa %ecx para este registo passar a apontar para o inteiro que agora vai ser comparado com os outros inteiros que estão à sua frente no array de forma a ordenar esse array
	movl %ecx, %edx					# copia o valor contido em %ecx para %edx para só serem comparados os números inteiros a partir do inteiro para o qual %ecx agora aponta
	decl %edi						# decrementa %edi que contém o número de elementos do array
	cmpl $0, %edi					# compara %edi com 0 para verificar se todos os elementos do array já foram percorridos
	je end_sort_array				# caso %edi seja igual a 0 salta para end_sort_array
	movl %edi, %eax					# caso contrário copia o valor contido em %edi para %eax para decrementar o número de elemetos do array que agora vão ser comparados com o inteiro apontado por %ecx
	
	sort:
	cmpl $0, %eax					# compara %eax com 0 para saber se o array já foi todo percorrido
	je decrease_num_elements		# caso %eax seja igual a 0 salta para decrease_num_elements 
	
	movl (%ecx), %ebx				# caso contrário copia o valor apontado por %ecx para %ebx
	movl (%edx), %esi				# copia o valor apontado por %edx para %esi
	cmpl %ebx, %esi					# compara o valor contido em %ebx com o contido em %esi
	jl swap_ints					# caso %esi seja menor que %ebx salta para swap_ints
	decl %eax						# decrementa %eax que contém o número de elementos do array
	addl $4, %edx					# incrementa %edx para passar para o pŕoximo inteiro contido no array
	jmp sort						# volta para sort para comparar um inteiro para o qual %ecx está a apontar com outro elemento do array para o qual %edx passa agora a apontar
	
	swap_ints:
	movl %ebx, (%edx)				# copia o valor contido em %ebx para o endereço apontado por %edx pondo assim o inteiro maior à frente do inteiro menor no array
	movl %esi, (%ecx)				# copia o valor contido em %esi para o endereço apontado por %ecx pondo assim o inteiro menor atrás do inteiro maior no array
	decl %eax						# decrementa %eax que contém o número de elementos do array
	addl $4, %edx					# incrementa %edx para passar para o pŕoximo inteiro contido no array
	jmp sort						# volta para sort para comparar um inteiro para o qual %ecx está a apontar com outro elemento do array para o qual %edx passa agora a apontar
	
	end_sort_array:
	popl %edi						# restaura o valor do registo %edi
	popl %esi						# restaura o valor do registo %esi
	popl %ebx						# restaura o valor do registo %ebx
	movl %ebp, %esp
	popl %ebp        
	ret

exists_in_array:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx						# guarda o registo %ebx na stack
	pushl %esi						# guarda o registo %esi na stack
	
	movl $0, %eax					# mete o registo %eax igual a 0 pois este é o registo de retorno que retorna 0 se x não existir no array ou 1 se x já existe no array
	movl x, %ecx					# copia o valor de x (inteiro que pode ou não já existir no array) para o registo %ecx
	movl num_elements_ptrdest, %edx	# copia o valor de num_elements_ptrdest (número de elementos que o array de destino contém) para o registo %edx
	movl ptrdest, %ebx				# copia o valor de ptrdest para o registo %ebx
	
	check:
	
	cmpl $0, %edx					# compara %edx com 0 para saber se todos os elementos que foram inseridos no array de destino foram percorridos
	je end_exists_in_array			# caso %edx seja igual a 0 salta para end_exists_in_array
	
	movl (%ebx), %esi				# copia o valor apontado por %ebx para o registo %esi
	cmpl %ecx, %esi					# compara %ecx (x) com %esi
	je x_exists						# se os registos forem iguais salta para x_exists
	addl $4, %ebx					# caso contrário incrementa %ebx para passar a apontar para o próximo inteiro contido no array
	decl %edx						# decrementa %edx que contém o número de elementos do array de destino
	jmp check						# volta para check para comparar x com o próximo inteiro para o qual %ebx está agora a apontar
	
	x_exists:
	movl $1, %eax					# mete %eax igual a 1 pois o valor de x já existe no array de destino
	jmp end_exists_in_array			# salta para end_exists_in_array
	
	end_exists_in_array:
	popl %esi						# restaura o valor do registo %esi
	popl %ebx						# restaura o valor do registo %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
