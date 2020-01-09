.section .data
	
.section .text
	.global test_equal			#test_equal(char *a, char *b)
	
test_equal:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	pushl %ebx
	pushl %esi
	#pushl %edi
#-----------------------------------------------------------------------

	movl 8(%ebp), %edx			#move o 1º parâmetro da função para edx
	movl 12(%ebp), %esi			#move o 2º parâmetro da função para esi
	movl $1, %eax				#coloca 1 em eax (strings iguais por definição)
	
loop:	
	movb (%edx), %bl			#coloca o primeiro carater em ebx
	movb (%esi), %cl			#coloca o segundo carater em esi
	
	cmpb $0, %bl				#verifica se o carater é 0 (se acabou a string edx)
	je checkLength				#salta para checkLength para ver se a primeira string já acabou
	
	cmpb %bl, %cl				#compara ambos os carateres
	jne notEqual				#se forem diferentes, salta para notEqual
	addl $1, %edx				#senão, avança para o próximo carater da string em edx
	addl $1, %esi				#avança para o próximo carater da string em esi
	jmp loop					#salta para a próxima iteração do loop
	
notEqual:
	movl $0, %eax				#coloca 0 em eax (strings diferentes)
	jmp fim						#termina o programa

checkLength:
								#se a primeira string acabou, verifica se a segunda também acabou
	cmpb $0, %cl				#verifica se o carater é 0 (se é fim da string esi)
	jne notEqual				#se for diferente, salta para notEqual
	jmp fim						#termina o programa 
	
#-----------------------------------------------------------------------
fim:
	#popl %edi
	popl %esi
	popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
