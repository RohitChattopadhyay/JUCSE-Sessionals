.model small
.stack 100h
.data
    msg db "Letters are: $"

.code
main proc 
    mov ax, @data   
    mov ds, ax      ;   Set data segment address
    lea dx, msg     ;   Load address of msg
    mov ah, 9       ;   Write string to STDOUT
    int 21h         ;   Call Display
    mov bl,65       ;   A charachter code
    mov cl,26       ;   Counter

print:
    mov ah,2        ;   Write charachter to STDOUT
    mov dl,bl       ;   Store in DL for display
    inc bl          ;   Increment BL
    dec cl          ;   Decrement Counter
    int 21h         ;   Call Display
    mov dl,32       ;   Store code of "space" in dl
    int 21h         ;   Call Display
    jnz print       ;   Jump to print if not zero 
  mov ah,4ch        ;   Exit code
  int 21h              

main endp
end main