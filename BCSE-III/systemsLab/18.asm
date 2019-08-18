.model small

.stack 256h

.data

linefeed      db 13, 10, "$"
len           db 8, "$"
nums          db "AXYZPQBR$"
msg1          db " is minimum$"
msg2          db " is maximum$"

.code 	                    ; code segment
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
    mov cl, 1
    mov di, 1
    
nums_loop_lesser:
    inc di
    inc cl
    cmp cl, len
    je init2
    
    mov al, nums[di]
    
    cmp al, dh
    jnl nums_loop_lesser
    mov dh, al    
    jmp nums_loop_lesser

init2:
    mov cl, 1
    mov di, 1
    mov bl, nums[0]
    mov bh, nums[1]

    
nums_loop_greater:
    inc di
    inc cl
    cmp cl, len
    je disp
    
    mov al, nums[di]
    
    cmp al, bh
    jl nums_loop_greater
    mov bh, al    
    jmp nums_loop_greater
    
disp:
    mov ah, 2
    int 21h
    lea dx,msg1
    mov ah, 9
    int 21h
    call ins_linefeed    
    mov dl, bh
    mov ah, 2
    int 21h
    lea dx,msg2
    mov ah, 9
    int 21h

    mov  ax, 4c00h
    int  21h
main endp

ins_linefeed proc
    lea dx,linefeed
    mov ah,9
    int 21h
    ret
ins_linefeed endp

end