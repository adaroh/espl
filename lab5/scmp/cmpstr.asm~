
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
	cmp 	eax, ebx  ;compare char of str1 with char of str2
	jne	.NotEqual ;if the chars not the same go to .NotEqual
	;this block will be done when eax==ebx
	add	DWORD[ebp+8],1
	add	DWORD[ebp+12],1  
	mov	eax,DWORD [ebp+8] ;get the next char of str1
	movzx	eax,BYTE [ebx] 
	mov	ebx,DWORD [ebp+12] ;get the next char of str2
	movzx	ebx,BYTE [ecx] 


.NotEqual:
	cmp 	eax,ebx   ;compare char of str1 with char of str2
	jl	.Less     ;jump to .Less when eax<abx
	jg	.Greater  ;jump to .Less when eax>abx
	je	.Equal 	  ;jump to .Less when eax=abx


.Less:
	mov	 eax,2 ; return value = 2
	jmp	.END

.Greater:
	mov	eax,1  ; return value = 1
	jmp	.END

.Equal:
	mov	eax,0  ; return value = 0
	jmp	.END

.END:
	mov	esp,ebp ;ebp pointed to head stack 
	pop	ebp
	ret