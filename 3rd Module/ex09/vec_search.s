.section .data
	.global ptrvec
	.global num
	.global x
	
.section .text
	.global vec_search			    #short* vec_search(void)
	
vec_search:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	pushl %esi
	pushl %edi
	pushl %ebx
			
#-----------------------------------------------------------------------
	movl num, %eax					#move num(Qtd de elementos) para eax
	cmpl $0, %eax					#verifica se num = 0 (se array tem 0 elementos)
	je numNaoExiste					#se sim, salta para numNaoExiste

	movl $0, %eax					#limpar o registo eax
	movl ptrvec, %esi				#move o pointer ptrvec para esi
	movl num, %edi					#move num para edi
	movw x, %bx						#move o elemento suposto encontrar para bx
	
loop:
	movw (%esi), %cx				#move 'apontado por' esi para cx
	cmpw %bx, %cx					#verifica se o valor em cx é o elemento desejado
	je numExiste					#se for, salta para numExiste
	
	cmpl $0, %edi					#verifica se edi = 0 (edi vai ser decrementado a cada iteração)
	je numNaoExiste					#se for, salta para numNaoExiste
	
	decl %edi						#decrementa edi
	addl $2, %esi					#avanca para o proximo short no array (2bytes)
	jmp loop						#salta para loop
	
numNaoExiste:
	movl $0, %eax					#coloca 0 em eax (numero nao foi encontrado)
	jmp fim							#salta para o fim
	
numExiste:	
	movl %esi, %eax					#move o apontador para eax (registo de return)

#-----------------------------------------------------------------------
fim:

	#epilogue
	popl %ebx
	popl %edi
	popl %esi
	movl %ebp, %esp
	popl %ebp        
	ret
