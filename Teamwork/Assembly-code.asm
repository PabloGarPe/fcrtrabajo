.386
.model flat, C

.code

; Complete the procedure
IsValidAssembly PROC

mov eax, [esp+4] ; a

mov ebx, 0
not eax; Todo 1s
shr ebx, 32 ; Deja tantos 1s como diga Id[1] (32 - 0)

and eax, ebx; 
cmp eax, 108; eax-108 <= 0 implica falso


JZ falso; = 0
JC falso; < 0

mov eax, [esp+8] ; b
mov ebx, [esp+12] ; c

mov ecx, 1; 1
shl ecx, 0; Id[2] = 0
and eax, ecx; Dejo solo el bit 0

shl ecx, 3; Id[0] = 3
and ebx, ecx; Dejo solo el bit 3
shr ebx, 3; Lo dejo en la posicion 0

cmp eax, ebx; eax - ebx != 0 implica falso

JC falso; < 0
JNZ falso; > 0

mov eax, 1
ret

falso:
mov eax, 0
ret


IsValidAssembly ENDP

END