; Find Min Max of an Array
.model small
.stack 256h
.data
linefeed      db 13, 10, "$"
len           db 8, "$"
nums          db "AXYZPQBR$"
msg1          db " is minimum$"
msg2          db " is maximum$"

.code
main proc
    mov ax, @data           
    mov ds, ax              ; Set address of data segment    
    cmp len, 1              ; Length check of array
    jne not_single_elem     ; Jump if length >1
    mov dl, nums[0]         ; Move first element
    mov bl, dl              ; BL = DL
    jmp disp                ; Unconditional JUMP
    
not_single_elem:
    mov dl, nums[0]         ; Get first element
    mov dh, nums[1]         ; Get second element
    cmp dl, dh              ; Compare
    jle init                ; Jump is less or equal    
    xchg dl, dh             ; Exchange DL,DH
    
init:                       
    mov cl, 1               ; Set counter
    mov di, 1               ; Set counter
    
nums_loop_lesser:
    inc di                  ; Increment Counter
    inc cl                  ; Increment Counter
    cmp cl, len             ; Compare with length
    je init2                ; Go to minimum finding loop if equal    
    mov al, nums[di]        ; Get current element    
    cmp al, dh              ; Compare with max
    jnl nums_loop_lesser    ; Jump if not less
    mov dh, al              ; Move current to dh
    jmp nums_loop_lesser    ; Unconditional Jump

init2:
    mov cl, 1               ; Set counter for minimum
    mov di, 1               ; Set counter for minimum
    mov bl, nums[0]         ; Get First element
    mov bh, nums[1]         ; Get Second element
    
nums_loop_greater:
    inc di                  ; Increment Counter
    inc cl                  ; Increment Counter
    cmp cl, len             ; Compare with length
    je disp                 ; Jump to result display if equal    

    mov al, nums[di]        ; Get current element
    cmp al, bh              ; Compare al and bh
    jl nums_loop_greater    ; Jump if less
    mov bh, al              ; BH = AL
    jmp nums_loop_greater   ; Unconditional Jump
    
disp:
    mov ah, 2               ; Result Display
    int 21h
    lea dx,msg1             ; Message print
    mov ah, 9
    int 21h
    call ins_linefeed       ; New line print
    mov dl, bh
    mov ah, 2
    int 21h
    lea dx,msg2             ; Message print
    mov ah, 9
    int 21h

    mov  ax, 4c00h          ; Exit program
    int  21h
main endp

ins_linefeed proc
    lea dx,linefeed         ; Subroutine for printing new line
    mov ah,9
    int 21h
    ret
ins_linefeed endp

end