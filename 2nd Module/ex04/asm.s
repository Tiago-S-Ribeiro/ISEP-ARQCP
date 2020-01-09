.section .data
op3:
	.int 3
op4:
	.int 4
	
	.global op1
	.global op2
	.global op3
	.global op4
	.equ CONST,15
	
.section .text
	.global sum_v3         #int sum_v3(void)
	
sum_v3:
	#prologo
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx  		   #valor de ebx colocado no topo da stack
   
    movl op1, %eax         #colocar op1 no eax
	movl op2, %ebx         #colocar op2 no ebx
	movl op3, %ecx		   #colocar op3 no ecx
	movl op4, %edx		   #colocar op4 no edx
	
	addl %edx, %ecx        #(ecx = ecx + edx) Resultado fica em ecx
	subl %ebx, %ecx        #(ecx = ecx - ebx) Resultado fica em ecx
	addl %ecx, %eax        #(eax = eax + ecx) Resultado fica em ecx
	
	#epilogo
	popl %ebx  			   #valor inicial de ebx recuperado
	movl %ebp, %esp        
	popl %ebp              
	ret

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
	
	.global sum            # int sum(void)
sum:

						   # prologue
	pushl %ebp             # save previous stack frame pointer
	movl %esp, %ebp        # the stack frame pointer for sum function
	movl op1, %ecx         #place op1 in ecx
	movl op2, %eax         #place op2 in eax
	addl %ecx, %eax        #add ecx to eax. Result is in eax

                           # epilogue
	movl %ebp, %esp        # restore the previous stack pointer ("clear" the stack)
	popl %ebp              # restore the previous stack frame pointer
	ret
