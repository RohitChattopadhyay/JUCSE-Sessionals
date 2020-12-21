; Hexadecimal number addition
.model small
.stack 256h
.data
linefeed      db 13, 10, "$"
num1          db 35h, "$"
num2          db 30h, "$"
hex_out       db 0, 0, 0, "H$"

.code

call main

mov  ax,4c00h               ; terminate properly
int  21h  

main proc
    mov ax,@data            
    mov ds,ax               ; Set address to Data Segment    
    mov dl,num1             ; Move first number to dl
    add dl,num2             ; Add  second number to first
    mov dh,0                ; Set dh to 0
    jnc nocarry             
    inc dh                  ; Increment dh
nocarry:
    call print_hex          ; Subroutine Call  
    ret   
main endp

print_hex proc
    mov cx,3                ; Set result length
c_loop:
    dec cx                  ; Decrement cx
    mov ax, dx
    
    shr dx,1                ; Right shift
    shr dx,1                ; Right shift
    shr dx,1                ; Right shift
    shr dx,1                ; Right shift
    
    and ax,0fh              ; AND to get right 4bits
    
    mov bx, offset hex_out  ; Make string
    add bx,cx
    
    cmp ax,0ah              ; carry check
    jl set_digit            ; Jump if less
    add al,27h              ; Add 27h

set_digit:
    add al,30h              ; Add 30h
    mov [bx],al             ; [BX] = AL    
    cmp cx,0                ; Compare with 0
    jne c_loop              ; Jump if not equal
    
    lea dx,hex_out          ; Set address to result msg
    mov ah,9                ; print result
    int 21h
    
    ret
print_hex endp

ins_linefeed proc
    lea dx,linefeed     ; New line print
    mov ah,9
    int 21h
    ret
ins_linefeed endp

end