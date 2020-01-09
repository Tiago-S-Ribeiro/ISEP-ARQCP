.section .data
	.global i
	.global j

.section .text
	.global f   					#int f(void)
	.global f2  					#int f2(void)
	.global f3  					#int f3(void)
	.global f4  					#int f4(void)

#-----------------------------------------------------------------------
f:
	#prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx
	#-------------------------------------------------------------------
 	movl i, %ebx					#coloca i em ebx
 	movl j, %ecx					#coloca j em ecx
 	cmpl %ecx, %ebx   				#compara i com j
 	je equals						#salta para 'equals' se forem iguais

 	addl %ecx, %ebx  				#ebx = ebx + ecx (i + j)
 	movl %ebx, %eax  				#colocar resultado anterior em eax
 	subl $1, %eax    				#eax = eax - 1 (eax é o h, valor a retornar)
 	jmp fim							#salta para o fim

equals:
	subl %ecx, %ebx    				#ebx = ebx - ecx (i - j)
	movl $1, %eax					#colocar 1 em eax
	addl %ebx, %eax   				#eax = 1 + ebx (eax é o h, valor a retornar)
	jmp fim							#salta para o fim

	#-------------------------------------------------------------------
fim:
	#epilogue
	popl %ebx
	movl %ebp, %esp 
	popl %ebp      
	ret	
#-----------------------------------------------------------------------

f2:
	#prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx
	#-------------------------------------------------------------------	
 	movl i, %ebx					#coloca i em ebx
 	movl j, %ecx					#coloca j em ecx
	cmpl %ecx, %ebx   				#compara i com j
 	jg maior						#salta para 'maior' se (i>j)

 	incl %ecx       				#j = j + 1
 	jmp fim2						#salta para o fim

maior:	
	 decl %ebx  					#i = i + 1
	 jmp fim2						#salta para o fim

	#-------------------------------------------------------------------
fim2:
	 movl %ecx, %eax     		#coloca ecx em eax (j em eax)
	 mull %ebx     				#multiplica ebx com eax (j * i)
		
     #epilogue
	 popl %ebx
	 movl %ebp, %esp
	 popl %ebp
	 ret
#-----------------------------------------------------------------------
f3:
	#prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx
	pushl %esi
	pushl %edi
	movl $0, %eax
	movl $0, %ebx					#duvida a tira com o professor
	movl $0, %ecx                   #pois se não colocar isto, recebo
	movl $0, %edx                	#floating point exception
	#-------------------------------------------------------------------
 	movl i, %ebx					#coloca i em ebx
 	movl j, %ecx					#coloca j em ecx
	cmpl %ecx, %ebx   				#compara i com j
	jge maiorOuIgual                #salta para 'maior' se (i>=j)
 	
 	movl %ebx, %esi     			#coloca i em esi
 	addl %ecx, %esi    				# i + j = g (esi)
 	movl %esi, %edi					#coloca esi(g) em edi
 	addl $2, %edi      				#soma 2 ao edi(g)
 	jmp fim3

maiorOuIgual:
	 movl %ecx, %eax    			#coloca ecx em eax (j em eax)    
	 mull %ebx               		#multiplica ebx com eax (i * j)
	 movl %eax, %esi 				#coloca eax(i*j) em esi	(esi é o h)	
	 incl %ebx						#i = i + 1
	 movl %ebx, %edi				#coloca ebx (g) em edi
	 jmp fim3						#salta para o fim

	#-------------------------------------------------------------------
fim3:
	 movl $0, %eax       			#eax is r
	 movl %edi, %eax 				#coloca edi (g) em eax
	 divl %esi           			#divide eax por esi (g/h)
		
	 # epilogue
	 popl %edi
	 popl %esi
	 popl %ebx
	 movl %ebp, %esp 
	 popl %ebp        
	 ret
#-----------------------------------------------------------------------

f4:
	 #prologue
	 pushl %ebp
	 movl %esp, %ebp
	 pushl %ebx
	 pushl %esi
	 pushl %edi
	 movl $0, %eax
 	 movl $0, %edx
 	 movl $0, %ebx
 	 movl $0, %ecx
 	 #------------------------------------------------------------------
 	 movl i, %ebx					#coloca i em ebx
 	 movl j, %ecx					#coloca j em ecx
 	 #movl $0, %esi
 	 movl %ecx, %esi                #coloca ecx em esi (j em esi)
 	 addl %ebx, %esi                #esi = esi + ebx (esi = j + i)

 	 #movl $0, %edi
 	 movl $10, %edi					#coloca 10 em edi

 	 cmpl %esi, %edi        		#compara esi (j+i) com 10
 	 jg maior_10					#salta para maior_10 se 10 > (j+i)
	 	
 	 movl %ecx, %eax				#coloca ecx em eax (j em eax)
 	 mull %eax						#eax*eax (j²)
 	 movl $0, %edi					#dar 'reset' a edi para ficar com o registo livre
 	 movl $3, %edi					#coloca 3 em edi
 	 divl %edi						#divide eax por edi (j² / 3)
 	 jmp end4						#salta para o fim

maior_10:
	 	movl %ebx, %eax				#coloca ebx em eax (i em eax)
	 	mull %eax					#eax*eax (i²)
	 	movl $0, %edi				#dar 'reset' a edi para ficar com o registo livre
	 	movl $4, %edi				#coloca 4 em edi
	 	mull %edi					#multiplica edi por eax ( 4 * i²)
	 	jmp end4					#salta para o fim

    #-------------------------------------------------------------------
end4:
		#epilogue
		popl %edi
		popl %esi
		popl %ebx
		movl %ebp, %esp 
		popl %ebp      
		ret
#-----------------------------------------------------------------------
