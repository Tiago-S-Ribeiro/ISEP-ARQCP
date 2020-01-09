.section .data
	.global A 		#char
	.global B 		#short
	.global C 		#int
	.global D 		#int
	
.section .text

.global sum_and_subtract		#sum_and_subtract(void)

sum_and_subtract:
	
	#prologo
	pushl %ebp       	
	movl %esp, %ebp 
	pushl %ebx	
	
	movsxb A, %eax     #move A com extensao de sinal para eax (8bits -> 32bits)
	movl C, %ecx	   #move C para ecx
	addl %ecx, %eax    #eax = eax + ecx
	
	movl D, %edx	   #move D para edx
	subl %edx, %eax    #eax = eax - edx
	
	movsxw B, %ebx	   #move B com extensao de sinal para ebx (16bits -> 32 bits)
	addl %ebx, %eax    #eax = eax + ebx
	cdq				   #extender o resultado de 32bits para 64bits
	
	#epilogo
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
