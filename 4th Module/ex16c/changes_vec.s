.section .data
	
.section .text
	
	.global changes_vec			#void changes_vec(int *ptrvec, int num);
	
changes_vec:
	#prologue
	pushl %ebp    
	movl %esp, %ebp
	
	#pushl %ebx
	#pushl %esi
	#pushl %edi
#-----------------------------------------------------------------------

	movl 8(%ebp), %edx			#move o 1º parâmetro da função para edx
	movl 12(%ebp), %ecx			#move o 1º parâmetro da função para ecx

loop:
	cmpl $0, %ecx				#verifica se o vetor já foi percorrido
	je fim						#se sim, termina o programa

	pushl %ecx					#passa por parâmetro à função 'num'
	pushl %edx					#passa por parâmetro à função o 1º elemento do array
	call changes				#chamada da função 'changes'
	popl %edx					#restaura o valor de edx
	popl %ecx					#restaura o valor de ecx

	addl $4, %edx				#avança para o próximo inteiro do vetor
	decl %ecx					#decrementa o contador
	jmp loop					#salta para a próxima iteração

#-----------------------------------------------------------------------
fim:
	#popl %edi
	#popl %esi
	#popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
