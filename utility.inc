.model small
.stack 100h
.code


;Title page proc, it just calls the letters macro which consists of all the info for the title page
titlepage proc

letters

ret
titlepage endp

;This is the process for the second page
rulepage proc	


mov ax, 12h ;Clears the screen
int 10h
mov dl, 32 ;setting coords
mov dh, 2
mov ah, 02
int 10h

;strings are printed

mov ah, 09
mov dx, offset heading
int 21h
mov ah, 09
mov dx, offset spaces
int 21h
mov ah, 09
mov dx, offset rules
int 21h

mov dl, 0
mov dh, 5
mov ah, 02h
int 10h

mov ah, 09h
mov dx, offset welcome
int 21h

mov ah, 09h
mov dx, offset naam
int 21h

mov ah, 02h
mov dl, 30
mov dh, 28
int 10h

mov dx, offset msg2
mov ah, 09h
int 21h

;The next 5 diamond calls are for the designing of the rule page only for aesthetic purposes
mov ah, 0ch
mov al, 0bh
mov cx, 87
mov dx, 360
call diamond

mov cx, 187
mov dx, 360
call diamond

mov cx, 287
mov dx, 360
call diamond



mov cx, 387
mov dx, 360
call diamond


mov cx, 487
mov dx, 360
call diamond




ret
rulepage endp

calchigh macro
mov bx, s1
mov cx, s2
mov dx, s3

.if (bx > cx && bx > dx) 
mov highest, bx

.elseif (cx > bx && cx > dx) 
mov highest, cx

.elseif (dx > bx && dx > cx)
mov highest, dx

.endif

endm

writehigh proc
mov ah, 40h			
mov bx, fhandle
mov cx, lengthof endl
mov dx, offset endl
int 21h

mov ah, 40h			
mov bx, fhandle
mov cx, lengthof hs
mov dx, offset hs
int 21h

mov ax, highest			
mov dcount, 0
pushing:
mov dx,0
mov bx,10
div bx
push dx

inc dcount
cmp ax, 0
jne pushing

disp:
cmp dcount,0
je close
dec dcount
pop bx
add bx, 48
mov ftemp, bx

mov ah,40h
mov bx,fhandle
mov cx, 1
mov dx, offset ftemp
int 21h

jmp disp
close:
ret

writehigh endp



writescore proc
mov ax, score			
mov dcount, 0
pushing:
mov dx,0
mov bx,10
div bx
push dx

inc dcount
cmp ax, 0
jne pushing

disp:
cmp dcount,0
je close
dec dcount
pop bx
add bx, 48
mov ftemp, bx

mov ah,40h
mov bx,fhandle
mov cx, 1
mov dx, offset ftemp
int 21h

jmp disp
close:
ret

writescore endp

;The process responsible for setting the arrx and arry 

settingarray proc
;127,182,237,292,347,402,457, these are the x coordinate values
;47,102,157,212,267,322,377, these are the y coordinate values. We will use these values to fill the arrays


; filling the arrayx with the x coords of the board
mov si, offset arrx 
mov cx, 7
mov bx, 127



.repeat
mov [si], bx
add si, 2 ;traversing the word type arrx
add bx, 55 ;Adding 55 to the previous bx value and storing in element. 55 because every box in the board is 55x55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)


; filling arry with y coords, same procedure as arrx but with different values
mov si, offset arry
mov cx, 7
mov bx, 47

.repeat
mov [si], bx
dec cx
add si, 2
.until(cx==0)

mov cx, 7
mov bx, 102

.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)

mov cx, 7
mov bx, 157

.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)

mov cx, 7
mov bx, 212

.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)

mov cx, 7
mov bx, 267

.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)

mov cx, 7
mov bx, 322

.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)

mov cx, 7
mov bx, 377
.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)
;End of filling y coords

ret
settingarray endp

fillboard proc
;127,182,237,292,347,402,457
;47,102,157,212,267,322,377




;FIRST LINE//////////
mov si, offset arrx ;setting the offset of arrx in si
mov bx, 0 ;setting 0 in bx, to which 2 will be added after every candycall to traverse the arry


mov cx, [si]
mov dx, arry[bx]
call delaycandy ;a delay is called which is needed to randomise the candies placed, Otherwise all candies placed will have the same type
call candycall ;this function makes a randomvalue and also sets a candy according to the value

add si, 2 ;traversing arrx
add bx, 2 ;traversing arry

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;SECOND LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;THIRD LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;FOURTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;FIFTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;SIXTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;SEVENTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall


ret
fillboard endp


settingarray2 proc
;127,182,237,292,347,402,457, these are the x coordinate values
;47,102,157,212,267,322,377, these are the y coordinate values. We will use these values to fill the arrays


; filling the arrayx with the x coords of the board
mov si, offset arrx 
mov cx, 7
mov bx, 127



.repeat
mov [si], bx
add si, 2 ;traversing the word type arrx
add bx, 55 ;Adding 55 to the previous bx value and storing in element. 55 because every box in the board is 55x55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)

mov cx, 7
mov bx, 127

.repeat
mov [si], bx
add si, 2
add bx, 55
dec cx
.until(cx==0)


; filling arry with y coords, same procedure as arrx but with different values
mov si, offset arry
mov cx, 7
mov bx, 47

