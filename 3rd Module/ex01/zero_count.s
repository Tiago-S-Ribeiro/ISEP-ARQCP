.section .data
	.global ptr1
.section .text
	.global zero_count		#int zero_count(void)
	
zero_count:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	pushl %ebx
#-----------------------------------------------------------------------
	movl ptr1, %ecx    		#colocar o endereço de ptr1 em ecx
	movl $0, %eax	    	#limpar o registo eax (começa em 0)

comparator:
	movb (%ecx), %bl   	    #mover o carater apontado por ecx para bl(1 byte)
	cmpb $'0', %bl	    	#comparar o carater com zero
	je contador   			#se bl for zero, salta para contador		
	cmpb $0, %bl	    	#verifica se é o final da string 
	je fim					#se sim, salta para o fim
	
caraterIncrement:
	incl %ecx		    	#avança para o próximo carater
	jmp comparator  		#salta de novo para o ciclo
	
contador:
	incl %eax        		#incrementa o resultado final (quantidade zeros)
	jmp caraterIncrement  	#salta para comparatorLoop para continuar o ciclo
#-----------------------------------------------------------------------
fim:
	#epilogue
	popl %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
