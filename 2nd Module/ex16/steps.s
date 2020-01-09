.section .data

	.global num
	
.section .text

.global steps			 #int steps(void)

steps:
	
	#prologue
	pushl %ebp
	movl %esp, %ebp
	#---------------------------------------------------------------------------
	
	movl num, %eax       #coloca num em eax
	imull $3, %eax       #multiplica 3 por eax           (resultado fica em eax)
	addl $6, %eax        #adiciona 6 a eax               (resultado fica em eax)
	cdq 			     #extende sinal para edx               (TP04 _ Slide 22)
	
	movl $3, %ecx        #coloca 3 em ecx     
	divl %ecx            #divide edx:eax por ecx             (resto fica em edx)
	
	addl $12, %eax       #adiciona 12 a eax
	subl num, %eax       #subtrai numero original ao eax (resultado fica em eax)
	subl $1, %eax        #subtrai 1 ao numero original   (resultado fica em eax)
	
	#---------------------------------------------------------------------------
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
