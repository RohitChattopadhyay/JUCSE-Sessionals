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
    
    and ax,0fh
    
    mov bx, offset hex_out
    add bx,cx
    
    cmp ax,0ah
    jl set_digit
    add al,27h

set_digit:
    add al,30h
    mov [bx],al
    
    cmp cx,0
    jne c_loop
    
    lea dx,hex_out
    mov ah,9
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