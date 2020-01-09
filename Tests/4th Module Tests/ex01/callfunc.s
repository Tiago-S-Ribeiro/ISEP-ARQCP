  
.section .text
 .global call_func      
                        # 1st parameter = function to be called    
                        # 2nd parameter = number of "32 bits" on the parameters 
                        # following = func parameters  
 call_func:
   # prologue
    pushl %ebp
    movl %esp, %ebp  # the stack frame pointer for  function

    pushl  %ebx     # save registers 
    pushl  %esi 
    pushl  %edi 
    
    movl   $0xdeadbeef,%ebx   # place marker on registers 
    movl   $0x12345678,%esi
    movl   $0x87654321,%edi 
    
    movl   12(%ebp),%ecx     # count  !!! No checks if number is zero 
push_loop:     
    pushl  12(%ebp,%ecx,4)   # if ecx = 1 => pushl 16(%ebp)  
    decl   %ecx
    jnz    push_loop  
         
    
    movl  8(%ebp),%eax 
    call  *%eax              # call  functions 

    cmpl   $0xdeadbeef,%ebx  # register has changed ? 
    jne    0                #  illegal jump to crash! 
    
    cmpl   $0x12345678,%esi  # register has changed ? 
    jne    0                #  illegal jump to crash! 
    
    cmpl   $0x87654321,%edi  # register has changed ? 
    jne    0                #  illegal jump to crash!  

    movl   12(%ebp),%ecx 
    shll   $2,%ecx 
    addl   %ecx,%esp       # clear stack 	
	
    
    popl %edi               # restore registers 
    popl %esi 
    popl %ebx 
    
    
     # epilogue
     movl %ebp, %esp  #  restore the previous stack pointer ("clear" the stack)
     popl %ebp     #  restore the previous stack frame pointer
     ret


