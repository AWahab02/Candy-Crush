;20i-0465_Abdul Wahab_20i-2473_Muhammad Huzaifa

include letters.inc
include candies.inc
include utility.inc

.model small
.stack 100h
.data

naam db 40 dup("$") ;string which inputs the name
naamlength dw 0
endl db 0dh, 0ah
newlinelength dw ?
variable dw 150h

filename db 'scores.txt'
fhandle dw ?
dcount db 0
ftemp dw ?

scorestr db "Score:$"
msg db "Press Enter to Play","$"
msg2 db " Enter to Continue","$"
msg1 db "Enter Your Name:","$"
msg3 db "[R]Restart$"
msg4 db "[ESC]Exit$"
msg5 db "Moves: $"
msg6 db "You failed to reach the threshold points in the alloted moves.$"
msg7 db "Try Again? Y/N$"
msg8 db "Level Completed Succesfully!$"
heading db "Game Rules$"
welcome db "Welcome, $"
spaces db 13, 10, 13, 10, 13, 10,13, 10, 13, 10, "$"
rules db "1. Candy crush is a match-three game.", 13, 10, 13, 10, 13, 10, "2. You are supposed to swap two adjacent candies to make a row/column of at", 13, 10, "least 3 matching candies.", 13, 10, 13, 10, 13, 10, "3. The matched candies would be removed from the board, and replaced with", 13, 10, "candies above them.", 13, 10,13, 10, 13, 10,  "4. There are a total of 3 levels, after completing one level, you can move on", 13, 10, "to the next.", 13, 10,13, 10, 13, 10,  "$"
x dw ? ; these variables are used to maintain the values of the register inside the callcandy function
y dw ?
b dw ?
s dw ?
a dw ?
r dw ?
clicks dw ?
x1 dw ?
y1 dw ?
x2 dw ?
y2 dw ?
swap1 dw ?
swap2 dw ?
swapindex1 dw ?
swapindex2 dw ?
temp dw ?
temp2 dw ?

boundary db "----------------------------------------"

crushcount dw 0

crushingbool dw 0

crushingstr db "CRUSHING!$"
bombstr db "EXPLOSION!$"

targetstr db "Target: 15000pts$"
targetstr2 db "Target: 8000pts$"
targetstr3 db "Target: 5000pts$"

highest dw 0

repeater dw ?
cxval dw ?
buttons dw ?
var db 0
rand db ?
arrx dw 49 dup(0)
arry dw 49 dup(0)
mainarr dw 56 dup(0)
mainiterator dw 0

mainarr2 dw 56 dup(0)

mainarr3 dw 56 dup(0)

s1 dw 0
s2 dw 0
s3 dw 0

score dw 0
scorelength dw ?

moves dw 5

digitCount dw ?

bombbool dw 0
swapbool dw 0

hs db "Highscore: "
l1 db "Level 1 score: "
l2 db "Level 2 score: "
l3 db "Level 3 score: "

level1str db "LEVEL 1$"
level2str db "LEVEL 2$"
level3str db "LEVEL 3$"

beatgame db "Congratulations! You won the game!$"

.code
main proc
mov ax, @data
mov ds, ax

;//////////////This is the beginning of the game, the first function initialises the arrx and arry with the coordinates on the board/////////////



call settingarray
mov si, offset mainarr

;call settingarray2

;/////////////Page1: this is the title page where the name of the game will be displayed and the user input is taken//////////////////
page1:
mov ax, 12h
int 10h


call titlepage		;title page with CANDY CRUSH LOGO

mov ah, 02h
mov bl, 00h
int 10h

mov ah, 01h	;Cursor scan length setting, to prevent extra black boxes
mov cx, 0001h
int 10h

;//String input part starts here

mov ah, 02h ;setting the position of the string which is to be inputted
mov dh, 22
mov dl, 34
int 10h

mov si, offset naam ;sets si to offset of the input string array



print: ;label which displays the string on the title page as it is types as well as stores the typed string in an array to display later in page 3

