
section .text
	global cmpstr

cmpstr:
	push 	ebp ; push ebp to stack
	mov	ebp, esp ;esp point to ebp 
loop:
	mov	eax,DWORD [ebp+8] ;get the first char of str1
	movzx	eax,BYTE [eax] 
	mov	ebx,DWORD [ebp+12] ;get the first char of str2
	movzx	ebx,BYTE [ebx] 
	test    eax, eax ; compare current char in str1 to zero
	je   endloop ; end of str1
	cmp 	eax, ebx  ;compare char of str1 with char of str2
	jne	 endloop ; chars differ
	
	;this block will be done when eax==ebx
	add	DWORD[ebp+8],1
	add	DWORD[ebp+12],1  
	jmp	loop


endloop:
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
