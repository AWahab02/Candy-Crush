.model small
.stack 100h
.code


;///////BOMB CANDY///////
bomb proc uses si cx dx

add cx, 18
add dx, 16

mov x, cx
mov y, dx

add x, 20
add y, 20


mov ah, 0ch
mov al, 04h

.repeat
.repeat
int 10h
inc cx
.until(cx == x)
sub cx, 20
inc dx
.until (dx == y)

mov al, 04h		;setting different color for triangle

sub x, 20		;default x and y positions
sub y, 20

mov cx, x
mov dx, y

sub y, 10

.repeat
int 10h
dec dx
inc cx
.until (dx == y)

add y, 10

.repeat
int 10h
inc dx
inc cx
.until(dx == y)

mov cx, x

add y, 20
mov dx, y
add y, 10

.repeat
int 10h
inc cx
inc dx
.until (dx == y)

sub y, 10

.repeat
int 10h
inc cx
dec dx
.until (dx == y)

sub y, 20

mov cx, x
mov dx, y

add y, 10

.repeat
int 10h
inc dx
dec cx
.until(dx == y)

add y, 10

.repeat
int 10h
inc cx
inc dx
.until(dx == y)

add cx, 20
add x, 30
.repeat
int 10h
inc cx
dec dx
.until (cx == x)

sub x, 10

.repeat
int 10h
dec cx
dec dx
.until (cx == x)


ret
bomb endp

;//////////PLAY BUTTON CANDY//////////
play proc uses si cx dx

;play button shape
add cx, 20
add dx, 7
mov x, cx
mov y, dx
mov al, 0eh


add x, 20
.repeat
int 10h
inc cx
inc dx
.until(cx==x)

sub x, 20
.repeat
int 10h
dec cx
inc dx
.until(cx==x)


.repeat
int 10h
dec dx
.until(dx==y)

ret
play endp

;////////DIAMOND CANDY//////////
diamond proc uses si cx dx
add cx, 28
add dx, 6
mov x, cx
mov y, dx
mov al, 0ah

add x, 20
.repeat
int 10h
inc cx
inc dx
.until(cx==x)

sub x, 21
.repeat
int 10h
dec cx
inc dx
.until(cx==x)

sub x, 20
.repeat
int 10h
dec cx
dec dx
.until(cx==x)

add x, 22
.repeat
int 10h
inc cx
dec dx
.until(cx==x)


ret 
diamond endp

;///////////YRDEN CANDY(HOURGLASS SHAPE)//////////////
yrden proc uses si cx dx
add cx, 12
add dx, 12
mov x, cx
mov y, dx
mov al, 0dh

add x, 30
.repeat
int 10h
inc cx
.until(cx==x)

sub x, 30
.repeat
int 10h
inc dx
dec cx
.until(cx==x)

add x, 30
.repeat
int 10h
inc cx
.until(cx==x)

sub x, 30
.repeat
int 10h
dec dx
dec cx
.until(cx==x)

;filling yrden


ret
yrden endp

;//////GPS CANDY////////
gps proc uses si cx dx
add cx, 27
add dx, 8
mov x, cx
mov y, dx
mov al, 0bh

add x, 18
.repeat
int 10h
inc cx
add dx, 2
.until(cx==x)

sub x, 18
.repeat
int 10h
sub cx, 2
dec dx
.until(cx==x)

sub x, 18
.repeat
int 10h
sub cx, 2
inc dx
.until(cx==x)

add x, 18
.repeat
int 10h
inc cx
sub dx, 2
.until(cx==x)

ret 
gps endp
