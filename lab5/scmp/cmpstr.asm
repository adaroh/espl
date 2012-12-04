
section .text
	global malami

cmpstr:
	push 	ebp ; push ebp to stack
	mov	ebp, esp ;esp point to ebp 
	mov	eax,DWORD [ebp+8] ;get the first char of str1
	movzx	eax,BYTE [ebx] 
	mov	ebx,DWORD [ebp+12] ;get the first char of str2
	movzx	ebx,BYTE [ecx] 
loop:
	cmp 	eax, ebx  ;compare char of str1 and str2
	jne	.NotEqual ;if the chars not same go to .NotEqual
	;this block will be done when eax==ebx
	add	DWORD[ebp+8],1
	add	DWORD[ebp+12],1  
	mov	eax,DWORD [ebp+8] ;get the next char of str1
	movzx	eax,BYTE [ebx] 
	mov	ebx,DWORD [ebp+12] ;get the next char of str2
	movzx	ebx,BYTE [ecx] 


.NotEqual:
	cmp 	eax,ebx   ;compare char of str1 and str2
	jl	.Less     ;jump to .Less when char in eax<abx
	jg	.Greater  ;jump to .Less when char in eax>abx
	je	.Equal 	  ;jump to .Less when char in eax=abx


.Less:
	mov	 eax,2 ; update a value to return to 2
	jmp	.END

.Greater:
	mov	eax,1  ; update a value to return to 1
	jmp	.END

.Equal:
	mov	eax,0  ; update a value to return to 0
	jmp	.END

.END:
	mov	esp,ebp
	pop	ebp
	ret