.section .data
	
.section .text

	.global count_bits_zero			#int count_bits_zero(int x)
	
count_bits_zero:
	#prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	pushl %ebx
	#pushl %esi
	#pushl %edi
#-----------------------------------------------------------------------

	movl 8(%ebp), %ecx			    #move o parâmetro da função para ecx
	cmpl $-1, %ecx					#verifica se o elemento = -1
	je semBitsInativos				#se sim, salta para semBitsInativos
	movl $0, %eax					#inicia o contador de bits inativos a 0
	movl $0, %ebx					#inicia contador de iterações a 0
	
loop:
	cmpl $32, %ebx					#verifica se já percorri 32 bits
	je fim							#se sim, termina o programa
	
	addl $1, %ebx					#incrementa o ebx (ebx++)
	sarl %ecx						#shift aritmetico de ecx à esquerda 
	jnc bitsInativos				#se não fizer carry, salta para bitsInativos
	jmp loop						#salta para a próxima iteração
	
bitsInativos:
	addl $1, %eax					#incrementa o eax (bits inativos)
	jmp loop						#salta para a próxima iteração	

semBitsInativos:
	movl $0, %eax
	jmp fim
#-----------------------------------------------------------------------
fim:
	#popl %edi
	#popl %esi
	popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
