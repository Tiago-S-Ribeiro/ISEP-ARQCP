.section .data
	
.section .text
	.global activate_2bits			#void activate_2bits(int *ptr, int pos)
	
activate_2bits:
	#prologue
	pushl %ebp 			
	movl %esp, %ebp 
				
	pushl %ebx
	#pushl %edi
	#pushl %esi
#-----------------------------------------------------------------------
	
	#movl 8(%ebp), %edi								#move o 1º parâmetro da função para edi
	#movl 12(%ebp), %esi							#move o 2º parâmetro da função para esi
	
	pushl 12(%ebp)									#pushl %esi			#passa o 2º parâmetro à função
	pushl 8(%ebp)									#pushl (%edi)		#passa o 1º parâmetro à função
	call activate_bit				#1ª chamada da funçao para ativar bit em 'pos'
	addl $8, %esp					#restaura o stack pointer
	
	
	movl 12(%ebp), %ecx
	movl $31, %edx					#coloca 31 em eax
	subl %ecx, %edx					#eax = eax - ecx (31 - pos)
	
	pushl %edx						#passa o 2º parâmetro à função
	pushl 8(%ebp)									#pushl (%edi)		#passa o 1º parâmetro à função
	call activate_bit				#2ª chamada da funçao para ativar bit em (31-pos)
	addl $8, %esp					#restaura o stack pointer
	
#-----------------------------------------------------------------------

	#popl %esi
	#popl %edi
	popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