.repeat
mov [si], bx
dec cx
add si, 2
.until(cx==0)

mov cx, 7
mov bx, 102

.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)

mov cx, 7
mov bx, 157

.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)

mov cx, 7
mov bx, 212

.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)

mov cx, 7
mov bx, 267

.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)

mov cx, 7
mov bx, 322

.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)

mov cx, 7
mov bx, 377
.repeat
mov [si], bx
add si, 2
dec cx
.until(cx==0)
;End of filling y coords

ret
settingarray2 endp




fillboard2 proc


;127,182,237,292,347,402,457
;47,102,157,212,267,322,377




;FIRST LINE//////////
mov si, offset arrx ;setting the offset of arrx in si
mov bx, 0 ;setting 0 in bx, to which 2 will be added after every candycall to traverse the arry


mov cx, [si]
mov dx, arry[bx]
call delaycandy ;a delay is called which is needed to randomise the candies placed, Otherwise all candies placed will have the same type
call candycall2 ;this function makes a randomvalue and also sets a candy according to the value

add si, 2 ;traversing arrx
add bx, 2 ;traversing arry

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

;SECOND LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

;THIRD LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;FOURTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

;FIFTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;SIXTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

;SEVENTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2


ret
fillboard2 endp




;Placing strings on the board page

string proc


mov al, 01h
mov cx, 0001h
int 10h


mov ah, 02h
mov dh, 5
mov dl, 2
int 10h





mov dx, offset naam
mov ah, 09h
int 21h

mov ah, 02h
mov dh, 7
mov dl, 2
int 10h

mov dx, offset scorestr
mov ah, 09h
int 21h


mov ah, 02h
mov dh, 28
mov dl, 0
int 10h

mov dx, offset msg3
mov ah, 09h
int 21h






mov ah, 02h
mov dh, 11
mov dl, 2
int 10h

mov dx, offset msg5
mov ah, 09h
int 21h

mov ah, 02h
mov dh, 28
mov dl, 70
int 10h

mov dx, offset msg4
mov ah, 09h
int 21h


mov ah, 02h
mov dh, 1
mov dl, 32
int 10h

mov dx, offset targetstr
mov ah, 09h
int 21h

mov ah, 02h
mov dh, 28
mov dl, 37
int 10h

mov dx, offset level1str
mov ah, 09h
int 21h


ret
string endp

string2 proc


mov al, 01h
mov cx, 0001h
int 10h


mov ah, 02h
mov dh, 5
mov dl, 2
int 10h


mov dx, offset naam
mov ah, 09h
int 21h

mov ah, 02h
mov dh, 7
mov dl, 2
int 10h

mov dx, offset scorestr
mov ah, 09h
int 21h


mov ah, 02h
mov dh, 28
mov dl, 0
int 10h

mov dx, offset msg3
mov ah, 09h
int 21h






mov ah, 02h
mov dh, 11
mov dl, 2
int 10h

mov dx, offset msg5
mov ah, 09h
int 21h

mov ah, 02h
mov dh, 28
mov dl, 70
int 10h

mov dx, offset msg4
mov ah, 09h
int 21h


mov ah, 02h
mov dh, 1
mov dl, 32
int 10h

mov dx, offset targetstr
mov ah, 09h
int 21h

mov ah, 02h
mov dh, 28
mov dl, 37
int 10h

mov dx, offset level2str
mov ah, 09h
int 21h




ret
string2 endp

string3 proc


mov al, 01h
mov cx, 0001h
int 10h


mov ah, 02h
mov dh, 5
mov dl, 2
int 10h


mov dx, offset naam
mov ah, 09h
int 21h

mov ah, 02h
mov dh, 7
mov dl, 2
int 10h

mov dx, offset scorestr
mov ah, 09h
int 21h


mov ah, 02h
mov dh, 28
mov dl, 0
int 10h

mov dx, offset msg3
mov ah, 09h
int 21h






mov ah, 02h
mov dh, 11
mov dl, 2
int 10h

mov dx, offset msg5
mov ah, 09h
int 21h

mov ah, 02h
mov dh, 28
mov dl, 70
int 10h

mov dx, offset msg4
mov ah, 09h
int 21h


mov ah, 02h
mov dh, 1
mov dl, 32
int 10h

mov dx, offset targetstr
mov ah, 09h
int 21h

mov ah, 02h
mov dh, 28
mov dl, 37
int 10h

mov dx, offset level3str
mov ah, 09h
int 21h




ret
string3 endp

;this is a randomcall proc, and it uses the system time, a random value between 0 and 9 is stored in the variable "rand" and returned
randomcall proc
mov ah, 0
int 1ah

mov ax, dx
mov dx, 0
mov bx, 10
div bx

mov rand, dl
ret 
randomcall endp

;This is the function which calls the candies, these registers are passed to it and stored in variables so they dont lose their values after the randomcall proc is called,

candycall proc uses ax bx cx dx si
mov cxval, cx
mov s, si
mov y, dx
mov b, bx
mov a, ax


call randomcall

;values are restored back in the registers as they were before the function was called
mov ax, a
mov si, s
mov bx, b
mov cx, cxval
mov dx, y


