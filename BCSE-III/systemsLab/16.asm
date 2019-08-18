; Show input charachter
.model small
.stack 256h
.data
msg1    db 'Enter a charachter: $'
msg2    db 0dh,0ah,'Given charachter: $'

.code
main proc
    mov ax, @data   ; Initialize ds to address
    mov ds, ax      ; of data segment
    lea dx, msg1    ; Get address of message
    mov ah, 9       ; Display string function
    int 21h         ; Display call
    mov ah, 1       ; Read char function
    int 21h         ; Read call
    mov bl, al      ; Store value from accumulator
    lea dx, msg2    ; Get address of message
    mov ah, 9       ; Display string function
    int 21h         ; Call display
    mov ah, 2       ; Write charachter to stdout
    mov dl, bl      ; Store value in dl
    int 21h         ; Call display
    mov ah, 4ch     ; Exit program
    int 21h         
main endp
end main