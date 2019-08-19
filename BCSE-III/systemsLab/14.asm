.model small

.stack

.data

linefeed      db 13, 10, "$"
len           db 8, "$"
nums          db "AXYZPQBR$"

.code 	                    ; code segment

call main
mov  ax, 4c00h
int  21h  

main proc
    mov ax, @data
    mov ds, ax
    
    cmp len, 1
    jne not_single_elem
    mov dl, nums[0]
    mov bl, dl
    jmp disp
    
not_single_elem:
    mov dl, nums[0]
    mov dh, nums[1]

    cmp dl, dh
    jle init
    
    xchg dl, dh
    
init:
    mov bl, dl
    mov bh, dh
    mov cl, 1
    mov di, 1
    
nums_loop:
    inc di
    inc cl
    cmp cl, len
    je disp
    
    mov al, nums[di]
    
    cmp al, dh
    jl first_greater
    mov dl, dh
    mov dh, al
    
    jmp second_greater
    
first_greater:
    cmp al, dl
    jl second_greater
    mov dl, al
    
second_greater:
    cmp al, bl
    jg first_lesser
    mov bh, bl
    mov bl, al
    
    jmp second_lesser
    
first_lesser:
    cmp al, bh
    jg second_lesser
    mov bh, al
    
second_lesser:
    jmp nums_loop
    
disp:
    mov ah, 2
    int 21h
    
    call ins_linefeed
    
    mov dl, bh
    mov ah, 2
    int 21h    
    ret
main endp

ins_linefeed proc
    lea dx,linefeed ; New Line printer
    mov ah,9
    int 21h
    ret
ins_linefeed endp
end