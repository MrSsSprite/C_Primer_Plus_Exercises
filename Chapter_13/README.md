# Chapter 13. File Input/Output

## Review Questions

### Question 1.
> What's wrong with this program?
> ```c
> int main(void)
> {
>     int *fp;
>     int k;
> 
>     fp = fopen("gelatin");
>     for (k = 0; k < 30; k++)
>         fputs(fp, "Nanette eats gelatin.");
>     fclose("gelatin");
> 
>     return 0;
> }
> ```

The `fclose` call in the program causes undefined behavior. The program should pass `fp` 
as the argument to `fclose`.

### Question 2.
> What would the following program do? (Assume it's run in a command-line evironment.)
> ```c
> #include <stdio.h>
> #include <stdlib.h>
> #include <ctype.h>
> int main(int argc, char *argv[])
> {
>     int ch;
>     FILE *fp;
> 
>     if (argc < 2)
>         exit(EXIT_FAILURE);
>     if ( (fp = fopen(argv[1], "r")) == NULL)
>         exit(EXIT_FAILURE);
>     while ( (ch = getc(fp)) != EOF)
>         if (isdigit(ch))
>             putchar(ch);
>     fclose (fp);
> 
>     return 0;
> }
> ```

The program reads in data from a given file path, parsing the data in text mode. Then, 
the program prints every digit characters in the file to `stdout`.

### Question 3.
> Suppose you have these statements in a program:
> ```c
> #include <stdio.h>
> FILE *fp1, *fp2;
> char ch;
> 
> fp1 = fopen("terky", "r");
> fp2 = fopen("jerky", "w");
> ```
> Also, suppose that both files were opened successfully. Supply the missing arguments in 
  the following function calls:
>> a. `ch = getc();`
>>
>> b. `fprintf( ,"%c\n", );`
>>
>> c. `putc( , );`
>>
>> d. `fclose(); /* close the terky file */`

- a. `ch = getc(fp1);`
- b. `fprintf(fp2, "%c\n", ch);`
- c. `putc(ch, fp2);`
- d. `fclose(fp1);`

### Question 4.
> Write a program that takes zero command-line arguments or one command-line argument. If 
  there is one argument, it is interpreted as the name of a file. If there is no argument, 
  the standard input (`stdin`) is to be used for input. Assume that the input consists 
  entirely of floating-point numbers. Have the program calculate and report the arithmetic 
  mean (the average) of the input numbers.

[source code](Review_Questions/q4.c) | [test input](test_inputs/q4.txt)

### Question 5.
> Write a program that takes two command-line arguments. The first is a character, and the 
  second is a filename. The program should print only those lines in the file containing 
  the given character. 

[source code](Review_Questions/q5.c) | [test input](test_inputs/q5.txt)

### Question 6.
> What’s the difference between binary files and text files on the one hand versus binary 
  streams and text streams on the other? 

The difference between binary files and text files is operating system dependent.

The difference between binary stream and text stream is that binary stream handles the 
data directly with no automatic translation, whereas text stream MAY include some 
automatic translation if necessary.

### Question 7.
> a. What is the difference between saving `8238201` by using `fprintf()` and saving it 
     by using `fwrite()` ?
>
> b. What is the difference between saving the character `S` by using `putc()` and saving 
     it by using `fwrite()` ?

- a. In essence, `fprintf` convert `8238201` to character code, while `fwrite` store the 
     binary representation of the value directly. If converted to character code, it 
     occupies more space and accordingly takes more effort to process; if saved directly 
     as binary value, it would cost less space and faster to process. Nonetheless, the 
     data form is not portable if saved as binary value. Different OS or even same OS 
     with different compiler or compiler setting may alter the parsing rule of a data 
     structure.
- b. Basically, NO.

### Question 8.
> What’s the difference among the following?
> ```c
> printf("Hello, %s\n", name);
> fprintf(stdout, "Hello, %s\n", name);
> fprintf(stderr, "Hello, %s\n", name);
> ```

The first two statements are exactly identical, whereas the third statement is a 
little different from them in that it is guaranteed to always output to the default 
output stream even if the `stdout` is redirected.

### Question 9.
> The `"a+"`, `"r+"`, and `"w+"` modes all open files for both reading and writing. Which 
  one is best for altering material already present in file?

It should be `"r+"` or `"a+"` mode if you want to keep the existing content.

## Programming Exercises

### Exercise 1.
> Modify [Listing 13.1](inClass/count.c) so that it solicits the user to enter the 
  filename and reads the user’s response instead of using command-line arguments.

[source code](Programming_Exercises/ex1.c)

### Exercise 2.
> Write a file-copy program that takes the original filename and the copy file from the 
  command line. Use standard I/O and the binary mode, if possible.

[source code](Programming_Exercises/ex2.c)

### Exercise 3.
> Write a file copy program that prompts the user to enter the name of a text file to act 
  as the source file and the name of an output file. The program should use the 
  `toupper()` function from `ctype.h` to convert all text to uppercase as it’s written to 
  the output file. Use standard I/O and the text mode. 

[source code](Programming_Exercises/ex3.c)

### Exercise 4.
> Write a program that sequentially displays onscreen all the files listed in the command 
  line. Use argc to control a loop. 

[source code](Programming_Exercises/ex4.c)

### Exercise 5.
> Modify the program in [Listing 13.5](inClass/append.c) so that it uses a command-line 
  interface instead of an interactive interface.

[source code](Programming_Exercises/ex5.c)

### Exercise 6.
> Programs using command-line arguments rely on the user’s memory of how to use them 
  correctly. Rewrite the program in [Listing 13.2](inClass/reducto.c) so that, instead of 
  using command-line arguments, it prompts the user for the required information.

[source code](Programming_Exercises/ex6.c)

### Exercise 7.
> Write a program that opens two files. You can obtain the filenames either by using 
  command-line arguments or by soliciting the user to enter them.
>> a. Have the program print line 1 of the first file, line 1 of the second file, line 2 
      of the first file, line 2 of the second file, and so on, until the last line of the 
      longer file (in terms of lines) is printed.
>>
>> b. Modify the program so that lines with the same line number are printed on the same 
      line.

[source code](Programming_Exercises/ex7.c)

### Exercise 8.
> Write a program that takes as command-line arguments a character and zero or more 
  filenames. If no arguments follow the character, have the program read the standard 
  input. Otherwise, have it open each file in turn and report how many times the character 
  appears in each file. The filename and the character itself should be reported along 
  with the count. Include error-checking to see whether the number of arguments is correct 
  and whether the files can be opened. If a file can’t be opened, have the program report 
  that fact and go on to the next file. 

[source code](Programming_Exercises/ex8.c) | [helper functions](Programming_Exercises/ex8_impl.c)

### Exercise 9.
> Modify the program in [Listing 13.3](inClass/addaword.c) so that each word is numbered 
  according to the order in which it was added to the list, starting with 1. Make sure 
  that, when the program is run a second time, new word numbering resumes where the 
  previous numbering left off.

[source code](Programming_Exercises/ex9.c)

### Exercise 10.
> Write a program that opens a text file whose name is obtained interactively. Set up a 
  loop that asks the user to enter a file position. The program then should print the part 
  of the file starting at that position and proceed to the next newline character. Let 
  negative or nonnumeric input terminate the user-input loop.

[source code](Programming_Exercises/ex10.c)

### Exercise 11.
> Write a program that takes two command-line arguments. The first is a string; the second 
  is the name of a file. The program should then search the file, printing all lines 
  containing the string. Because this task is line oriented rather than character 
  oriented, use `fgets()` instead of `getc().` Use the standard C library function 
  `strstr()` (briefly described in exercise 7 of Chapter 11 ) to search each line for the 
  string. Assume no lines are longer than 255 characters.

[source code](Programming_Exercises/ex11.c)

### Exercise 12.
> Create a text file consisting of 20 rows of 30 integers. The integers should be in the 
  range 0–9 and be separated by spaces. The file is a digital representation of a picture, 
  with the values 0 through 9 representing increasing levels of darkness. Write a program 
  that reads the contents of the file into a 20-by-30 array of ints. In a crude approach 
  toward converting this digital representation to a picture, have the program use the 
  values in this array to initialize a 20-by-31 array of chars, with a 0 value 
  corresponding to a space character, a 1 value to the period character, and so on, with 
  each larger number represented by a character that occupies more space. For example, you 
  might use # to represent 9. The last character (the 31st) in each row should be a null 
  character, making it an array of 20 strings. Have the program display the resulting 
  picture (that is, print the strings) and also store the result in a text file.
