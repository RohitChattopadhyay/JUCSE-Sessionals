; .MODEL SMALL
; .STACK 256H
; .DATA
; NUM1    DB  10H
; NUM2    DB  31H
; RES     DB  ?

; .CODE
; MAIN PROC
;     MOV AX,@DATA
;     MOV DS,AX
;     MOV AL,NUM1
;     ADD AL,NUM2
;     MOV RES,AL
;     MOV DL,RES
;     MOV AH,02H
;     INT 21H
;     MOV AH,4CH
;     INT 21H
; MAIN ENDP
; END MAIN

.model small

.stack 100

.data

linefeed      db 13, 10, "$"
num1          db 35h, "$"
num2          db 30h, "$"
hex_out       db 0, 0, 0, "H$"

.code 	                    ; code segment

call main

mov  ax,4c00h               ; terminate properly
int  21h  

main proc
    mov ax,@data
    mov ds,ax
    
    mov dl,num1
    add dl,num2
    mov dh,0
    jnc nocarry
    inc dh
nocarry:

    call print_hex
    call wait_for_key
    
    ret   
main endp

print_hex proc
    mov cx,3
c_loop:
    dec cx
    mov ax, dx
    
    shr dx,1
    shr dx,1
    shr dx,1
    shr dx,1
    
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
    lea dx,linefeed
    mov ah,9
    int 21h
    ret
ins_linefeed endp

wait_for_key proc
    mov  ah,7
    int  21h
    ret
wait_for_key endp

end