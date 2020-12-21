.model small

.stack

.data

linefeed      db 13, 10, "$"
len           db 8, "$"
nums          db "AXYZPQBR$"

.code 	                    ; code segment

call main
mov  ax, 4c00h              ; Exit Program
int  21h  

main proc
    mov ax, @data           ; Set address to data segment
    mov ds, ax
    cmp len, 1              ; Check length of array
    jne not_single_elem     ; if length>1
    mov dl, nums[0]         ; else min max are first element
    mov bl, dl
    jmp disp    
    
not_single_elem:
    mov dl, nums[0]         ; dl = first element 
    mov dh, nums[1]         ; dh = second element
    cmp dl, dh              ; Compare
    jle init                ; jump if less or equal    
    xchg dl, dh             ; exchange dl dh
    
init:
    mov bl, dl              
    mov bh, dh
    mov cl, 1               ; Set Counter
    mov di, 1               ; Set Counter
    
nums_loop:
    inc di                  ; Increment Counter
    inc cl                  ; Increment Counter
    cmp cl, len             ; Compare
    je disp                 ; Jump to display if array traversed
    
    mov al, nums[di]        ; Move current number
    
    cmp al, dh              ; Compare
    jl first_greater        ; Jump if less
    mov dl, dh
    mov dh, al
    
    jmp second_greater      ; Unconditional jump
    
first_greater:
    cmp al, dl              ; Compare al, dl
    jl second_greater       ; Jump if less
    mov dl, al              ; DL = AL
    
second_greater:
    cmp al, bl              ; Compare al, bl
    jg first_lesser         ; Jump if greater
    mov bh, bl              ; BH = BL
    mov bl, al              ; BL = AL    
    jmp second_lesser       ; Unconditional Jump
    
first_lesser:
    cmp al, bh              ; Compare al, bh
    jg second_lesser        ; jump if greater
    mov bh, al              ; BH = AL
    
second_lesser:
    jmp nums_loop           : Unconditional Jump
    
disp:
    mov ah, 2   ; Print result
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