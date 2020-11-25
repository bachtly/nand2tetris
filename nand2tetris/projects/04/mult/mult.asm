// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

    //init variables
    @i
    M = 1
    @value
    M = 0 

    //condition
(while)    
    @R1
    D = M
    @i
    D = M - D
    @exit
    D; JGT
    
    //looping
    @R0
    D = M
    @value
    M = D + M
    @i
    M = M + 1

    @while //loop back
    0; JMP

(exit)
    @value 
    D = M
    @R2
    M = D
//END
    @20
    0; JMP

//psudo-code
//while i-R1 <= 0:
//  value += R0
//  i++




