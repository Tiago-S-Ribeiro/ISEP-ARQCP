.section .data
	
.section .text
	.global sum_n				#int sum_n(int n)
	
sum_n:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	#pushl %ebx
	#pushl %esi
	#pushl %edi
#-----------------------------------------------------------------------

	movl 8(%ebp), %edx			#move o parâmetro da função para edx
	cmpl $0, %edx				#verifica se o parâmetro é <= 0
	jle null					#se sim, salta para o fim
	movl $1, %ecx				#iniciar contador a 1 para a soma
	movl $0, %eax				#inicia eax a 0

loop:
	addl %ecx, %eax 			#adiciona ecx ao eax (1ºiteracao = 1+0)
	cmpl %ecx, %edx 			#verifica se chegamos a 'n'
	je	fim						#se sim, salta para o fim
	incl %ecx 					#senão, incrementa o contador (cont++)
	jmp loop					#salta para loop
	
null:
	movl $0, %eax				#coloca 0 em eax para devolver
	jmp fim						#termina o programa

#-----------------------------------------------------------------------
fim:
	#popl %edi
	#popl %esi
	#popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
