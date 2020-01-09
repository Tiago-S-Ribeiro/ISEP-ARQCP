.section .data
	.global ptrvec
	.global num
	
.section .text
	.global vec_greater20			    #short* vec_greater20(void)
	
vec_greater20:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	pushl %ebx		
#-----------------------------------------------------------------------
	
	movl ptrvec, %ecx					#coloca pointer ptrvec em ecx
	movl num, %ebx						#coloca num(Qtd elementos) em ebx
	cmpl $0, %ebx						#verifica se num=0 (se vetor nao tem elementos)
	je vazio							#se sim, salta para vazio
	movl $0, %eax						#se nao, limpa o registo eax e segue para loop

loop:
	cmpl $0, %ebx						#verifica se ebx(num) é zero. (ebx vai ser decrementao a cada iteracao)
	je fim								#se sim, salta para o fim
	
	decl %ebx							#decrementa ebx
	movl (%ecx), %edx					#move o apontado por ecx, para edx
	cmpl $20, %edx						#verifica se edx > 20
	jg maiorQue20						#se sim, salta para maiorQue20
	addl $4, %edx						#avança para o proximo elemento no array
	jmp loop							#salta para loop
	
maiorQue20:
	incl %eax							#incrementa a quantidade de elementos maiores que 20
	addl $4, %edx						#avança para o proximo elemento no array
	jmp loop							#salta para loop
	
vazio:
	movl $0, %eax						#coloca 0 em eax
	jmp fim								#salta para o fim

#-----------------------------------------------------------------------
fim:

	#epilogue
	popl %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
