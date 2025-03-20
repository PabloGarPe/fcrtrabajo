.386
.model flat, C

.code

; Complete the procedure
IsValidAssembly PROC

;_______Prologo________
push ebp				; Guarda el program counter
mov ebp, esp			; Mueve al program counter el counter de subprograma

push ebx				; Guarda el valor de ebx
push ecx				; Guarda el valor de ecx


;______________Primera condicion__________
; Los 9 bits mas bajos de a tienen que ser mayores que 108

mov eax, [ebp+8]		; eax = a


mov ebx, 0				; ebx = 0
not ebx; Todo 1s		; ebx = 0xFFFFFFFF
shr ebx, 23				; Deja tantos 1s como diga Id[1] = 9 (32 - 9 = 23), 

and eax, ebx			; Máscara de los 9 bits mas bajos de eax
cmp eax, 108			; eax-108 <= 0 implica falso


JZ falso				; Comprueba = 0
JC falso				; Comprueba < 0


;__________Segunda condicion__________________
; El bit 9 de ebx tiene que ser el mismo que el bit 2 de ecx

mov eax, [ebp+12]		; eax = b
mov ebx, [ebp+16]		; ebx = c

mov ecx, 1				; ecx = 1
shl ecx, 9				; Id[2] = 9
and eax, ecx			; Dejo solo el bit 9 de eax
shr eax, 9				; Lo muevo a la posicion 0

shr ecx, 7				; Id[2] - Id[0] = 9 - 2 = 7
and ebx, ecx			; Dejo solo el bit 7
shr ebx, 7				; Lo muevo a la posicion 0

cmp eax, ebx			; eax - ebx != 0 implica falso


JZ verdadero			; Si son iguales cumple las dos condiciones
JMP falso				; Si no, no las cumple


verdadero:
	mov eax, 1			; Devuelve 1
	jmp Epilogo



falso:
	mov eax, 0			; Devuelve 0
	jmp Epilogo


Epilogo:
	pop ecx				; Recupera ecx
	pop ebx				; Recupera ebx

	mov esp, ebp		; Recupera el program counter
	pop ebp				; Descarta el sub counter
	ret					; Devuelve


IsValidAssembly ENDP

END