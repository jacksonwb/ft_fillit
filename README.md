# fillit @ 42

This code was written to pass the fillet project at 42 Silicon Valley. The purpose of this program is to fill the smallest possible square board with valid tetris pieces. The arrangement can have holes, but the board size must be the smallest possible. The program must bias the solution to the top and left of the board. This particular solution uses bitfields and bitwise operators to more efficiently store and manipulate representations of each tetris piece. The solution is then printed with empy spaces represented by the `.` character and pieces represented by the letter coresponding to their order in the input. This particular implementation only supports 26 pieces.

## Compiling
Run `make`. An executable name `fillit` will be generated. 

## Usage
`./fillit [file]`

Example:
```
~./fillit samples/26

A..B.CCDDEM
ABBBCCGDDEM
AAFFFFG..EM
HHHII.GGJEM
KKH.IIN.JJS
KLLLL.NNNJS
KOOPPPQQRRS
UOOPTTYQRRS
U..TT.YQZW.
UUXXX.YZZWW
VVVVX.YZ..W
```