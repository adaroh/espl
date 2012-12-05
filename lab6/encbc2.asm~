 
section	.text
    global main			;must be declared for linker (ld)

extern start

main:					;tell linker entry point
	push 	ebp ; push ebp to stack
	mov	ebp, esp ;esp point to ebp 
	push	DWORD[ebp+12] ;insert argv to ebx
	push 	DWORD[ebp+8]  ;insert argc to eax
	call 	start
	mov 	esp,ebp ;ebp pointed to head stack 
	pop	ebp
	ret