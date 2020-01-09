.section .data
	
.section .text

	.global join_bits		#int join_bits(int a, int b, int pos)
	
join_bits:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	pushl %ebx
	#pushl %esi
	#pushl %edi
#-----------------------------------------------------------------------

	movl 8(%ebp), %ebx		#move o 1º parâmetro da função para ecx
	movl 12(%ebp), %edx		#move o 2º parâmetro da função para ecx
	movb 16(%ebp), %cl		#move o 3º parâmetro da função para ecx
	movl $1, %eax			#coloca 1 em eax (máscara)
		
	sal %cl, %eax			#shift do numero POS 1 bit para a esquerda
	subl $1, %eax			#retira 1 à mascara (ficar com 0s à esquerda de 'pos' e 1s à direita)
	sal $1, %eax			#shift aritmético 1 bit para a esquerda
	addl $1, %eax			#adiciona 1 à mascara
		
	andl %eax, %ebx			#mascara AND 'a', guarda os bits de 'a' de 0 a (pos)
	notl %eax				#nega a mascara
	andl %eax, %edx			#mascara AND 'b', guarda os bits desde (pos+1) a 32
	orl %ebx, %edx			#junta os 2 conjuntos de bits

	movl %edx, %eax			#coloca o resultado em eax (registo de retorno)

#-----------------------------------------------------------------------
fim:
	#popl %edi
	#popl %esi
	popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
