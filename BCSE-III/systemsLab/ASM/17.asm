; Is second number lesser
.model small
.stack 256h
.data
    num1    db  30h
    num2    db  20h
    msg1    db  "Second number is not lesser.$"
    msg2    db  "Second number is lesser.$"
.code
main proc
    mov ax,@data
    mov ds,ax    
    mov dl,num2
    sub dl,num1
    js lesser
    lea dx, msg1    ; Get address of message
    mov ah, 9       ; Display string function
    int 21h         ; Display call
    mov ah, 4ch     ; Exit program
    int 21h    
lesser:
    lea dx, msg2    ; Get address of message
    mov ah, 9       ; Display string function
    int 21h         ; Display call
    mov ah, 4ch     ; Exit program
    int 21h    
main endp
end main