.section .data
	
.section .text
	.global calc			#int calc(int a, int * b, int c)
	
calc:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	pushl %ebx
	pushl %esi
	pushl %edi
#-----------------------------------------------------------------------

	movl 8(%ebp), %edi			#move o 1º parâmetro da função para edi
	movl 12(%ebp), %esi			#move o 2º parâmetro da função para esi
	movl 16(%ebp), %ebx			#move o 3º parâmetro da função para ebx
	
	movl (%esi), %eax			#move apontado por esi (*b) para eax
	subl %edi, %eax				#subtrai 'a' ao *b       (eax = eax-edi)
	mull %ebx					#multiplica 'c' ao 'z    (eax = eax*ebx)
	subl $2, %eax				#subtrai 2 a eax 	     (eax = eax - 2)
		
#-----------------------------------------------------------------------
fim:
	popl %edi
	popl %esi
	popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
