
;The function takes a string that represents a number
; and converts it to integer


section .text
	global malami
malami:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	mov	DWORD [ebp-4], 0
	jmp	.L2
.L3:
	mov	eax, DWORD [ebp-4] ;takes previous sum into eax
	mov ebx, eax  ; copy to ebx
	sal eax, 3    ; multiply eax by 8
	sal ebx, 1 	; multiply ebx by 2	      
	add eax, ebx	
	; you have in effect multiplied eax by 10	
	mov	ebx, DWORD [ebp+8] ;put last char in ebx
	movzx	ebx, BYTE [ebx]
	movsx	ebx, bl
	add	eax, ebx  ; add the current char to sum
	sub	eax, 48   ;48 is 0 in ascii. 
	mov	DWORD [ebp-4], eax ; move result to sum parameter
	add	DWORD [ebp+8], 1 ;
.L2:
	mov	eax, DWORD [ebp+8]
	movzx	eax, BYTE [eax]
	test	al, al  ;logic &
	jne	.L3
	mov	eax, DWORD [ebp-4] ; move resul to eax. eax is always output
	mov esp, ebp ; go to head of stack
	pop ebp ; pop beginning 
	ret ;return eax
