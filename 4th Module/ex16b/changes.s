.section .data

.section .text

.global changes				#void changes(int *ptr)

changes:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	pushl %ebx
	#pushl %esi
	#pushl %edi
#-----------------------------------------------------------------------		
	
	movl 8(%ebp), %edx		#move o 1º parâmetro da função para edx
	movl (%edx), %eax		#coloca o valor de edx, em eax
	movb $20, %cl			#valor do numero de bits a deslocar (2 primeiros bytes e metade menos significativa do 3º)	

	shrl %cl, %eax			#shift 20 bits à direita da cópia do valor de ebx
	andl $15, %eax			#máscara AND eax: coloca todos os bits a 0 exceto os ultimos 4
		
	cmpl $7, %eax			#verifica se os 4 bits mais significativos do 3ºbyte>7
	jg inverterBits			#se sim, salta para inverterBits
	jmp fim					#se não, termina o programa

inverterBits:
	movl $1, %ebx			#coloca 1 em ebx (máscara)
	cmpb $24, %cl			#verifica se o loop chegou ao fim
	je fim					#se sim, termina o programa

	shll %cl, %ebx			#deslocacao de 'cl' bits à esquerda de ebx
	xorl %ebx, (%edx)		#XOR deteta os bits diferentes e inverte-os
	incb %cl				#incrementa cl (o bit a ser lido)
	jmp inverterBits		#salta para a próxima iteração
	
#-----------------------------------------------------------------------

fim:
	#popl %edi
	#popl %esi
	popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
