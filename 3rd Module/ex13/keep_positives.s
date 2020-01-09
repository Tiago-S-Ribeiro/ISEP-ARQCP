.section .data
	.global ptrvec
	.global num
	
.section .text
	.global keep_positives			    #void keep_positives(void)
	
keep_positives:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	pushl %esi
	pushl %ebx
		
#-----------------------------------------------------------------------
	
	movl ptrvec, %esi					#coloca pointer ptrvec em esi
	movl num, %ebx						#coloca num(Qtd elementos) em ebx
	cmpl $0, %ebx						#verifica se num=0 (se vetor nao tem elementos)
	je fim								#se sim, salta para o fim
	movl $0, %eax						#limpa o registo eax
	movl $0, %ecx						#coloca 0 em ecx (vai ser o indice do array)
loop:
	cmpl %ecx, %ebx						#compara qtd elementos com indice
	je fim								#se igual, salta para o fim
	
	movl (%esi), %eax					#coloca o apontado por esi em eax
	cmpl $0, %eax						#compara o valor em eax com 0
	jl negativo							#se for menor que zero, salta para 'negativo'
	
	incl %ecx							#se nao, incrementa o indice
	addl $4, %esi					    #avança para o proximo inteiro do array
	jmp loop							#salta para o loop
	
negativo:
	movl %ecx, (%esi)					#coloca o indice no apontado por esi, substituindo o valor pelo seu indice no array
	incl %ecx							#incrementa o indice
	addl $4, %esi						#avança para o proximo inteiro do array
	jmp loop							#salta para o loop

#-----------------------------------------------------------------------
fim:

	popl %ebx
	popl %esi
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
