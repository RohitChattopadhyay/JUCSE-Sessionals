; Print Prime numbers
.MODEL SMALL
.STACK 256H
.DATA
MSG DB '2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 83 89 97$'

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