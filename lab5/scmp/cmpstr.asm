

section .text
	global malami

cmpstr:
	push 	ebp ; push ebp to stack
	mov	ebp, esp ;esp point to ebp 
	mov	ebx,DWORD [ebp+8] 
	movzx	ebx,BYTE [ebx] ;get the first char of str1
	mov	ecx,DWORD [ebp+12] 
	movzx	ecx,BYTE [ecx] ;get the first char of str2
loop:
	cmp 	ebx, ecx ;compare char of str1 and str2
	