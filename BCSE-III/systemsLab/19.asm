.model small
.stack 100h
.data
    msg1 db 'Looping $'
    msg2 db 0dh,0ah,'Loop Ends $'
    msg4 db 0dh,0ah,'Press 0 to end. $'
.code
main proc 
    mov ax, @data
    mov ds, ax      ; Set data segment address
    lea dx, msg1    ; Set address to msg1
    mov ah, 9       ; Display String function
    int 21h         ; Call Display
    lea dx, msg4    ; Set address to msg1
    mov ah, 9       ; Display String function
    int 21h         ; Call Display

looper:
    mov ah, 1       ; Read char function
    int 21h         ; Read call
    cmp al, '0'
    jnz looper

    lea dx, msg2    ; Get address of msg2
    mov ah, 9       ; Display string function
    int 21h         ; Call display
    mov ah,4ch
    int 21h

main endp
end main