;Since rand has stored in it, any random value between 0 and 9, here we will use conditions to see what candy should be placed
;For example if rand has 0 stored in it, then a candy called "play" is called, if rand has 2 then "diamond" is called and so on
.if(rand==0)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 3
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 3
call play
.endif

.if(rand==1)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 2
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 2
call diamond
.endif

.if(rand==2)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 1
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 1
call yrden
.endif

.if(rand==3)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 1
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 1
call yrden
.endif

.if(rand==4)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 4
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 4
call gps
.endif

.if(rand==5)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 1
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 1
call yrden
.endif

.if(rand==6)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 5
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 5
call bomb
.endif

.if(rand==7)
mov bx, 0

	.if(mainarr[bx]==0)
	mov mainarr[bx], 2
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 2


call diamond
.endif

.if(rand==8)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 4
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 4
call gps
.endif

.if(rand==9)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 3
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 3
call play
.endif


mov ax, a
mov si, s
mov bx, b
mov cx, cxval
mov dx, y



ret
candycall endp


candycall2 proc uses ax bx cx dx si
mov cxval, cx
mov s, si
mov y, dx
mov b, bx
mov a, ax


call randomcall

;values are restored back in the registers as they were before the function was called
mov ax, a
mov si, s
mov bx, b
mov cx, cxval
mov dx, y


;Since rand has stored in it, any random value between 0 and 9, here we will use conditions to see what candy should be placed
;For example if rand has 0 stored in it, then a candy called "play" is called, if rand has 2 then "diamond" is called and so on
.if(rand==0)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 3
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 3
;call play
.endif

.if(rand==1)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 2
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 2
;call diamond
.endif

.if(rand==2)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 1
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 1
;call yrden
.endif

.if(rand==3)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 1
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 1
;call yrden
.endif

.if(rand==4)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 4
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 4
;call gps
.endif

.if(rand==5)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 1
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 1
;call yrden
.endif

.if(rand==6)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 5
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 5
;call bomb
.endif

.if(rand==7)
mov bx, 0

	.if(mainarr[bx]==0)
	mov mainarr[bx], 2
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 2


;call diamond
.endif

.if(rand==8)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 4
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 4
;call gps
.endif

.if(rand==9)
mov bx, 0
	.if(mainarr[bx]==0)
	mov mainarr[bx], 3
	.else
		.repeat
		add bx, 2
		.until(bx==98 || mainarr[bx]==0)
	.endif
mov mainarr[bx], 3
;call play
.endif


mov ax, a
mov si, s
mov bx, b
mov cx, cxval
mov dx, y



ret
candycall2 endp


;This function is exactly the same as the delay function, only difference is that the delay factor is reduced in this function to prevent candies being placed too slowly
delaycandy proc

push ax
push bx
push cx
push dx

mov cx,1000
D1:
mov bx,90; Delay factor 
D2:
dec bx
jnz D2
loop D1

pop dx
pop cx
pop bx
pop ax

ret
delaycandy endp

arrtokens proc

mov dx, 10
mov ah, 02h
int 21h

mov bx, 0
.repeat
mov dx, mainarr[bx]
add dx, 48
mov ah, 02h
int 21h
add bx, 2
.until(bx==98)

ret
arrtokens endp

;////////UPDATING
updating proc uses bx


;FOR FIRST CANDY
mov swapindex1, 0

.repeat

mov ax, 01h
int 33h

mov ax,07h
mov cx, 127
mov dx, 512
int 33h


mov ax,08h
mov cx, 47
mov dx, 432
int 33h

mov ax, 03h ;getting mouse info
int 33h
.until(bx>0)

;mov ax, 0h
;int 16h

;cmp ah, 01
;je exitfunc

;127,182,237,292,347,402,457
;47,102,157,212,267,322,377

mov ah, 0ch ;setting pixel for which the box that is selected will be highlighted
mov al, 04h


	.repeat
	dec cx
	.until(cx==127 || cx==182 || cx==237 || cx==292 || cx==347 || cx==402 || cx==457) ; This loop is for moving the pixel to the left until it matches x coords of the top left pixel



	mov x1, cx ;stores that x coord in x1

	.repeat
	dec dx
	.until(dx==47 || dx==102 || dx==157 || dx==212 || dx==267 || dx==322 || dx==377)


	
	mov y1, dx

	add x1, 55 ; box highlighting
	.repeat
	inc cx
	int 10h
	.until(cx==x1)


	add y1, 55
	.repeat
	inc dx
	int 10h
	.until(dx==y1)

	sub x1, 55
	.repeat
	dec cx
	int 10h
	.until(cx==x1)


	sub y1, 55
	.repeat
	dec dx
	int 10h
	.until(dx==y1)



;//Finding out the index of the first candy for swapping
mov bx, 0
mov s, ax
mov ax, x1

.repeat
	
	.if(arrx[bx]==ax)
	mov swapindex1, 0
	.else
	add bx, 2
	add swapindex1, 2
	.endif

.until(arrx[bx]==ax)

mov bx, 0
mov ax, y1

.repeat
	
	.if(arry[bx]==ax)
	add swapindex1, 0
	.else
	add bx, 2
	add swapindex1, 2
	.endif

.until(arry[bx]==ax)



;REPEATING SAME PROCESS FOR 2ND CANDY



mov ax, s


exitfunc:
ret
updating endp


