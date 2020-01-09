.section .data
	
.section .text
	.global sum_smaller			#int sum_smaller(int num1, int num2, int *smaller)
	
sum_smaller:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	pushl %ebx
	#pushl %esi
	#pushl %edi
#-----------------------------------------------------------------------

	movl 8(%ebp), %edx			#move o 1º parâmetro da função para edx
	movl 12(%ebp), %ecx			#move o 2º parâmetro da função para ecx
	movl 16(%ebp), %ebx			#move o 3º parâmetro da função para ebx
	movl $0, %eax				#coloca 0 em eax (soma = 0)
	
	addl %edx, %eax				#soma o 1º parâmetro a eax (eax=eax+edx)
	addl %ecx, %eax				#soma o 2º parâmetro a eax (eax=eax+ecx)
	
	cmpl %edx, %ecx				#compara ecx com edx
	jge param2Maior				#salta para param2Maior se o 2ºP > 1ºP
	movl %ecx, (%ebx)			#coloca o 1ºP no apontado por ebx
	jmp fim						#termina o programa
	
param2Maior:
	movl %edx, (%ebx)			#coloca o 2ºP no apontado por ebx
	jmp fim						#termina o programa
	
#-----------------------------------------------------------------------
fim:
	#popl %edi
	#popl %esi
	popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
