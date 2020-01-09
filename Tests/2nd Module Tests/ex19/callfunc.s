  
.section .text
 .global call_func 
 
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
    
    movl 8(%ebp),%eax 
    call  *%eax              # call  functions 

    cmpl   $0xdeadbeef,%ebx  # register has changed ? 
    jne    0                #  illegal jump to crash! 
    
    cmpl   $0x12345678,%esi  # register has changed ? 
    jne    0                #  illegal jump to crash! 
    
    cmpl   $0x87654321,%edi  # register has changed ? 
    jne    0                #  illegal jump to crash! 
    
    popl %edi               # restore registers 
    popl %esi 
    popl %ebx 
    
    
     # epilogue
     movl %ebp, %esp  #  restore the previous stack pointer ("clear" the stack)
     popl %ebp     #  restore the previous stack frame pointer
     ret