;////////game start/////////
startgame proc
mov si, offset arrx
mov bx, 0


.repeat

mov cx, [si]
mov dx, arry[bx]

.if(mainarr[bx]==1)
call yrden
.endif

.if(mainarr[bx]==2)
call diamond
.endif

.if(mainarr[bx]==3)
call play
.endif

.if(mainarr[bx]==4)
call gps
.endif

.if(mainarr[bx]==5)
call bomb
.endif

add si, 2
add bx, 2
.until(bx==98)




ret
startgame endp

board proc
mov ax, 12h
int 10h

mov ah, 0ch ;sets pixel
mov al, 0fh ;sets pixel color
mov bh, 0 ;sets page no
mov cx, 127 ;x-axis coordinate
mov dx, 47;y-axis coordinate

;This is the board drawing part

.repeat
int 10h ;prints a pixel
inc cx ;increases the x-coord of the next pixel
.until (cx==512)

.repeat
int 10h
inc dx ;increases the y-coord of the next pixel
.until (dx==432)

.repeat
int 10h
dec cx
.until (cx==127)

.repeat
int 10h
dec dx
.until (dx==47)

mov cx, 182
.repeat ;print vertical lines
mov dx, 47
.repeat
int 10h
inc dx
.until (dx==432)
add cx, 55
.until (cx == 512)

mov dx, 47
.repeat
add dx, 55 ;prints horizontal lines
mov cx, 127
.repeat
int 10h
inc cx
.until (cx == 512)
.until (dx == 432)

ret
board endp

delaygame proc

push ax
push bx
push cx
push dx

mov cx,1000
D1:
mov bx,5000; Delay factor 
D2:
dec bx
jnz D2
loop D1

pop dx
pop cx
pop bx
pop ax

ret
delaygame endp


updating2 proc uses bx


mov bx, 0
mov swapindex2, 0


.repeat
mov ax, 01h
int 33h

mov ax,07h
mov cx, 127
mov dx, 512
int 33h


mov ax,08h
mov cx, 47
mov dx, 432
int 33h


mov ax, 03h ;getting mouse info
int 33h
.until(bx>0)

;call delay


;mov ax, 0h
;int 16h

;cmp ah, 01
;je exitfunc

;127,182,237,292,347,402,457
;47,102,157,212,267,322,377

mov ah, 0ch ;setting pixel for which the box that is selected will be highlighted
mov al, 0bh

.if(bx>0) ;If a mouse is clicked
	.repeat
	dec cx
	.until(cx==127 || cx==182 || cx==237 || cx==292 || cx==347 || cx==402 || cx==457) ; This loop is for moving the pixel to the left until it matches x coords of the top left pixel



	mov x2, cx ;stores that x coord in x1

	.repeat
	dec dx
	.until(dx==47 || dx==102 || dx==157 || dx==212 || dx==267 || dx==322 || dx==377)

	mov y2, dx

	add x2, 55 ; box highlighting
	.repeat
	inc cx
	int 10h
	.until(cx==x2)


	add y2, 55
	.repeat
	inc dx
	int 10h
	.until(dx==y2)

	sub x2, 55
	.repeat
	dec cx
	int 10h
	.until(cx==x2)


	sub y2, 55
	.repeat
	dec dx
	int 10h
	.until(dx==y2)

.endif


;//Finding out the index of the second candy for swapping
mov bx, 0
mov ax, x2

.repeat
	
	.if(arrx[bx]==ax)
	mov swapindex2, 0
	.else
	add bx, 2
	add swapindex2, 2
	.endif

.until(arrx[bx]==ax)

mov bx, 0
mov ax, y2

.repeat
	
	.if(arry[bx]==ax)
	add swapindex2, 0
	.else
	add bx, 2
	add swapindex2, 2
	.endif

.until(arry[bx]==ax)


mov bx, swapindex1
.if(mainarr[bx]==5)
mov bombbool, 1

.endif

mov bx, swapindex2
.if(mainarr[bx]==5)
mov bombbool, 1
.endif



ret
updating2 endp

swapping proc uses ax bx

mov bx, swapindex1
mov ax, mainarr[bx]

mov temp, ax

mov bx, swapindex2
mov ax, mainarr[bx]

mov temp2, ax

mov bx, swapindex1
mov ax, temp2

mov mainarr[bx], ax

mov bx, swapindex2
mov ax, temp

mov mainarr[bx], ax

mov swapbool, 1

ret
swapping endp


;///CRUSHING
crushing proc uses ax bx si cx dx


.if(bombbool==1)
	mov crushingbool, 1

	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset bombstr
	mov ah, 09h
	int 21h 

	mov bx, swapindex1
	mov mainarr[bx], 6

	mov bx, swapindex2
	mov ax, mainarr[bx]
	mov bx, 0

	.while(bx<=98)
		.if(mainarr[bx]==ax)
		mov mainarr[bx], 6
		add score, 100
		.endif
		add bx, 2
	.endw
	mov bombbool, 0
.endif


;///////////////////ROWS PART////////////////
;for first row

mov si, offset mainarr
mov bx, 2




.while(bx<=12)


mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 2
		mov cx, bx
		add bx, 2
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx

	

	
		.repeat
		mov mainarr[bx], 6
		add bx, 2
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 2
add si, 2


