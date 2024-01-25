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
