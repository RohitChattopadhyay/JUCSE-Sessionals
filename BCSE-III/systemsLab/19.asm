.model small
.stack 100h
.data
    msg1 db 'Looping $'
    msg2 db 0dh,0ah,'Loop Ends $'
    msg4 db 0dh,0ah,'Press 0 to end. $'
.code
main proc 
    mov ax, @data
    mov ds, ax
    lea dx, msg1
    mov ah, 9
    int 21h
    lea dx, msg4
    mov ah, 9
    int 21h
    mov bl,0

looper:
    inc bl
    mov ah, 1       ; Read char function
    int 21h         ; Read call
    cmp al, '0'
    jnz looper

    lea dx, msg2    ; Get address of message
    mov ah, 9       ; Display string function
    int 21h         ; Call display
    mov ah,4ch
    int 21h

main endp
end main