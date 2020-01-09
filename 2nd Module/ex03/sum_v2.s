.section .data
	.global op1
	.global op2
	.equ CONST,15
	
.section .text
	.global sum_v2         #int sum_v2(void)
	
sum_v2:
	#prologo
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx
   
    movl op1, %ecx         #colocar op1 no ecx
	movl op2, %edx         #colocar op2 no edx
	movl $CONST, %eax      #colocar valor da constante no eax
	movl $CONST, %ebx      #colocar valor da constante no ebx
	
	subl %ecx, %eax        #(eax = eax - ecx) Resultado fica em eax
	subl %edx, %ebx        #(ebx = ebx - edx) Resultado fica em ebx
	subl %ebx, %eax        #(eax = eax - ebx) Resultado fica em eax
	
	#epilogo
	popl %ebx
	movl %ebp, %esp        
	popl %ebp              
	ret
		
