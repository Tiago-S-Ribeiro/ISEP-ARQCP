.section .data

	.global byte1
	.global byte2
	
.section .text

.global concatBytes			#short concatBytes(void)

concatBytes:

		#prologo
		pushl %ebp
		movl %esp, %ebp
		
		movb byte1, %al			 #colocar byte1 no ah (8 bits)
		movb byte2, %ah			 #colocar byte2 no al (8 bits)
		
		#epilogo
		movl %ebp, %esp
		popl %ebp
		ret
