.section .data
	.global num
	
.section .text
	.global vec_avg			    #int vec_avg(void)
	
vec_avg:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
			
#-----------------------------------------------------------------------
	call vec_sum				#chamada da funcao vec_sum
	movl num, %ecx				#colocar num(qtd de elementos) em ecx
	cmpl $0, %ecx				#verificar se o divisor é zero
	je divisorZero				#se for, salta para divisorZero
	cdq							#extend do registo eax para edx
	idivl %ecx					#eax = eax / ecx
	jmp fim						#salta para o fim

divisorZero:
	movl $0, %eax				#coloca zero em eax
	jmp fim						#salta para o fim
	
#-----------------------------------------------------------------------
fim:
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
