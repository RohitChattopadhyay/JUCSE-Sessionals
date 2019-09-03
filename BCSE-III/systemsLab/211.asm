.model small
.stack 256

.data
	msg1 db "Enter the numbers for Insertion Sort (last space): $"
	msg2 db 10,13,"Enter the numbers for Selection sort (last Space): $"
	msg3 db "After Insertion Sort: $"
	msg4 db "After Selection Sort: $"
	space db " $"
	numbers dw ?
	length1 dw ?
	
.code
start:
	mov ax,@data
	mov ds,ax
	mov ah,9
	lea dx,msg1
	int 21h
	mov ax,0
	mov cx,0
	mov si,offset numbers
	call input
	push si
	push cx
	call insertion_sort
	pop cx
	pop si
	mov ah,9
	lea dx,msg3
	int 21h
	call show_numbers
;###########################################################
	mov ah,9
	lea dx,msg2
	int 21h
	mov ax,0
	mov cx,0
	mov si,offset numbers
	call input
	push si
	push cx
	call selection_sort
	pop cx
	pop si
	mov ah,9
	lea dx,msg4
	int 21h
	call show_numbers

	mov ah,4ch
	int 21h

input:
	push ax
	mov ah,1
	int 21h
	mov bl,al
	pop ax
	cmp bl,13
	je return
	cmp bl,32
	je one_number_finished
	sub bl,'0'
	mov bh,0
	push cx
	mov cx,10
	mul cx
	pop cx
	add ax,bx
	jmp input

one_number_finished:
	mov [si],ax
	add si,4
	inc cx
	mov ax,0
	jmp input

insertion_sort:
	cmp cx,1
	jle return
	lea si,numbers
	mov dx,0
	inner_loop1:	inc dx
	cmp dx,cx
	je return
	call address_calc
	mov ax,[di]
	push dx
	inner_loop2:	cmp dx,0
	je all_over
	dec dx
	call address_calc
	mov bx,[di]
	cmp ax,bx
	jl less_found
	call address_calc
	mov [di+4],bx
	jmp inner_loop2
	less_found:	call address_calc
	mov [di+4],ax
	pop dx
	jmp inner_loop1
	all_over:	call address_calc
	mov [di],ax
	pop dx
	jmp inner_loop1

address_calc:
	mov di,si
	add di,dx
	add di,dx
	add di,dx
	add di,dx
	ret

selection_sort:
	cmp cx,1
	jle return
	mov length1,cx
	lea si,numbers
	mov dx,0
	inner_loop11:	cmp dx,length1
	je return
	mov di,si
	mov bx,dx
	inner_loop22:	mov ax,[si]
	mov cx,[di]
	cmp ax,cx
	jl swap
	l0:	inc bx
	cmp bx,length1
	je loop22_end
	add di,4
	jmp inner_loop22
	loop22_end:	inc dx
	add si,4
	jmp inner_loop11

	swap:	mov [si],cx
	mov [di],ax
	jmp l0

show_numbers:
	cmp cx,0
	je return
	sub si,4
	dec cx
	mov ax,[si]
	push cx
	mov cx,0
	call show
	pop cx
	mov ah,9
	lea dx,space
	int 21h
	jmp show_numbers

show:
	push cx
	mov cx,10
	mov dx,0
	div cx
	pop cx
	add cx,1
	add dl,'0'
	push dx
	cmp ax,0
	je reverse
	jmp show

reverse:
	cmp cx,0
	je return
	sub cx,1
	pop dx
	mov ah,2
	int 21h
	jmp reverse

return:
ret

end start

