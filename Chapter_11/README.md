# Chapter 11. Character Strings and String Functions

## Review Questions

### Question 1.
> What’s wrong with this attempted declaration of a character string?
> ```c
> int main(void)
> {
>     char name[] = {'F', 'e', 's', 's' };
>     ...
> }
> ```
A character string should end with `'\0'` (while the initialization above don't).

### Question 2.
> What will this program print?
> ```c
> #include <stdio.h>
> int main(void)
> {
>     char note[] = "See you at the snack bar.";
>     char *ptr;
>     ptr = note;
>     puts(ptr);
>     puts(++ptr);
>     note[7] = '\0';
>     puts(note);
>     puts(++ptr);
>     return 0;
> }
> ```
The program should print:
```terminal
See you at the snack bar.
ee you at the snack bar.
See you
e you

```

### Question 3.
> What will this program print?
> ```c
> #include <stdio.h>
> #include <string.h>
> int main(void)
> {
> char food[] = "Yummy";
> char *ptr;
> ptr = food + strlen(food);
> while (--ptr >= food)
>     puts(ptr);
> return 0;
> }
> ```
The program should print:
```terminal
y
my
mmy
ummy
Yummy

```

### Question 4.
> What will the following program print?
```c
#include <stdio.h>
#include <string.h>
int main(void)
{
    char goldwyn[40] = "art of it all ";
    char samuel[40] = "I read p";
    const char * quote = "the way through.";
    strcat(goldwyn, quote);
    strcat( samuel, goldwyn);
    puts(samuel);
    return 0;
}
```
The above program should print:
```terminal
I read part of it all the way through.

```

### Question 5.
> The following provides practice with strings, loops, pointers, and pointer 
  incrementing. First, suppose you have this function definition:
> ```c
> #include <stdio.h>
> char *pr(char *str)
> {
>     char *pc;
>     pc = str;
>     while (*pc)
>         putchar(*pc++);
>     do
>     {
>         putchar(*--pc);
>     }
>     while (pc - str);
>     return (pc);
> }
> ```
> Consider the following function call:
> ```c
> x = pr("Ho Ho Ho!");
> ```
>> a. What is printed?
>>
>> b. What type should `x` be?
>>
>> c. What value does `x` get?
>>
>> d. What does the expression `*--pc` mean, and how is it different from `--*pc`?
>>
>> e. What would be printed if `*--pc` were replaced with `*pc--`?
>>
>> f. What do the two `while` expressions test for?
>>
>> g. What happens if `pr()` is supplied with a null string as an argument?
>>
>> h. What must be done in the calling function so that `pr()` can be used as shown?
- a. Ho Ho Ho!!oH oH oH
- b. `char *`
- c. address of the first character of the input string literal (i.e., `"Ho Ho Ho!"`)
- d. `*--pc` instruct the computer to first decrement and then dereference it. In 
     comparison, `--*pc` instruct the computer to first dereference and decrement the 
     dereferenced value.
- e. `Ho Ho Ho!!oH oH o`
- f. the first `while` breaks when `*pc` evaluates to 0, which is `'\0'` in char. The 
     second `while` breaks when pc points to the first character of input string.
- g. `pc` pass through str before the condition is checked in the second loop. That means 
     the behavior is unpredictable.
- h. `pr` must be delared (correctly) in (or actually in or before) the calling function.

### Question 6.
> Assume this declaration:
> ```c
> char sign = '$';
> ```
> How many bytes of memory does sign use? What about `'$'`? What about `"$"`?
- `'$'`: 1 byte
- `"$"`: 2 bytes (i.e., `{'$', '\0'}`)

### Question 7.
> What does the following program print?
> ```c
> #include <stdio.h>
> #include <string.h>
> #define M1 "How are ya, sweetie? "
> char M2[40] = "Beat the clock.";
> char * M3 = "chat";
> int main(void)
> {
>     char words[80];
>     printf(M1);
>     puts(M1);
>     puts(M2);
>     puts(M2 + 1);
>     strcpy(words,M2);
>     strcat(words, " Win a toy.");
>     puts(words);
>     words[4] = '\0';
>     puts(words);
>     while (*M3)
>         puts(M3++);
>     puts(--M3);
>     puts(--M3);
>     M3 = M1;
>     puts(M3);
>     return 0;
> }
> ```
The program should print:
```terminal
How are ya, sweetie? How are ya, sweetie? 
Beat the clock.
eat the clock.
Beat the clock. Win a toy.
Beat
chat
hat
at
t
t
at
How are ya, sweetie? 

```

### Question 8.
> What does the following program print?
> ```c
> #include <stdio.h>
> int main(void)
> {
>     char str1[] = "gawsie"; // plump and cheerful
>     char str2[] = "bletonism";
>     char *ps;
>     int i = 0;
>     for (ps = str1; *ps != '\0'; ps++)
>     {
>         if ( *ps == 'a' || *ps == 'e')
>             putchar(*ps);
>         else
>             (*ps)--;
>         putchar(*ps);
>     }
>     putchar('\n');
>     while (str2[i] != '\0')
>     {
>         printf("%c", i % 3 ? str2[i] : '*');
>         ++i;
>     }
>     return 0;
> }
> ```
The program should print:
```terminal
faavrhee
*le*on*sm
```

### Question 9.
> The `s_gets()` function defined in this chapter can be written in pointer notation 
  instead of array notation so as to eliminate the variable i. Do so.

Here's an alternative:
```c
char * s_gets(char *st, int n)
{
    char *ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (*st != '\n' && *st != '\0')
            st++;
        if (*st == '\n')
            *st = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
```

### Question 10.
> The `strlen()` function takes a pointer to a string as an argument and returns the 
  length of the string. Write your own version of this function.

Here's my implementation:
```c
size_t strlen(const char *str)
{
    size_t count = 0;
    while (*str++)
        count++;
    return count;
}
```

### Question 11.
> The `s_gets()` function defined in this chapter can be written using `strchr()` instead 
  of a while loop to find the newline. Do so.

Here's my implementation:
```c
char * s_gets(char *st, int n)
{
    char *ret = fgets(st, n, stdin);
    if (ret)
    {
        if (st = strchr(ret, '\n'))
            *st = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret;
}
```

### Question 12.
> Design a function that takes a string pointer as an argument and returns a pointer to 
  the first space character in the string on or after the pointed-to position. Have it 
  return a null pointer if it finds no spaces.

Here's my implementation:
```c
char *find_space(const char *str)
{
    while (*str)
    {
        if (*str == ' ')
            return str;
        str++;
    }
    return NULL;
}
```

### Question 13.
> Rewrite Listing 11.21 using `ctype.h` functions so that the program recognizes a correct 
  answer regardless of the user’s choice of uppercase or lowercase.
> ```c
> /* Listing 11.21 */
> /* compare.c -- this will work */
> #include <stdio.h>
> #include <string.h> // declares strcmp()
> 
> #define ANSWER "Grant"
> #define SIZE 40
> char * s_gets(char * st, int n);
> 
> int main(void)
> {
>     char try[SIZE];
>     puts("Who is buried in Grant's tomb?");
>     s_gets(try, SIZE);
>     while (strcmp(try,ANSWER) != 0)
>     {
>         puts("No, that's wrong. Try again.");
>         s_gets(try, SIZE);
>     }
>     puts("That's right!");
>     return 0;
> }
> 
> char * s_gets(char * st, int n)
> {
>     char * ret_val;
>     int i = 0;
>     ret_val = fgets(st, n, stdin);
>     if (ret_val)
>     {
>         while (st[i] != '\n' && st[i] != '\0') i++;
>         if (st[i] == '\n') st[i] = '\0';
>         else // must have words[i] == '\0'
>             while (getchar() != '\n')
>                 continue;
>     }
>     return ret_val;
> }
> ```
Here's my implementation:
```c
#include <stdio.h>
#include <string.h> // declares strcmp()
#include <ctype.h>

#define ANSWER "GRANT"
#define SIZE 40
char * s_gets(char * st, int n);

int main(void)
{
    char try[SIZE];
    char *ptr = try;
    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    while (*ptr)
    {
        *ptr = toupper(*ptr);
        ptr++;
    }
    while (strcmp(try,ANSWER) != 0)
    {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
        while (*ptr)
        {
            *ptr = toupper(*ptr);
            ptr++;
        }
    }
    puts("That's right!");
    return 0;
}

char * s_gets(char * st, int n)
{ /* as in the original one */ }
```

## Programming Exercises

### Exercise 1.
> Design and test a function that fetches the next n characters from input (including 
  blanks, tabs, and newlines), storing the results in an array whose address is passed as 
  an argument.

[source code](Programming_Exercises/ex1.c) | [test input](test_inputs/ex1.txt)

### Exercise 2.
> Modify and test the function in exercise 1 so that it stops after n characters or 
  after the first blank, tab, or newline, whichever comes first. (Don’t just use scanf().)

[source code](Programming_Exercises/ex2.c) | [test input](test_inputs/ex1.txt)

### Exercise 3.
> Design and test a function that reads the first word from a line of input into an array 
  and discards the rest of the line. It should skip over leading whitespace. Define a word 
  as a sequence of characters with no blanks, tabs, or newlines in it. Use `getchar()`.

[source code](Programming_Exercises/ex3.c)

### Exercise 4.
> Design and test a function like that described in Programming Exercise 3 except that it 
  accepts a second parameter specifying the maximum number of characters that can be read.

To safeguard memory usage, this is already done in the previous exercise.

### Exercise 5.
> Design and test a function that searches the string specified by the first function 
  parameter for the first occurrence of a character specified by the second function 
  parameter. Have the function return a pointer to the character if successful, and a null 
  if the character is not found in the string. (This duplicates the way that the library 
  `strchr()` function works.) Test the function in a complete program that uses a loop to 
  provide input values for feeding to the function.

[source code](Programming_Exercises/ex5.c)

(the `get_string` function in the source code is just a function that is used to get 
variable-length string. It's implementation is not part of the this exercise. The only 
thing you need to know is that it take input from `stdin` and returns a pointer to 
a dynamically allocated block of memory (just think of it a pointer-to-array))

### Exercise 6.
> Write a function called `is_within()` that takes a character and a string pointer as its 
  two function parameters. Have the function return a nonzero value (true) if the 
  character is in the string and zero (false) otherwise. Test the function in a complete 
  program that uses a loop to provide input values for feeding to the function.

[source code](Programming_Exercises/ex6.c)

### Exercise 7.
> The `strncpy(s1,s2,n)` function copies exactly `n` characters from `s2` to `s1`, 
  truncating `s2` or padding it with extra null characters as necessary. The target string 
  may not be null-terminated if the length of `s2` is `n` or more. The function returns 
  `s1`. Write your own version of this function; call it `mystrncpy().` Test the function 
  in a complete program that uses a loop to provide input values for feeding to the function.

[source code](Programming_Exercises/ex7.c)

### Exercise 8.
> Write a function called `string_in()` that takes two string pointers as arguments. If 
  the second string is contained in the first string, have the function return the address 
  at which the contained string begins. For instance, `string_in("hats", "at")` would 
  return the address of the `a` in `hats`. Otherwise, have the function return the null 
  pointer. Test the function in a complete program that uses a loop to provide input 
  values for feeding to the function.

[source code](Programming_Exercises/ex8.c) | [test input](test_inputs/ex8.c)

### Exercise 9.
> Write a function that replaces the contents of a string with the string reversed. Test 
  the function in a complete program that uses a loop to provide input values for feeding 
  to the function.

[source code](Programming_Exercises/ex9.c) | [test input](test_inputs/ex9.c)

### Exercise 10.
> Write a function that takes a string as an argument and removes the spaces from the 
  string. Test it in a program that uses a loop to read lines until you enter an empty 
  line. The program should apply the function to each input string and display the result.

[source code](Programming_Exercises/ex10.c) | [test input](test_inputs/ex10.c)

### Exercise 11.
> Write a program that reads in up to 10 strings or to `EOF`, whichever comes first. Have 
  it offer the user a menu with five choices: print the original list of strings, print 
  the strings in ASCII collating sequence, print the strings in order of increasing 
  length, print the strings in order of the length of the first word in the string, and 
  quit. Have the menu recycle until the user enters the quit request. The program, of 
  course, should actually perform the promised tasks.

[source code](Programming_Exercises/ex11.c)

### Exercise 12.
> Write a program that reads input up to `EOF` and reports the number of words, the 
  number of uppercase letters, the number of lowercase letters, the number of punctuation 
  characters, and the number of digits. Use the `ctype.h` family of functions.

[source code](Programming_Exercises/ex12.c)

### Exercise 13.
> Write a program that echoes the command-line arguments in reverse word order. That is, 
  if the command-line arguments are `see you later`, the program should print `later you 
  see`.

[source code](Programming_Exercises/ex13.c)

### Exercise 14.
> Write a power-law program that works on a command-line basis. The first command-line 
  argument should be the type `double` number to be raised to a certain power, and the 
  second argument should be the integer power.

[source code](Programming_Exercises/ex14.c)

### Exercise 15.
> Use the character classification functions to prepare an implementation of `atoi()`; 
  have this version return the value of 0 if the input string is not a pure number.

[source code](Programming_Exercises/ex15.c)

### Exercise 16.
> Write a program that reads input until end-of-file and echoes it to the display. Have 
  the program recognize and implement the following command-line arguments:
> 
> | command | Description                |
> | ------- | -------------------------- |
> | `-p`    | Print input as is          |
> | `-u`    | Map input to all uppercase |
> | `-l`    | Map input to all lowercase |
>
> Also, if there are no command-line arguments, let the program behave as if the `-p` 
  argument had been used.

[source code](Programming_Exercises/ex16.c) | [test input(AI generated story)](test_inputs/ex16.c)
