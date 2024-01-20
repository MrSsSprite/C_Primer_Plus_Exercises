# Chapter 1

## Review Questions

### Question 1.
> What does *portability* mean in the context of programming?

*Portability* in context of programming means the ability to directly move the source code
written in a specific system or environment to another without (or least) effort on modification.

### Question 2.
> Explain the difference between a source code file, object code file, and executable file.

A source code file is a file that high-level programming language (for instance, C) that is not
directly executable by computers.

By comparison, an executable file is file that is executable by computers (and hence in binary).

An object code file is between the above two filetypes, and more like a executable
except for that an object code file (though in binary) does not include all the information to
run a program (as a specific example, does not have the starter function or library required).

### Question 3.
> What are the seven major steps in programming?

1. Defining program objectives
2. Designing the program
3. Coding the program
4. Compiling the program
5. Running the program
6. Testing and Debugging the program
7. Maintaining and Modifying the program

### Question 3.
> What does a compiler do?

Compiler "translates" the source code into executable instructions to a computer.

### Question 4.
> What does a linker do?

Linker link the object code file(s) and library function files together and add a starter code
so that an executable file is generated.

## Programming Exercise

### Question 1.
> You have just been employed by MacroMuscle, Inc. (Software for Hard Bodies). The 
company is entering the European market and wants a program that converts inches 
to centimeters (1 inch = 2.54 cm). The company wants the program set up so that it 
prompts the user to enter an inch value. Your assignment is to define the program 
objectives and to design the program (steps 1 and 2 of the programming process).

Program Objectives
------------------
Convert the length value in inch from user to be in *centimeters*

Program Design
--------------
1. Prompt the user for a length value (and remind them it should be in inch)
2. Convert the value to be in centimeters
3. Print the value
