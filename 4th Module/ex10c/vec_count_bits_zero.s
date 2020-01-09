.section .data
	
.section .text
	
	.global vec_count_bits_zero		#int vec_count_bits_zero(int* ptr, int num)
	
vec_count_bits_zero:
	#prologue
	pushl %ebp    
	movl %esp, %ebp
	
	pushl %ebx
	#pushl %esi
	pushl %edi
#-----------------------------------------------------------------------

	movl 8(%ebp), %ebx				#move o 1º parâmetro da função para ebx
	movl 12(%ebp), %ecx				#move o 2º parâmetro da função para ecx
	cmpl $0, %ecx					#verifica se o num de elementos = 0
	je arrayNulo					#se sim, salta para 'arrayNulo'
	movl $0, %edi					#inicia o contador auxiliar de bits inativos a 0

loop:
	cmpl $0, %ecx					#verifica se já percorremos o array todo
	je fim							#salta para o fim se sim
	
	pushl %ecx						#salvaguarda o contador de iteração do array
	pushl (%ebx)					#passa por parâmetro à função o 1º elemento do array
	
	call count_bits_zero			#chamada da função para contagem de bits inativos
	
	addl $4, %esp					#restaura o stack pointer
	popl %ecx						#restaura o valor de ecx
	addl %eax, %edi					#adiciona o valor de retorno da função a edi (temporariamente)
	decl %ecx						#decrementa o ecx (número restante de elementos a percorrer)
	addl $4, %ebx					#avança para o próximo elemento no array
	jmp loop						#salta para a próxima iteração

arrayNulo:
	movl $0, %edi					#coloca 0 em edi
	jmp fim							#termina o programa

#-----------------------------------------------------------------------
fim:
	movl %edi, %eax
	popl %edi
	#popl %esi
	popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
