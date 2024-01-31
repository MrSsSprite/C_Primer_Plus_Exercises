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

[source code](Review_Questions/q4.c)
