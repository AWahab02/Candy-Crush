letters macro
mov ah, 0ch
mov al, 0bh
mov bh, 0
mov cx, 240
mov dx, 140

;drawing C
.repeat
int 10h
dec cx
.until(cx==190)

.repeat
int 10h
inc dx
.until(dx==193)

.repeat
int 10h
inc cx
.until(cx==240)

.repeat
int 10h
dec dx
.until(dx==181)

.repeat
int 10h
dec cx
.until(cx==205)

.repeat
int 10h
dec dx
.until(dx==153)

.repeat
int 10h
inc cx
.until(cx==240)

.repeat
int 10h
dec dx
.until(dx==140)

;Drawing A
add cx, 20

.repeat
int 10h
inc dx
.until(dx==193)

.repeat
int 10h
inc cx
.until(cx==273)

.repeat
int 10h
dec dx
.until(dx==168)

.repeat
int 10h
inc cx
.until(cx==286)

.repeat
int 10h
inc dx
.until(dx==193)

.repeat
int 10h
inc cx
.until(cx==299)

.repeat
int 10h
dec dx
.until(dx==140)	

.repeat
int 10h
dec cx
.until(cx==260)

mov cx, 275
mov dx, 156

.repeat
int 10h
inc cx
dec dx
.until(cx==280)

.repeat
int 10h
inc cx
inc dx
.until(cx==285)

.repeat
int 10h
dec cx
.until(cx==275)

;Drawing N

mov cx, 320
mov dx, 140

.repeat
int 10h
inc dx
.until(dx==193)

.repeat
int 10h
inc cx
.until(cx==330)

.repeat
int 10h
dec dx
.until(dx==158)

.repeat
int 10h
inc cx
.until(cx==340)


.repeat
int 10h
inc dx
.until(dx==193)

.repeat
int 10h
inc cx
.until(cx==350)

.repeat
int 10h
dec dx
.until(dx==140)

.repeat
int 10h
dec cx
.until(cx==320)

;Drawing D

mov cx, 370
mov dx, 140

.repeat
int 10h
inc dx
.until(dx==193)

.repeat
int 10h
inc cx
.until(cx==405)

.repeat
int 10h
dec dx
.until(dx==140)

.repeat
int 10h
dec cx
.until(cx==370)

mov cx, 384
mov dx, 160

.repeat
int 10h
inc dx
inc cx
.until(cx==392)

.repeat
int 10h
inc dx
dec cx
.until(cx==384)

.repeat
int 10h
dec dx
.until(dx==160)

;drawing Y

mov cx, 425
mov dx, 140

.repeat
int 10h
inc cx
add dx, 2
.until(cx==435)

.repeat
int 10h
inc dx
.until(dx==193)

.repeat
int 10h
inc cx
.until(cx==445)

.repeat
int 10h
dec dx
.until(dx==160)

.repeat
int 10h
inc cx
sub dx, 2
.until(dx==140)

.repeat
int 10h
dec cx
.until(cx==445)

.repeat
int 10h
dec cx
add dx, 2
.until(cx==440)

.repeat
int 10h
dec cx
sub dx, 2
.until(cx==435)

.repeat
int 10h
dec cx
.until(cx==425)

;Drawing C

mov cx, 240
mov dx, 213

.repeat
int 10h
dec cx
.until(cx==190)

.repeat
int 10h
inc dx
.until(dx==266)

.repeat
int 10h
inc cx
.until(cx==240)

.repeat
int 10h
dec dx
.until(dx==254)

.repeat
int 10h
dec cx
.until(cx==205)

.repeat
int 10h
dec dx
.until(dx==226)

.repeat
int 10h
inc cx
.until(cx==240)


.repeat
int 10h
dec dx
.until(dx==213)


;Drawing R

mov cx, 260
mov dx, 213

.repeat
int 10h
inc dx
.until(dx==266)

.repeat
int 10h
inc cx
.until(cx==272)

.repeat
int 10h
dec dx
.until(dx==243)

.repeat
int 10h
inc cx
.until(cx==280)