mov ah, 01 ;takes input
int 21h

.if(al!=13 && al) ;If Enter key is not pressed
mov [si], al ;The character entered is stored in array
inc naamlength
inc si ;array traversed
mov ah, 09h ;Character which is inputted is printed on the screen
int 10h

jmp print
.endif

mov ah,3dh			
mov dx,offset filename
mov al, 2 
int 21h
mov fhandle, ax

mov ah,42h
mov bx,fhandle
xor cx,cx
xor dx,dx
mov al, 2
int 21h

mov ah, 40h			
mov bx, fhandle
mov cx, lengthof endl
mov dx, offset endl
int 21h

mov ah, 40h			
mov bx, fhandle
mov cx, lengthof boundary
mov dx, offset boundary
int 21h

mov ah, 40h			
mov bx, fhandle
mov cx, lengthof endl
mov dx, offset endl
int 21h

mov ah, 40h			;writing name to file
mov bx, fhandle
mov cx, naamlength
mov dx, offset naam
int 21h



;/////////////////Page 2 starts here, which is the rulepage/////////////////////

page2:

call rulepage


;Sees if user enters input from the keyboard 

mov ax, 0
int 16h

;If the user presses Enter key on the rulespage, it proceeds to the next page which is the board page

.if(ah==1Ch)
jmp page3			;PAGE WITH board
.endif

call delay
jmp page2


;/////////////Page 3 starts here, the board page//////////////////

page3:
mov ax, 12h ;setting the resolution
int 10h




;127,182,237,292,347,402,457
;47,102,157,212,267,322,377

mov score, 0
mov moves, 10

call board

call fillboard ;function which fills the board with random candies

call string ;function which prints the strings that are required on the board page

call crushing

call delay

call board

call startgame

call filling

call board

call startgame

call string

call displaynum

call displaymoves


mov r, 5


	.repeat

	swaplabel:

	call crushing

	call filling

	call board

	call startgame

	call string

	call displaynum

	call displaymoves


	mov swapbool, 0
	call updating
	call delay
	call updating2

	mov ax, swapindex1
	mov bx, swapindex2

	add ax, 2

	.if(ax==bx)
	call swapping
	cmp swapbool, 1
	je swapend
	.endif

	mov ax, swapindex1
	mov bx, swapindex2

	sub ax, 2

	.if(ax==bx)
	call swapping
	cmp swapbool, 1
	je swapend
	.endif

	mov ax, swapindex1
	mov bx, swapindex2

	add ax, 14

	.if(ax==bx)
	call swapping
	cmp swapbool, 1
	je swapend
	.endif

	mov ax, swapindex1
	mov bx, swapindex2
	sub ax, 14

	.if(ax==bx)
	call swapping
	cmp swapbool, 1
	je swapend
	.endif

	jmp swaplabel

	swapend:

	dec moves


	mov repeater, 10

	.repeat
	
	.if(swapbool==1)
	call crushing
	.endif


	.if(crushingbool==1 && swapbool==1)
	call delay
	call board
	call startgame
	call string
	call displaynum
	call filling
	call board
	call startgame
	call string
	call displaynum
	.endif

	dec repeater
	.until(repeater==0)
	

	
	call displaymoves

	.until(moves==0)

mov ah, 40h
mov bx, fhandle
mov cx, lengthof endl
mov dx, offset endl
int 21h

mov ah, 40h
mov bx, fhandle
mov cx, lengthof l1
mov dx, offset l1
int 21h

call writescore
mov ax, score
mov s1, ax

	.if(score<15000)
	call failed
	mov ax, 0h
	int 16h

		.if(al==59h || al==79h)
		jmp page3
		.else
		calchigh
		call writehigh
		mov ah,3eh
		mov bx,fhandle
		int 21h
	
		jmp exit
		.endif
	.else
	call passed
	call delay
	call delay
	call delay
	jmp page4

	.endif



jmp exit


;takes input on page 3 from user

