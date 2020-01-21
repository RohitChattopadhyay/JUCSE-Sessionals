.model small
.stack 64h
.data
	input db 10,0,10 dup(?)
	count db 0
.code
	;reading string
    mov  dx, offset input
    mov  ah, 0Ah
    int  21h 

 ;checking for vowels
    xor  cx, cx            ; Also clears the CX register like `mov cx, 0`
    mov  count, cl         ; Count = 0
    mov  si, offset input+2 
    mov  cl, [si-1]        ; length is 2nd byte
 counting:
    cmp  [si], 'a'
    je   count1 
    cmp  [si], 'e'
    je   count1
    cmp  [si], 'i'
    je   count1
    cmp  [si], 'o'
    je   count1
    cmp  [si], 'u'
    je   count1
    inc  si
    loop counting
    cmp  cl, 0 
    je   exit
 count1:
    inc  count 
    inc  si
    loop counting 
	exit:
	mov dl, count
	mov ah,02h
	int 21h
	mov ah,04ch
	int 21h
end