.endw


;///For second row


mov si, offset mainarr
add si, 14
mov bx, 16


.while(bx<=26)


mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 2
		mov cx, bx
		add bx, 2
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 2
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 2
add si, 2


.endw

;For third row


mov si, offset mainarr
add si, 28
mov bx, 30


.while(bx<=40)


mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 2
		mov cx, bx
		add bx, 2
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 2
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 2
add si, 2


.endw


;For fourth row


mov si, offset mainarr
add si, 42
mov bx, 44


.while(bx<=54)


mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 2
		mov cx, bx
		add bx, 2
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 2
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 2
add si, 2


.endw

;For fifth row

mov si, offset mainarr
add si, 56
mov bx, 58


.while(bx<=68)


mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 2
		mov cx, bx
		add bx, 2
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 2
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 2
add si, 2


.endw

;For sixth row

mov si, offset mainarr
add si, 70
mov bx, 72


.while(bx<=82)


mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 2
		mov cx, bx
		add bx, 2
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 2
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 2
add si, 2


.endw

;For seventh row

mov si, offset mainarr
add si, 84
mov bx, 86


.while(bx<=98)


mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 2
		mov cx, bx
		add bx, 2
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 2
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 2
add si, 2


.endw


;//////////////Columns part/////////////////


mov si, offset mainarr
mov bx, 14


.while(bx<=98)

mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6 && ax!=0)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 14
		mov cx, bx
		add bx, 14
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 14
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 14
add si, 14


.endw

;Second Column

mov si, offset mainarr
add si, 2
mov bx, 16


.while(bx<=100)

mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6 && ax!=0)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 14
		mov cx, bx
		add bx, 14
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 14
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 14
add si, 14


.endw

;Third Column

mov si, offset mainarr
add si, 4
mov bx, 18


.while(bx<=102)

mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6  && ax!=0)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 14
		mov cx, bx
		add bx, 14
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 14
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 14
add si, 14


.endw

;Fourth Column

mov si, offset mainarr
add si, 6
mov bx, 20


.while(bx<=104)

mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6 && ax!=0)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 14
		mov cx, bx
		add bx, 14
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 14
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 14
add si, 14


.endw

;Fifth Column

mov si, offset mainarr
add si, 8
mov bx, 22


.while(bx<=106)

mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6 && ax!=0)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 14
		mov cx, bx
		add bx, 14
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 14
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 14
add si, 14


.endw

;sixth Column

mov si, offset mainarr
add si, 10
mov bx, 24


.while(bx<=108)

mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6 && ax!=0)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 14
		mov cx, bx
		add bx, 14
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h


	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 14
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 14
add si, 14


.endw

;seventh Column

mov si, offset mainarr
add si, 12
mov bx, 26


.while(bx<=110)

mov ax, mainarr[bx]
	
	.if([si]==ax && ax!=6 && ax!=0)
	add crushcount, 2
		
		.if(crushcount==2)
		sub bx, 14
		mov cx, bx
		add bx, 14
		.endif

	.else
	
	.if(crushcount>2)
	mov crushingbool, 1
	mov ah, 02h
	mov dl, 67
	mov dh, 12
	int 10h

	mov dx, offset crushingstr
	mov ah, 09h
	int 21h

	mov dx, bx
	mov bx, cx
	
		.repeat
		mov mainarr[bx], 6
		add bx, 14
		add score, 100
		.until(bx==dx)

	.endif
	mov crushcount,0

	.endif

add bx, 14
add si, 14


.endw





ret 
crushing endp


displaynum proc uses cx
	
 mov cx, score

 mov ah, 02h
 mov dh, 9
 mov dl, 2
 int 10h

 Pushing:
 mov ax, score
 mov dx,0
 mov bx,10
 div bx    
 push dx
 
 mov score,ax
 inc digitCount
 cmp ax,0
 jne Pushing
 
 display:
 cmp digitCount,0
 je exit
 dec digitCount 
 pop dx
 add dx,48
 mov ah,02h
 int 21h
 jmp display

 exit:
 mov score, cx
ret
displaynum endp

displaymoves proc uses cx
	
 mov cx, moves

 mov ah, 02h
 mov dh, 12
 mov dl, 2
 int 10h

 Pushing:
 mov ax, moves
 mov dx,0
 mov bx,10
 div bx    
 push dx
 
 mov moves,ax
 inc digitCount
 cmp ax,0
 jne Pushing
 
 display:
 cmp digitCount,0
 je exit
 dec digitCount 
 pop dx
 add dx,48
 mov ah,02h
 int 21h
 jmp display

 exit:
 mov moves, cx
ret
displaymoves endp



filling proc uses si dx bx cx


;//////////////FIRST COLUMN FILLING
mov bx, 84
mov r, 8

