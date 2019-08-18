.model small
.stack 100h
.data
    msg db "Letters are: $"

.code
main proc 
    mov ax, @data
    mov ds, ax
    lea dx, msg
    mov ah, 9
    int 21h
    mov bl,65
    mov cl,26

print:
    mov ah,2
    mov dl,bl
    inc bl
    dec cl
    int 21h
    mov dl,32
    int 21h
    jnz print
  mov ah,4ch
  int 21h

main endp
end main