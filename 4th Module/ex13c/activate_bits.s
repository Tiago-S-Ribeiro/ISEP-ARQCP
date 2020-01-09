.section .text

	.global activate_bits	# int
	
activate_bits:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	pushl %ebx				# guarda o valor de %ebx na stack
	pushl %esi				# guarda o valor de %esi na stack

	movl 8(%ebp), %eax		# copia o valor contido na primeira variável (a) para o registo %eax
	movl 12(%ebp), %esi		# copia o valor contido na segunda variável (left) para o registo %esi
	movl 16(%ebp), %edx		# copia o valor contido na terceira variável (right) para o registo %edx
	movb 16(%ebp), %cl		# copia o valor contido na terceira variável (right) para o registo %cl
	
	addl $1, %esi			# adiciona 1 ao valor contido em %esi pois apenas começa a contar a partir do bit left (excluindo)
	movl $32, %ebx			# mete o registo %ebx igual a 32
	subl %esi, %ebx			# subtrai ao valor contido em %ebx o valor contido em %esi para percorrer todos os bits que se encontram à esquerda de left
	
	go_to_left:
	cmpl $0, %esi			# compara o valor contido em %esi com 0 para verificar se já rodou para a direita todos os bits necessários, para começar a ativar os restantes
	jle one_to_left			# caso o valor contido em %esi seja menor ou igual a 0 salta para one_to_left para começar a ativar os bits restantes
	
	rorl $1, %eax			# roda 1 bit para a direita em %eax
	decl %esi				# decrementa %esi que contém o valor da variável left + 1
	jmp go_to_left			# volta para go_to_left para rodar mais um bit para a direita
	
	one_to_left:
	cmpl $0, %ebx			# compara o valor contido em %ebx com 0 para verificar se já todos os bits do inteiro foram percorridos
	je one_to_right			# caso o valor contido em %ebx seja igual a 0 salta para one_to_right
	
	orl $1, %eax			# faz or entre 1 e o valor do bit menos significativo de %eax para que este fique ativo
	rorl $1, %eax			# roda 1 bit para a direita em %eax
	decl %ebx				# decrementa %ebx que contém o número de bits que irão ficar ativos a partir do bit left
	jmp one_to_left			# volta para one_to_left para ativar o próximo bit
	
	one_to_right:
	cmpl $0, %edx			# compara o valor contido em %edx com 0 para verificar se já todos os bits até ao bit right (excluindo) foram ativados
	jle end					# caso o valor contido em %edx seja menor ou igual a 0 salta para end
	
	orl $1, %eax			# faz or entre 1 e o valor do bit menos significativo de %eax para que este fique ativo
	rorl $1, %eax			# roda 1 bit para a direita em %eax
	decl %edx				# decrementa %edx que contém o valor de right
	jmp one_to_right		# volta para one_to_right para ativar o próximo bit

	end:
	roll %cl, %eax			# roda para a esquerda tantas vezes quantas o valor contido em %cl (valor de right) para voltar ao bit menos significativo inicial de %eax
	
	popl %esi				# restaura o valor de %esi
	popl %ebx				# restaura o valor de %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