.repeat
	mov s, 8

	.repeat
		mov bx, 84

		.repeat

			.if(mainarr[bx]==6)
			sub bx, 14
			mov ax, mainarr[bx]
			mov mainarr[bx], 6
			add bx, 14
			mov mainarr[bx], ax
			.endif

		sub bx, 14
		.until(bx==0)
		dec s
	.until(s==0)

	.if(mainarr[0]==6)
	call delaycandy
	call randomcall
		.if(rand==0)
		mov mainarr[0], 1
		.endif

		.if(rand==1)
		mov mainarr[0], 2
		.endif

		.if(rand==2)
		mov mainarr[0], 3
		.endif

		.if(rand==3)
		mov mainarr[0], 4
		.endif

		.if(rand==4)
		mov mainarr[0], 3
		.endif

		.if(rand==5)
		mov mainarr[0], 4
		.endif

		.if(rand==6)
		mov mainarr[0], 3
		.endif

		.if(rand==7)
		mov mainarr[0], 2
		.endif

		.if(rand==8)
		mov mainarr[0], 1
		.endif

		.if(rand==9)
		mov mainarr[0], 1
		.endif

		

	.endif
dec r
.until(r==0)

;/////SECOND COLUMN FILLING

mov bx, 86
mov r, 8

.repeat
	mov s, 8

	.repeat
		mov bx, 86

		.repeat

			.if(mainarr[bx]==6)
			sub bx, 14
			mov ax, mainarr[bx]
			mov mainarr[bx], 6
			add bx, 14
			mov mainarr[bx], ax
			.endif

		sub bx, 14
		.until(bx==2)
		dec s
	.until(s==0)

	.if(mainarr[2]==6)
	call delaycandy
	call randomcall
		.if(rand==0)
		mov mainarr[2], 1
		.endif

		.if(rand==1)
		mov mainarr[2], 2
		.endif

		.if(rand==2)
		mov mainarr[2], 3
		.endif

		.if(rand==3)
		mov mainarr[2], 4
		.endif

		.if(rand==4)
		mov mainarr[2], 3
		.endif

		.if(rand==5)
		mov mainarr[2], 4
		.endif

		.if(rand==6)
		mov mainarr[2], 3
		.endif

		.if(rand==7)
		mov mainarr[2], 2
		.endif
		
		.if(rand==8)
		mov mainarr[2], 1
		.endif

		.if(rand==9)
		mov mainarr[2], 1
		.endif

	.endif
dec r
.until(r==0)

;//////////Third column filling
mov bx, 88
mov r, 8

.repeat
	mov s, 8

	.repeat
		mov bx, 88

		.repeat

			.if(mainarr[bx]==6)
			sub bx, 14
			mov ax, mainarr[bx]
			mov mainarr[bx], 6
			add bx, 14
			mov mainarr[bx], ax
			.endif

		sub bx, 14
		.until(bx==4)
		dec s
	.until(s==0)

	.if(mainarr[4]==6)
	call delaycandy
	call randomcall
		.if(rand==0)
		mov mainarr[4], 1
		.endif

		.if(rand==1)
		mov mainarr[4], 2
		.endif

		.if(rand==2)
		mov mainarr[4], 3
		.endif

		.if(rand==3)
		mov mainarr[4], 4
		.endif

		.if(rand==4)
		mov mainarr[4], 3
		.endif

		.if(rand==5)
		mov mainarr[4], 4
		.endif

		.if(rand==6)
		mov mainarr[4], 3
		.endif

		.if(rand==7)
		mov mainarr[4], 2
		.endif

		.if(rand==8)
		mov mainarr[4], 2
		.endif


		.if(rand==9)
		mov mainarr[4], 1
		.endif

		
	.endif
dec r
.until(r==0)

;///////////FOURTH COLUMN FILLING

mov bx, 90
mov r, 8

.repeat
	mov s, 8

	.repeat
		mov bx, 90

		.repeat

			.if(mainarr[bx]==6)
			sub bx, 14
			mov ax, mainarr[bx]
			mov mainarr[bx], 6
			add bx, 14
			mov mainarr[bx], ax
			.endif

		sub bx, 14
		.until(bx==6)
		dec s
	.until(s==0)

	.if(mainarr[6]==6)
	call delaycandy
	call randomcall
		.if(rand==0)
		mov mainarr[6], 1
		.endif

		.if(rand==1)
		mov mainarr[6], 2
		.endif

		.if(rand==2)
		mov mainarr[6], 3
		.endif

		.if(rand==3)
		mov mainarr[6], 4
		.endif

		.if(rand==4)
		mov mainarr[6], 3
		.endif

		.if(rand==5)
		mov mainarr[6], 4
		.endif

		.if(rand==6)
		mov mainarr[6], 3
		.endif

		.if(rand==7)
		mov mainarr[6], 2
		.endif

		.if(rand==8)
		mov mainarr[6], 1
		.endif

		.if(rand==9)
		mov mainarr[6], 1
		.endif

		

	.endif
dec r
.until(r==0)

;/////////////FIFTH COLUMN FILLING

mov bx, 92
mov r, 8

.repeat
	mov s, 8

	.repeat
		mov bx, 92

		.repeat

			.if(mainarr[bx]==6)
			sub bx, 14
			mov ax, mainarr[bx]
			mov mainarr[bx], 6
			add bx, 14
			mov mainarr[bx], ax
			.endif

		sub bx, 14
		.until(bx==8)
		dec s
	.until(s==0)

	.if(mainarr[8]==6)
	call delaycandy
	call randomcall
		.if(rand==0)
		mov mainarr[8], 1
		.endif

		.if(rand==1)
		mov mainarr[8], 2
		.endif

		.if(rand==2)
		mov mainarr[8], 3
		.endif

		.if(rand==3)
		mov mainarr[8], 4
		.endif

		.if(rand==4)
		mov mainarr[8], 3
		.endif

		.if(rand==5)
		mov mainarr[8], 4
		.endif

		.if(rand==6)
		mov mainarr[8], 3
		.endif

		.if(rand==7)
		mov mainarr[8], 2
		.endif

		.if(rand==8)
		mov mainarr[8], 2
		.endif

		.if(rand==9)
		mov mainarr[8], 1
		.endif

		

	.endif
