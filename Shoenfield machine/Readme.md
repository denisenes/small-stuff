# Shoenfield register machine interpreter

This project includes a simple bytecode compiler and a small interpreter that executes programs with instructions for the Shoenfield register machine (and some meta-information). I made it to learn how to use BNF Converter (https://github.com/BNFC/bnfc).

## Source code -> bytecode
The frontend part (aka lexer and parser) of the compiler was generated using BNFC. You can find language grammar in  ```machine.cf```.
The correct program looks like this:
```
$pragmas
...%list of directives%...
$instructions
...%list of machine instructions%...
```
In the ```$pragmas``` part there are two types of directives:
- ```@alloc %val%;``` This directive says to the interpreter how many registers it has to allocate.
- ```@set %regNum%, %val%;``` Set the value ```%val``` to the register with number ```%regNum%``` before execution.


The ```$instructions``` part contains instructions for the Shoenfield machine. They are written according to the usual syntax (with ";" delimiter between instructions).

## Interpretation
After compiling we have a bytecode file that has the following structure:
- Register allocation information (4 bytes)
- Number of ```set``` operations (4 bytes)
- ```Set``` operations (list of pairs: register number (4bytes), value (4 bytes))
- List of instructions (9 bytes per instruction: 1 byte - instruction code, 8 bytes - 1st and 2nd operands)

Then the file is given for reading to the interpreter. The interpreter allocates memory, put values into registers and then starts execution. If the program successfully terminates, it prints the value of the register with the number 0.