;mov ax, 0h
;int 16h
;.if(al==72h || al==52h) ;If user presses R or r, then the board restarts and places random candies at each position
;jmp page3
;.endif

mov scorelength, lengthof score

;////////End of main function////////

;.repeat
;call updating
;.until (ah==01)
exit:



mov ax, 12h
int 10h


mov ah, 4ch
int 21h

;//////////////////////////////////////////////////////////////////LEVEL2///////////////////////////////////////////



page4:
mov ax, 12h ;setting the resolution
int 10h


call clrmainarr

;127,182,237,292,347,402,457
;47,102,157,212,267,322,377

mov score, 0
mov moves, 10


call level2

call fillboard2 ;function which fills the board with random candies

call string2 ;function which prints the strings that are required on the board page

call crushing

call delay

call level2

call startgame2

call filling

call level2

call startgame2

call string2

call displaynum

call displaymoves


mov r, 5


	.repeat

	swaplabel2:

	call crushing

	call filling

	call level2

	call startgame2

	call string2

	call displaynum

	call displaymoves


	mov swapbool, 0
	call updating
	call delay
	call updating2

	mov ax, swapindex1
	mov bx, swapindex2

	add ax, 2

	.if(ax==bx)
	call swapping
	cmp swapbool, 1
	je swapend2
	.endif

	mov ax, swapindex1
	mov bx, swapindex2

	sub ax, 2

	.if(ax==bx)
	call swapping
	cmp swapbool, 1
	je swapend2
	.endif

	mov ax, swapindex1
	mov bx, swapindex2

	add ax, 14

	.if(ax==bx)
	call swapping
	cmp swapbool, 1
	je swapend2
	.endif

	mov ax, swapindex1
	mov bx, swapindex2
	sub ax, 14

	.if(ax==bx)
	call swapping
	cmp swapbool, 1
	je swapend2
	.endif

	jmp swaplabel2

	swapend2:
	dec moves



	mov repeater, 10

	.repeat
	
	.if(swapbool==1)
	call crushing
	.endif


	.if(crushingbool==1 && swapbool==1)
	call delay
	call level2
	call startgame2
	call string2
	call displaynum
	call filling
	call level2
	call startgame2
	call string2
	call displaynum
	.endif

	dec repeater
	.until(repeater==0)
	


	call displaymoves


	.until(moves==0)

mov ah, 40h
mov bx, fhandle
mov cx, lengthof endl
mov dx, offset endl
int 21h

mov ah, 40h
mov bx, fhandle
mov cx, lengthof l2
mov dx, offset l2
int 21h

call writescore
mov ax, score
mov s2, ax

	.if(score<15000)
	call failed
	mov ax, 0h
	int 16h

		.if(al==59h || al==79h)
		jmp page4
		.else
		calchigh
		call writehigh
		mov ah,3eh
		mov bx,fhandle
		int 21h
		jmp exit
		.endif
	.else
	call passed
	call delay
	call delay
	call delay
	jmp page5

	.endif



jmp exit




;//////////////////////////////////////////////////////////////////LEVEL3///////////////////////////////////////////



page5:
mov ax, 12h ;setting the resolution
int 10h


call clrmainarr


;127,182,237,292,347,402,457
;47,102,157,212,267,322,377
mov score, 0
mov moves, 10


call level3

call fillboard3 ;function which fills the board with random candies

call string3 ;function which prints the strings that are required on the board page

call crushing

call delay

call level3

call startgame3

call filling

call level3

call startgame3

call string3

call displaynum

call displaymoves