dec r
.until(r==0)

;////////////////SIXTH COLUMN FILLING

mov bx, 94
mov r, 8

.repeat
	mov s, 8

	.repeat
		mov bx, 94

		.repeat

			.if(mainarr[bx]==6)
			sub bx, 14
			mov ax, mainarr[bx]
			mov mainarr[bx], 6
			add bx, 14
			mov mainarr[bx], ax
			.endif

		sub bx, 14
		.until(bx==10)
		dec s
	.until(s==0)

	.if(mainarr[10]==6)
	call delaycandy
	call randomcall
		.if(rand==0)
		mov mainarr[10], 1
		.endif

		.if(rand==1)
		mov mainarr[10], 2
		.endif

		.if(rand==2)
		mov mainarr[10], 3
		.endif

		.if(rand==3)
		mov mainarr[10], 4
		.endif

		.if(rand==4)
		mov mainarr[10], 3
		.endif

		.if(rand==5)
		mov mainarr[10], 4
		.endif

		.if(rand==6)
		mov mainarr[10], 3
		.endif

		.if(rand==7)
		mov mainarr[10], 2
		.endif

		.if(rand==8)
		mov mainarr[10], 1
		.endif

		.if(rand==9)
		mov mainarr[10], 1
		.endif

		

	.endif
dec r
.until(r==0)

;///////////SEVENTH COLUMN FILLING

mov bx, 96
mov r, 8

.repeat
	mov s, 8

	.repeat
		mov bx, 96

		.repeat

			.if(mainarr[bx]==6)
			sub bx, 14
			mov ax, mainarr[bx]
			mov mainarr[bx], 6
			add bx, 14
			mov mainarr[bx], ax
			.endif

		sub bx, 14
		.until(bx==12)
		dec s
	.until(s==0)

	.if(mainarr[12]==6)
	call delaycandy
	call randomcall
		.if(rand==0)
		mov mainarr[12], 1
		.endif

		.if(rand==1)
		mov mainarr[12], 2
		.endif

		.if(rand==2)
		mov mainarr[12], 3
		.endif

		.if(rand==3)
		mov mainarr[12], 4
		.endif

		.if(rand==4)
		mov mainarr[12], 3
		.endif

		.if(rand==5)
		mov mainarr[12], 4
		.endif

		.if(rand==6)
		mov mainarr[12], 3
		.endif

		.if(rand==7)
		mov mainarr[12], 2
		.endif

		.if(rand==8)
		mov mainarr[12], 1
		.endif

		.if(rand==9)
		mov mainarr[12], 1
		.endif


	.endif
dec r
.until(r==0)

mov crushingbool, 0


ret 
filling endp

failed proc 

mov ax, 12h
int 10h

mov ah, 02h
mov dh, 12
mov dl, 10
int 10h

mov dx, offset msg6
mov ah, 09h
int 21h

mov ah, 02h
mov dh, 14
mov dl, 32
int 10h

mov dx, offset msg7
mov ah, 09h
int 21h




ret
failed endp

passed proc

mov ax, 12h
int 10h

mov ah, 02h
mov dh, 14
mov dl, 26
int 10h

mov dx, offset msg8
mov ah, 09h
int 21h

ret 
passed endp


level2 proc 

mov ax, 12h
int 10h

mov ah, 0ch ;sets pixel
mov al, 0fh ;sets pixel color
mov bh, 0 ;sets page no

mov cx, 127 ;x-axis coordinate
mov dx, 47;y-axis coordinate

;This is the board drawing part
add cx, 55
.repeat
int 10h ;prints a pixel
inc cx ;increases the x-coord of the next pixel
.until (cx==292)

add cx, 55
.repeat
int 10h ;prints a pixel
inc cx ;increases the x-coord of the next pixel
.until (cx==457)

mov cx, 127
mov dx, 432

add cx, 55
.repeat
int 10h ;prints a pixel
inc cx ;increases the x-coord of the next pixel
.until (cx==292)

add cx, 55
.repeat
int 10h ;prints a pixel
inc cx ;increases the x-coord of the next pixel
.until (cx==457)

mov cx, 182
mov dx, 47

.repeat
.repeat
int 10h
inc dx
.until(dx == 432)
mov dx, 47
add cx, 55
.until (cx == 512)

mov dx, 102
mov cx, 182

.repeat
.repeat
int 10h
inc cx
.until(cx == 457)
mov cx, 182
add dx,55
.until (dx == 432)

mov dx, 157
mov cx, 127

.repeat
.repeat
int 10h
inc cx
.until(cx == 512)
mov cx, 127
add dx, 55
.until (dx == 377)

mov dx, 157
mov cx, 127

.repeat
int 10h
inc dx
.until (dx == 212)