.repeat
int 10h
inc cx
add dx, 2
.until(cx==292)

.repeat
int 10h
inc cx
.until(cx==302)

.repeat
int 10h
dec cx
sub dx, 2
.until(cx==290)

.repeat
int 10h
inc cx
sub dx, 3
.until(cx==300)

.repeat
int 10h
dec cx
.until(cx==260)

mov cx, 275
mov dx, 222

.repeat
int 10h
inc cx
inc dx
.until(cx==281)

.repeat
int 10h
dec cx
inc dx
.until(cx==275)

.repeat
int 10h
dec dx
.until(dx==222)

;Drawing U

mov cx, 320
mov dx, 213

.repeat
int 10h
inc dx
.until(dx==268)

.repeat
int 10h
inc cx
.until(cx==350)

.repeat
int 10h
dec dx
.until(dx==213)

.repeat
int 10h
dec cx
.until(cx==340)

.repeat
int 10h
inc dx
.until(dx==248)

.repeat
int 10h
dec cx
.until(cx==330)

.repeat
int 10h
dec dx
.until(dx==213)

.repeat
int 10h
dec cx
.until(cx==320)

;Drawing S

mov cx, 405
mov dx, 213

.repeat
int 10h
dec cx
.until(cx==370)

.repeat
int 10h
inc dx
.until(dx==243)

.repeat
int 10h
inc cx
.until(cx==395)

.repeat
int 10h
inc dx
.until(dx==258)

.repeat
int 10h
dec cx
.until(cx==370)

.repeat
int 10h
inc dx
.until(dx==268)

.repeat
int 10h
inc cx
.until(cx==405)

.repeat
int 10h
dec dx
.until(dx==233)

.repeat
int 10h
dec cx
.until(cx==380)

.repeat
int 10h
dec dx
.until(dx==223)

.repeat
int 10h
inc cx
.until(cx==405)

.repeat
int 10h
dec dx
.until(dx==213)


;drawing H
mov cx, 425
mov dx, 213

.repeat
int 10h
inc dx
.until(dx==268)

.repeat
int 10h
inc cx
.until(cx==438)

.repeat
int 10h
dec dx
.until(dx==248)

.repeat
int 10h
inc cx
.until(cx==450)

.repeat
int 10h
inc dx
.until(dx==268)

.repeat
int 10h
inc cx
.until(cx==464)

.repeat
int 10h
dec dx
.until(dx==213)

.repeat
int 10h
dec cx
.until(cx==450)

.repeat
int 10h
inc dx
.until(dx==231)

.repeat
int 10h
dec cx
.until(cx==438)

.repeat
int 10h
dec dx
.until(dx==213)

.repeat
int 10h
dec cx
.until(cx==425)


;Borders
mov ah, 0ch
mov al, 0dh
mov bh, 0
mov cx, 140
mov dx, 110

.repeat
int 10h
inc cx
.until(cx==525)

.repeat
int 10h
inc dx
.until(dx==340)

.repeat
int 10h
dec cx
.until(cx==140)

.repeat
int 10h
dec dx
.until(dx==110)

;Outer Borders
mov ah, 0ch
mov al, 09h
mov bh, 0
mov cx, 100
mov dx, 70

.repeat
int 10h
inc cx
.until(cx==565)

.repeat
int 10h
inc dx
.until(dx==380)

.repeat
int 10h
dec cx
.until(cx==100)

.repeat
int 10h
dec dx
.until(dx==70)

call delay

mov cx, 187
mov dx, 270
call yrden


mov cx, 417
mov dx, 270
call yrden

call delay

mov cx, 250
mov dx, 270
call diamond


mov cx, 359
mov dx, 270
call diamond

call delay

mov cx, 307
mov dx, 270
call gps





mov ah, 02
mov dl, 18
mov dh, 22
int 10h



mov dx, offset msg1
mov ah, 09h
int 21h

mov ah, 02
mov dl, 31
mov dh, 26
int 10h

mov dx, offset msg
mov ah, 09h
int 21h

endm