mov r, 5
mov swapbool, 0

	.repeat

	swaplabel3:

	.if(swapbool==1)
	call crushing
	.endif

	call crushing

	call filling

	call level3

	call startgame3

	call string3

	call displaynum

	call displaymoves


	mov swapbool, 0
	call updating
	call delay
	call updating2

	mov ax, swapindex1
	mov bx, swapindex2

	add ax, 2

	.if(ax==bx && ax!=6 && ax!=20 && ax!=34 && ax!=48 && ax!=62 && ax!=76 && ax!=90 && ax!=42 && ax!=44 && ax!=46 && ax!=48 && ax!=50 && ax!=52 && ax!=54)
		.if(bx!=6 && bx!=20 && bx!=34 && bx!=48 && bx!=62 && bx!=76 && bx!=90 && bx!=42 && bx!=44 && bx!=46 && bx!=48 && bx!=50 && bx!=52 && bx!=54)
		call swapping
		cmp swapbool, 1
		je swapend3
		.endif
	.endif

	mov ax, swapindex1
	mov bx, swapindex2

	sub ax, 2

	.if(ax==bx && ax!=6 && ax!=20 && ax!=34 && ax!=48 && ax!=62 && ax!=76 && ax!=90 && ax!=42 && ax!=44 && ax!=46 && ax!=48 && ax!=50 && ax!=52 && ax!=54)
		.if(bx!=6 && bx!=20 && bx!=34 && bx!=48 && bx!=62 && bx!=76 && bx!=90 && bx!=42 && bx!=44 && bx!=46 && bx!=48 && bx!=50 && bx!=52 && bx!=54)
		call swapping
		cmp swapbool, 1
		je swapend3
		.endif
	.endif

	mov ax, swapindex1
	mov bx, swapindex2

	add ax, 14

	.if(ax==bx && ax!=6 && ax!=20 && ax!=34 && ax!=48 && ax!=62 && ax!=76 && ax!=90 && ax!=42 && ax!=44 && ax!=46 && ax!=48 && ax!=50 && ax!=52 && ax!=54)
		.if(bx!=6 && bx!=20 && bx!=34 && bx!=48 && bx!=62 && bx!=76 && bx!=90 && bx!=42 && bx!=44 && bx!=46 && bx!=48 && bx!=50 && bx!=52 && bx!=54)
		call swapping
		cmp swapbool, 1
		je swapend3
		.endif
	.endif

	mov ax, swapindex1
	mov bx, swapindex2
	sub ax, 14

	.if(ax==bx && ax!=6 && ax!=20 && ax!=34 && ax!=48 && ax!=62 && ax!=76 && ax!=90 && ax!=42 && ax!=44 && ax!=46 && ax!=48 && ax!=50 && ax!=52 && ax!=54)
		.if(bx!=6 && bx!=20 && bx!=34 && bx!=48 && bx!=62 && bx!=76 && bx!=90 && bx!=42 && bx!=44 && bx!=46 && bx!=48 && bx!=50 && bx!=52 && bx!=54)
		call swapping
		cmp swapbool, 1
		je swapend3
		.endif
	.endif

	jmp swaplabel3

	swapend3:

	dec moves


	mov repeater, 10

	.repeat
	
	.if(swapbool==1)
	call crushing
	.endif


	.if(crushingbool==1 && swapbool==1)
	call delay
	call level3
	call startgame3
	call string3
	call displaynum
	call filling
	call level3
	call startgame3
	call string3
	call displaynum
	.endif

	dec repeater
	.until(repeater==0)
	

	call displaymoves


	.until(moves==0)

mov ah, 40h
mov bx, fhandle
mov cx, lengthof endl
mov dx, offset endl
int 21h

mov ah, 40h
mov bx, fhandle
mov cx, lengthof l3
mov dx, offset l3
int 21h

call writescore
mov ax, score
mov s3, ax

	.if(score<15000)
	call failed
	mov ax, 0h
	int 16h

		.if(al==59h || al==79h)
		jmp page5
		.else
		calchigh
		call writehigh
		mov ah,3eh
		mov bx,fhandle
		int 21h
		jmp exit
		
		.endif
	.else
	call passed
	call delay
	call delay
	call delay
	calchigh
	call writehigh
	mov ah,3eh
	mov bx,fhandle
	int 21h

	jmp exitgamebeat

	.endif



jmp exitgamebeat

exitgamebeat:

call beatgametext

mov ax, 12h

int 10h

mov ah, 4ch
int 21h




main endp





end main