add dx, 55

.repeat
int 10h
inc dx
.until (dx == 322)

mov dx, 157
mov cx, 512

.repeat
int 10h
inc dx
.until (dx == 212)

add dx, 55

.repeat
int 10h
inc dx
.until (dx == 322)

ret
level2 endp


startgame2 proc
mov si, offset arrx
mov bx, 0


.repeat

.if(bx!=0 && bx!=6 && bx!=12 && bx!=14 && bx!=26 && bx!=42 && bx!=54 && bx!=70 && bx!=82 && bx!=84 && bx!=90 && bx!=96)
	mov cx, [si]
	mov dx, arry[bx]


	.if(mainarr[bx]==1)
	call yrden
	.endif

	.if(mainarr[bx]==2)
	call diamond
	.endif

	.if(mainarr[bx]==3)
	call play
	.endif

	.if(mainarr[bx]==4)
	call gps
	.endif

	.if(mainarr[bx]==5)
	call bomb
	.endif

.endif

add si, 2
add bx, 2
.until(bx==98)




ret
startgame2 endp


startgame3 proc
mov si, offset arrx
mov bx, 0


.repeat

.if(bx!=6 && bx!=20 && bx!=34 && bx!=48 && bx!=62 && bx!=76 && bx!=90 && bx!=42 && bx!=44 && bx!=46 && bx!=48 && bx!=50 && bx!=52 && bx!=54)
	mov cx, [si]
	mov dx, arry[bx]


	.if(mainarr[bx]==1)
	call yrden
	.endif

	.if(mainarr[bx]==2)
	call diamond
	.endif

	.if(mainarr[bx]==3)
	call play
	.endif

	.if(mainarr[bx]==4)
	call gps
	.endif

	.if(mainarr[bx]==5)
	call bomb
	.endif

.endif

add si, 2
add bx, 2
.until(bx==98)




ret
startgame3 endp

level3 proc
mov ax, 12h
int 10h

mov ah, 0ch ;sets pixel
mov al, 0fh ;sets pixel color
mov bh, 0 ;sets page no

mov dx, 47
mov cx, 127
call brick

mov dx, 267
mov cx, 127
call brick

mov dx, 267
mov cx, 347
call brick

mov dx, 47
mov cx, 347
call brick

mov dx, 47
mov cx, 294

mov al, 0eh

.repeat
.repeat
int 10h
inc cx
.until (cx == 346)
mov cx, 294
inc dx
.until (dx==212)

mov al, 0ah
add dx, 56
mov cx, 294

.repeat
.repeat
int 10h
inc cx
.until (cx == 346)
mov cx, 294
inc dx
.until (dx==433)

mov cx, 127
mov dx, 214

mov al, 0dh

.repeat
.repeat
int 10h
inc dx
.until (dx == 266)
mov dx, 214
inc cx
.until (cx==292)

mov al, 0bh
mov dx, 214
add cx, 55

.repeat
.repeat
int 10h
inc dx
.until (dx == 266)
mov dx, 214
inc cx
.until (cx==513)

ret
level3 endp

brick proc uses cx dx

mov ah, 0ch ;sets pixel
mov al, 0fh ;sets pixel color
mov bh, 0 ;sets page no

mov y, dx
mov x, cx
add x, 165
add y, 220

.repeat
.repeat
int 10h
inc cx
.until (cx == x)
sub cx, 165
add dx, 55
.until (dx == y)

sub x, 165
sub y, 220

mov cx, x
mov dx, y

add y, 165
add x, 220

.repeat
.repeat
int 10h
inc dx
.until (dx == y)
sub dx, 165
add cx, 55
.until (cx == x)

ret
brick endp


fillboard3 proc
;127,182,237,292,347,402,457
;47,102,157,212,267,322,377




;FIRST LINE//////////
mov si, offset arrx ;setting the offset of arrx in si
mov bx, 0 ;setting 0 in bx, to which 2 will be added after every candycall to traverse the arry


mov cx, [si]
mov dx, arry[bx]
call delaycandy ;a delay is called which is needed to randomise the candies placed, Otherwise all candies placed will have the same type
call candycall ;this function makes a randomvalue and also sets a candy according to the value

add si, 2 ;traversing arrx
add bx, 2 ;traversing arry

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;SECOND LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;THIRD LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;FOURTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2


add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

;FIFTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;SIXTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

;SEVENTH LINE//////////

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall2

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall

add si, 2
add bx, 2

mov cx, [si]
mov dx, arry[bx]
call delaycandy
call candycall


ret
fillboard3 endp

clrmainarr proc uses bx

mov bx, 0

.repeat

mov mainarr[bx],0

add bx, 2

.until(bx==98)

ret
clrmainarr endp

beatgametext proc

mov ax, 12h
int 10h

mov ah, 02h
mov dh, 14
mov dl, 23
int 10h

mov dx, offset beatgame
mov ah, 09h
int 21h

call delay
call delay
call delay


ret
beatgametext endp



;///This is the delay code, which is used in the title page for the animation of the candies////
delay proc

push ax
push bx
push cx
push dx

mov cx,1000
D1:
mov bx,800; Delay factor 
D2:
dec bx
jnz D2
loop D1

pop dx
pop cx
pop bx
pop ax

ret
delay endp


