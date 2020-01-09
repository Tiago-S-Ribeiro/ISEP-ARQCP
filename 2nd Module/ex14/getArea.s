.section .data
base:
			.int 6
height:
			.int 2

	.global base	 #int
	.global height   #int

.section .text

.global getArea  #int getArea(void)

getArea:

	#prologue
	pushl %ebp       
	movl %esp, %ebp
	  
	movl height, %ecx   #coloca altura no ecx
	movl base, %eax     #coloca base no eax

	mull %ecx	        #multiplica ecx com eax(resultado fica em eax)

	movl $2, %ecx       #coloca 2 no ecx

	divl %ecx           #divide eax por ecx(que é 2 nesta instancia)

	# epilogue
	movl %ebp, %esp 
	popl %ebp        
	ret
