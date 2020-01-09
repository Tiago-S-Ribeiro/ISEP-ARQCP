.section .data
A:
	.int 4
B:
	.int 2
	
	.global A
	.global B
	.global n
	.global i
	
.section .text

.global somatorio			#int somatorio(void)

somatorio:
	
	#prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx
	pushl %esi
	#----------------------------------------------------------------------------
	
	movl A, %eax            #colocar A em eax
	imull %eax, %eax        #colocar A² em eax
	cdq
	movl B, %ecx            #colocar B em ecx
	idivl %ecx              #divide eax (A²) por ecx (B) ->(resultado fica em eax)
	movl %eax, %esi         #resultado da divisao anterior fica em esi

	movl $0, %edx 
    movl n, %edx            #colocar 'n' em edx

	movl i, %ebx            #colocar 'i' em ebx ('i' vai ser incrementado n vezes)
	movl $0, %ecx           #dar 'reset' a ecx para ficar com o registo livre
	
	#----------------------------------------------------------------------------
loop:
	
	movl $0, %eax           #dar 'reset' a eax para ficar com o registo livre
	movl %ebx, %eax         #colocar 'i' em eax
	imull %eax, %eax        #colocar i² em eax
	imull %esi, %eax        #multiplica esi (valor onde guardei A²/B antes) por eax (i²)
	addl %eax, %ecx         #summing the previous result to what is already in ecx
	
	cmpl %edx, %ebx         #compara edx(n) com ebx(i), quando for igual, salta para o fim
	je fim                  #salta para o fim se (i = n)
	incl %ebx               #incrementa 'i' -> ( i = i + 1)
	jmp loop
	
	#----------------------------------------------------------------------------
fim:
	movl %ecx, %eax         #move resultado do somatorio de ecx para eax
	
	#---------------------------------------------------------------------------
	#epilogue
	popl %esi
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
