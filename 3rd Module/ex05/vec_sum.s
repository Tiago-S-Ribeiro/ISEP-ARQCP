.section .data
	.global ptrvec
	.global num
	
.section .text
	.global vec_sum			    #int vec_sum(void)
	
vec_sum:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	pushl %esi
	pushl %edi
	movl $0, %eax				#limpa o registo eax (registo de return)
	
	movl ptrvec, %esi			#coloca ptrvec em esi
	movl num, %ecx				#coloca num em ecx
#-----------------------------------------------------------------------
loop:
	cmpl $0, %ecx				#verifica se ecx é 0 (ou seja, se foram feitas 'num' operacoes)
	je fim						#salta para o fim
	
	movl (%esi), %edi			#coloca o apontado por esi em edi
	addl %edi, %eax				#adiciona o valor em edi a eax
	decl %ecx					#decrementa ecx (valor do num)
	addl $4, %esi				#incrementa o apontador em 32 bits (4 bytes)
	jmp loop					#salta para o loop
	
#-----------------------------------------------------------------------
fim:
	#epilogue
	popl %edi
	popl %esi
	movl %ebp, %esp
	popl %ebp        
	ret
