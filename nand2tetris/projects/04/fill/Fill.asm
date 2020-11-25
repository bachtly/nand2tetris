// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

    @KBD
    D = A
    @const
    M = D
    //@SCREEN
    //D = A
    //@const 
    //M = M - D

(START)
    @SCREEN
    D=A
    @R0
    M=D	

(KBDCHECK)
    @KBD
    D=M
    @BLACK
    D; JGT	//PRESSED THEN BLACK
    @WHITE
    0; JMP	//ELSE WHITE
    
(BLACK)
    @R1
    M=-1	//(-1=11111111111111)
    @CHANGE
    0; JMP

(WHITE)
    @R1
    M=0	//0000000000000000
    @CHANGE
    0; JMP


(CHANGE)
    @R1	
    D=M	//D = 0 or 1

    @R0
    A = M
    M = D //Filling a slot

    @R0
    M=M+1	//INC TO NEXT PIXEL
    D = M
    @const
    D = D - M

    @CHANGE
    D; JLT

    @START
    0; JMP