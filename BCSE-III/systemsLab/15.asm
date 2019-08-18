; Print Terminating message
.MODEL SMALL
.STACK 256H
.DATA
MSG DB 'Program Terminated...$'

.CODE
MAIN PROC
    MOV AX, @DATA    ;   Initialize DS to address
    MOV DS, AX       ;   of Data Segment
    LEA DX, MSG      ;   Load effective address
    MOV AH, 09H      ;   Display string function
    INT 21H          ;   Display message
    MOV DL, 10       ;   Display new Line
    MOV AH, 02H      ;   Display charachter to STDOUT
    INT 21H          ;   Display message
    MOV AH, 4CH      ;   DOS function: Exit program
    INT 21H          ;   Call DOS
MAIN ENDP
END MAIN