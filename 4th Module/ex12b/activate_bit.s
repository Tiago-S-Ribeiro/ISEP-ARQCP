.section .data
	
.section .text
	.global activate_bit			#int activate_bit(int *ptr, int pos)
	
activate_bit:
	#prologue
	pushl %ebp 			
	movl %esp, %ebp 
				
	pushl %ebx
	pushl %edi
	pushl %esi
#-----------------------------------------------------------------------
		
	movl 8(%ebp), %esi				#move o 1º parâmetro da função para esi
	movb 12(%ebp), %cl				#move o 2º parâmetro da função para cl
									
	rorl %cl, (%esi)				#faz 'pos' rotações para a direita ao número
	movl (%esi), %ebx	    		#move o apontado por esi para ebx para verificar o bit menos significativo
	orl $1, (%esi)			        #faz OR booleano entre o apontado por esi e 1 para alterar o bit menos significativo
	roll %cl, (%esi)				#faz 'pos' rotações para a esquerda ao número, para restaurar os bits rodados, às suas posições
									
	andl $1, %ebx					#faz AND booleano de ebx com 1 para garantir a alteração do OR anterior
	cmpl $0, %ebx					#compara o bit menos significativo com 0
	je bitAlterado					#se for igual a 0, salta para bitAlterado
	movl $0, %eax					#senão, o bit já era 1, logo, retorna 0
	jmp fim							#termina o programa
									
bitAlterado:		
	movl $1, %eax					#coloca 1 em eax
	jmp fim							#termina o programa

#-----------------------------------------------------------------------
fim:
	popl %esi
	popl %edi
	popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
