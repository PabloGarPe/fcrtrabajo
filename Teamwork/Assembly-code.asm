.386
.model flat, C

.code

; Complete the procedure
IsValidAssembly PROC

;Prologo
push ebp
mov ebp, esp



mov eax, [ebp+4] ; eax = a

mov ebx, 0
not ebx; Todo 1s
shr ebx, 23 ; Deja tantos 1s como diga Id[1] (32 - 9)

and eax, ebx; 
cmp eax, 108; eax-108 <= 0 implica falso


JZ falso; = 0
JC falso; < 0


; Segunda condicion

mov eax, [ebp+8] ; eax = b
mov ebx, [ebp+12] ; ebx = c

mov ecx, 1; 1
shl ecx, 9; Id[2] = 9
and eax, ecx; Dejo solo el bit 9
shr eax, 9; Lo dejo en la posicion 0

shr ecx, 7; Id[2] - Id[0] = 9 - 2 = 7
and ebx, ecx; Dejo solo el bit 7
shr ebx, 7; Lo dejo en la posicion 0

cmp eax, ebx; eax - ebx != 0 implica falso

JC falso; < 0
JNZ falso; > 0


; Pasa las dos condiciones
mov eax, 1


Epilogo:
	mov esp, ebp
	pop ebp
	ret

falso:
	mov eax, 0
	jmp Epilogo


IsValidAssembly ENDP

END