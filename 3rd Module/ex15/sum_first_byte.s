.section .data
	.global ptrvec
	.global num
	
.section .text
	.global sum_first_byte			    #int sum_first_byte(void)
	
sum_first_byte:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	pushl %ebx
	pushl %esi
	pushl %edi
#-----------------------------------------------------------------------

	movl ptrvec, %esi					#coloca pointer ptrvec em esi
	movl num, %ebx						#coloca num(Qtd elementos) em ebx
	movl $0, %eax
	movl $0, %ecx
	
loop:
	cmpl $0, %ebx						#verifica se ebx(num) é zero. (ebx vai ser decrementao a cada iteracao)
	je fim								#se sim, salta para o fim
	
	decl %ebx							#decrementa ebx(num)
	movl (%esi), %ecx					#move o apontado por esi, para ecx
	movsxb %cl, %edi					#move com extensao de sinal de 8 para 32 bits
	addl %edi, %eax						#eax = eax + edi
	addl $4, %esi						#avança para o proximo elemento no array
	jmp loop							#salta para o loop
	
vazio:
	movl $0, %eax						#coloca 0 em eax
	jmp fim								#salta para o fim
#-----------------------------------------------------------------------
fim:
	popl %edi
	popl %esi
	popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
