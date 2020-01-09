.section .data
	.global ptr1
	.global ptr2
	
.section .text
	.global str_copy_porto2		#void str_copy_porto2(void)
	
str_copy_porto2:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	pushl %esi
	pushl %edi
	pushl %ebx
	
#-----------------------------------------------------------------------

	movl ptr1, %esi				#colocar o endereço de ptr1 em esi	
	movl ptr2, %edi				#colocar o endereço de ptr2 em edi

loop:
	movb (%esi), %bl			#mover o carater apontado por esi(ptr1) para bl
	movb %bl, (%edi)			#move o carater em bl para apontado por edi(ptr2)
	cmpb $0 ,% bl				#verifica se é o final da string
	je fim						#se for final da string, salta para o fim
	
	cmpb $'v', %bl				#verifica se o carater é 'v'
	je vMinusculo				#salta para vMinusculo se a condição se verificar
	
	cmpb $'V', %bl				#verifica se o carater é 'V'
	je vMaiusculo				#salta para vMaiusculo se a condição se verificar
	
	movb %bl, (%edi)			#coloca o carater de bl no apontado por edi
	jmp incremento				#salta para o incremento
	
vMinusculo:
	movb $'b', (%edi)			#coloca o carater 'b' no apontado por edi
	jmp incremento				#salta para o incremento
	
vMaiusculo:	
	movb $'B', (%edi)			#coloca o carater 'B' no apontado por edi
	jmp incremento				#salta para o incremento
	
incremento:
	incl %esi					#incrementa um carater em esi
	incl %edi					#incrementa um carater em edi
	jmp loop					#salta para o loop

#-----------------------------------------------------------------------
fim:
	#epilogue
	popl %ebx
	popl %edi
	popl %esi
	movl %ebp, %esp
	popl %ebp        
	ret
