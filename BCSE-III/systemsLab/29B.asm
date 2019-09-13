.MODEL SMALL
.STACK 300H
.DATA
ARRAY1 DB 5 DUP(?)
MSG4 DB 0AH,0DH,'Enter size of the array: $'
MSG1 DB 0AH,0DH,'Enter number to be searched: $'
MSG2 DB 0AH,0DH,'FOUND AT POSITION $ '
MSG3 DB 0AH,0DH,'NOT FOUND$'
ENDL DB 0AH,0DH,'$'
KEY DB '$'
SE DB 33H
COUNT DB 00H

.CODE

PRINT MACRO MSG
	push ax
	push dx
	mov AH, 09H
	lea DX, MSG
	int 21H
	pop dx
	pop ax
ENDM

MAIN PROC
	MOV AX,@DATA
	MOV DS,AX

START:

	PRINT MSG4
	call readnum
	mov COUNT, al
	mov cl, COUNT
	mov bx, 00h
	rdnxt:
		PRINT ENDL
		call readnum
		mov ARRAY1[BX],AL
		inc BX
	loop rdnxt
	
	mov cl, COUNT

	LEA SI, ARRAY1
	MOV BH,0
	MOV BL,COUNT
	CALL PRINT_ARRAY

	PRINT MSG1
	call readnum	
	mov bh,al
	mov dl,00h
	mov dh,COUNT
	mov ch,0
	mov cl,COUNT
	dec dh
UP:
	CMP dl,dh
	JG NF
	mov al, dl
	add al, dh
	mov bl, 2
	mov ah, 0
	div bl
	mov ah, 0
	ADD SI,AX
	MOV BL,[SI]
	mov ah,02h
	mov dl,AL
	INT 21h
	CMP bh, BL
	JZ FO
	JG LEFT
	JL RIGHT
	loop UP
NF:	PRINT MSG3
	JMP END1
RIGHT:
	inc al
	mov dl,al
	JMP UP
LEFT:
	dec al
	mov dh,al
	JMP UP
FO:
	PRINT MSG2
	call writenum
 
END1:
	mov ah, 4ch
	int 21h

MAIN ENDP

PRINT_ARRAY PROC
   ; this procedure will print the elements of a given array
   ; input : SI=offset address of the array
   ;       : BX=size of the array
   ; output : none

   PUSH AX                        ; push AX onto the STACK   
   PUSH CX                        ; push CX onto the STACK
   PUSH DX                        ; push DX onto the STACK
   push SI
   MOV CX, BX                     ; set CX=BX

   @PRINT_ARRAY:                  ; loop label
     XOR AH, AH                   ; clear AH
     MOV AL, [SI]                 ; set AL=[SI]

     CALL writenum                  ; call the procedure OUTDEC

     MOV AH, 2                    ; set output function
     MOV DL, 20H                  ; set DL=20H
     INT 21H                      ; print a character

     INC SI                       ; set SI=SI+1
   LOOP @PRINT_ARRAY              ; jump to label @PRINT_ARRAY while CX!=0

   pop SI
   POP DX                         ; pop a value from STACK into DX
   POP CX                         ; pop a value from STACK into CX
   POP AX                         ; pop a value from STACK into AX

   RET                            ; return control to the calling procedure
 PRINT_ARRAY ENDP


readnum proc near
	
	push bx
	push cx
	mov cx,0ah
	mov bx,00h
loopnum: 
	mov ah,01h
	int 21h
	cmp al,'0'
	jb skip
	cmp al,'9'
	ja skip
	sub al,'0'
	push ax
	mov ax,bx
	mul cx
	mov bx,ax
	pop ax
	mov ah,00h
	add bx,ax
	jmp loopnum
skip:
	mov ax,bx
	pop cx
	pop bx
	ret
readnum endp

writenum PROC near
   ; this procedure will display a decimal number
   ; input : AX
   ; output : none

   push bx                        ; push BX onto the STACK
   push cx                        ; push CX onto the STACK
   push dx                        ; push DX onto the STACK

   XOR CX, CX                     ; clear CX
   MOV BX, 10                     ; set BX=10

   @OUTPUT:                       ; loop label
     XOR DX, DX                   ; clear DX
     DIV BX                       ; divide AX by BX
     PUSH DX                      ; push DX onto the STACK
     INC CX                       ; increment CX
     OR AX, AX                    ; take OR of Ax with AX
   JNE @OUTPUT                    ; jump to label @OUTPUT if ZF=0

   MOV AH, 2                      ; set output function

   @DISPLAY:                      ; loop label
     POP DX                       ; pop a value from STACK to DX
     OR DL, 30H                   ; convert decimal to ascii code
     INT 21H                      ; print a character
   LOOP @DISPLAY                  ; jump to label @DISPLAY if CX!=0

   POP DX                         ; pop a value from STACK into DX
   POP CX                         ; pop a value from STACK into CX
   POP BX                         ; pop a value from STACK into BX

   RET                            ; return control to the calling procedure
writenum ENDP
	
END MAIN