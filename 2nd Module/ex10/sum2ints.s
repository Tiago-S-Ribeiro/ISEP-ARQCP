.section .data
	.global op1 #int(32bits)
	.global op2 #int(32bits)

.section .text

.global sum2ints		#sum2ints(void)

sum2ints:

	#prologo
	pushl %ebp       	
	movl %esp, %ebp
	
	movl op1, %eax
	movl op2, %ecx
	addl %ecx, %eax
	cdq
	
	#epilogo
	movl %ebp, %esp
	popl %ebp
	ret
