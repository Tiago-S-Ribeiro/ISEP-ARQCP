.section .data

	.global ptrgrades		# char*
	.global num				# int
	.global ptrfreq			# int*
	
.section .text

	.global frequencies		# void
	
frequencies:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx				# guarda o registo %ebx na stack
	pushl %esi				# guarda o registo %esi na stack
	pushl %edi				# guarda o registo %edi na stack
	
	movl ptrgrades, %esi	# copia o valor de ptrgrades para o registo %esi
	movl num, %ecx			# copia o valor de num para o registo %ecx
	movl ptrfreq, %edx		# copia o valor de ptrfreq para o registo %edx 
	movl ptrfreq, %edi		# copia o valor de ptrfreq para o registo %edi
	movl $21, %ebx			# mete %ebx igual a 21 pois este é o registo que vai guardar o número de elementos do array de frequências
	
	zero_for_all_freq:
	
	cmpl $0, %ebx			# compara o valor contido em %ebx com 0 para verificar se todos os elementos do array de frequências já foram percorridos
	je count_frequencies	# caso o valor contido em %ebx seja igual a 0 salta para count_frequencies
	
	movl $0, (%edx)			# caso contrário mete o valor apontado por %edx igual a 0
	addl $4, %edx			# incrementa o apontador %edx para passar para o pŕoximo elemento do array
	decl %ebx				# decrementa %ebx que contém o número de elementos do array de frequências
	jmp zero_for_all_freq	# volta para zero_for_all_freq para meter o próximo elemento do array igual a 0
	
	count_frequencies:
	
	cmpl $0, %ecx			# compara o valor contido em %ecx com 0 para verificar se já todos os elementos do array de notas foram percorridos
	je end					# caso o valor contido em %ecx seja igual a 0 salta para end
	
	movl %edi, %edx			# copia o valor contido em %edi para %edx para que %edx volte a apontar para o primeiro elemento do array de frequências
	movb (%esi), %al		# copia o valor apontado por %esi para o registo %al
	
	search_freq:
	
	cmpb $0, %al			# compara o valor contido em %al com 0 para para verificar se %edx já está a apontar para o elemento certo a incrementar do array
	je increment			# caso o valor contido em %al seja igual a 0 salta para increment
	addl $4, %edx			# caso contrário incrementa o apontador %edx (neste loop vai ser incrementado tantas vezes quantas o valor contido em %al)
	decb %al				# decrementa %al que contém uma nota
	jmp search_freq			# volta para search_freq para verificar se o próximo elemento do array de frequências corresponde à frequência em questão a ser incrementada
	
	increment:
	
	addl $1, (%edx)			# incrementa o valor apontado por %edx
	addl $1, %esi			# incrementa o apontador %esi para passar para a próxima nota do array
	decl %ecx				# decrementa %ecx que contém o número de elementos do array de notas
	jmp count_frequencies	# volta para count_frequencies para incrementar a frequência da próxima nota
	
	end:
	popl %edi				# restaura o valor de %edi
	popl %esi				# restaura o valor de %esi
	popl %ebx				# restaura o valor de %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
