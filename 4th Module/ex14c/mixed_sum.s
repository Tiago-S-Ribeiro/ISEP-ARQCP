.section .data
	
.section .text

	.global mixed_sum		#int mixed_sum(int a, int b, int pos)
	
mixed_sum:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	#pushl %ebx
	#pushl %esi
	#pushl %edi
#-----------------------------------------------------------------------

	subl $8, %esp			#reserva espaço na stack para 2 variaveis locais
	movl 8(%ebp), %eax		#move o 1º parâmetro da função para eax
	movl 12(%ebp), %ecx		#move o 2º parâmetro da função para ecx
	movl 16(%ebp), %edx		#move o 3º parâmetro da função para edx
	
	pushl %edx				#passa 'pos' por parâmetro à função 
	pushl %ecx				#passa 'b' por parâmetro à função
	pushl %eax				#passa 'a' por parâmetro à função
	
	call join_bits			#chamada da função
	addl $12, %esp			#restaura o stack pointer (excepto eax)
	
	movl %eax, -4(%ebp)		#guarda o resultado da função numa variavel local

	movl 8(%ebp), %eax		#move o 1º parâmetro da função para eax
	movl 12(%ebp), %ecx		#move o 2º parâmetro da função para ecx
	movl 16(%ebp), %edx		#move o 3º parâmetro da função para edx
		
	pushl %edx				#passa 'pos' por parâmetro à função
	pushl %eax				#passa 'a' por parâmetro à função
	pushl %ecx				#passa 'b' por parâmetro à função
	
	call join_bits
	addl $12, %esp			#restaura o stack pointer (excepto eax)

	movl %eax, -8(%ebp)		#guarda o resultado da função numa variavel local
	movl -4(%ebp), %eax		#coloca o resultado da primeira chamada em eax
	addl -8(%ebp), %eax		#soma as duas variaveis locais, com o resultado a ficar em eax

#-----------------------------------------------------------------------
fim:
	#popl %edi
	#popl %esi
	#popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
