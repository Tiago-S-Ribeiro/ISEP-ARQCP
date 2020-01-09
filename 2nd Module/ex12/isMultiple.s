.section .data
	.global A
	.global B

.section .text

.global isMultiple		#int isMultiple(void)

isMultiple:
	
	#prologo
	pushl %ebp       	
	movl %esp, %ebp
	movl $0, %eax
	movl $0, %edx
	
	movl A, %eax       #colocar A em eax
	movl B, %ecx       #colocar B em ecx
	cmpl $0, %ecx
	je divisorZero
	divl %ecx		   #divide eax por ecx
	
	cmpl $0, %edx      #compara 0 com valor em edx pois o resto fica em edx
	je restoZero	   #jump if equal (salta para restoZero se edx = 0)
	movl $0, %eax      #coloca 0 em eax (significa que nao é multiplo)
	jmp end			   #salta para o fim

restoZero:
	movl $1, %eax      #coloca 1 em eax (significa que é multiplo)
	jmp end			   #salta para o fim

divisorZero:
	movl $0, %eax
	jmp end
end:
	#epilogo
	movl %ebp, %esp
	popl %ebp
	ret
