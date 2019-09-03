.MODEL SMALL
.STACK 256H
.DATA
oldName DB "B.TXT", 0
newName DB "A.TXT", 0

.CODE
MAIN PROC
        MOV AX, @DATA
        MOV DS, AX
        MOV ES, AX
        LEA DX,oldName
        LEA DI,newName
	MOV AH,56H
	INT 21H
	MOV AH,4CH
	INT 21H
MAIN ENDP
END MAIN