.section .data
	.global ptr1
	
.section .text
	.global decrypt			    #int decrypt(void)
	
decrypt:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
			
#-----------------------------------------------------------------------

	movl $0, %eax				#limpa o registo de retorno eax
	movl $0, %ecx				#limpa o registo ecx
	movl ptr1, %edx				#coloca ptr1 em edx
	
loop:
	movb (%edx), %cl			#coloca apontado por edx em cl (8bits)
	cmpb $0, %cl				#verifica se o carater é 0 (se é fim da string)
	je fim						#se sim, salta para o fim
	
	cmpb $'a', %cl				#compara 'a' ao carater em cl
	je incremento				#se for igual, salta para o incremento
	
	cmpb $' ', %cl				#compara ' ' ao carater em cl
	je incremento				#se for igual, salta para o incremento
	
	subl $2, (%edx)				#subtrai 2 ao apontado por edx (faz o contrario da funcao encrypt)
	incl %eax					#incrementa o contador de carateres alterados
	
incremento:
	incl %edx					#incrementa edx (avanca para o proximo carater)
	jmp loop					#salta para o loop
	
#-----------------------------------------------------------------------
fim:
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
