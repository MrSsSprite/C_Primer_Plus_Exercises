# Chapter 2

## Review Questions

### Question 1.
> What are the basic modules of a C program called?
>> Function

### Question 2.
> What is a syntax error? Give an example of one in English and one in C.
>> In C, a Syntax error is a type of error that violates the syntactical structure of C
stipulated by the C standard.
>> - English:
>>      - A is this syntax error.
>> - C:
>>      - int i0, int i1;

### Question 3.
> What is a semantic error? Give an example of one in English and one in C.
>> In C, semantic error basically involve every error which are not syntax error.
>> To be precise, it means an error that, though comforming the syntax,
>> does not lead to the anticipated result.
- English:
    - A pen brings me.
- C:
```c
float i = 1.2, j = 3.4;
int k = i * j;
```

### Question 4.
> Indiana Sloth has prepared the following program and brought it to you for approval. 
Please help him out.

```c
include studio.h
int main{void} /* this prints the number of weeks in a year /*
(
    int s
    s := 56;
    print(There are s weeks in a year.);
    return 0;
```

Here are the errors of this program (ordered from first line to last):
- incorrect preprocessor `include` format
- close the comment block incorrectly
- using improper symbol to open a function definition body
- no semicolon at the end of a statement
- improper symbol for assignment
- function name that does not match the stdlib (nor custom defined)
- not closing the function definition body

The corrected version:
```c
#include <stdio.h>
int main(void)
{
    int s;
    s = 56;
    printf("There are s weeks in a year.\n");

    return 0;
}
```

### Question 5.
> Assuming that each of the following examples is part of a complete program,
what will each one print?

```c
a. printf("Baa Baa Black Sheep.");
printf("Have you any wool?\n");
b. printf("Begone!\nO creature of lard!\n");
c. printf("What?\nNo/nfish?\n");
d. int num;
num = 2;
printf("%d + %d = %d", num, num, num + num);
```

a.
```terminal
Baa Baa Black Sheep.Have you any wool?

```
---
b.
```terminal
Begone!
O creature of lard!

```
---
c.
```terminal
What?
No/nfish?

```
---
d.
```terminal
2 + 2 = 4
```

### Question 6.
> Which of the following are C keywords? main, int, function, char, =
>> `int` and `char`

### Question 7.
> How would you print the values of the variables `words` and `lines`
so they appear in the following form:
```c
There were 3020 words and 350 lines.
```

Here, `3020` and `350` represent the values of the two variables.

```c
#include <stdio.h>

int main(void) {
    int words, lines;
    words = 3020;
    lines = 350;

    printf("There were %d words and %d lines.\n");

    return 0;
}
```

### Question 8.
> Consider the following program:
```c
#include <stdio.h>
int main(void)
{
    int a, b;
    a = 5;
    b = 2; /* line 7 */
    b = a; /* line 8 */
    a = b; /* line 9 */
    printf("%d %d\n", b, a);
    return 0;
}
```
> What is the program state after line 7? Line 8? Line 9?
>> After
---
>> Line 7: a=5, b=2
---
>> Line 8: a=5, b=5
---
>> Line 9: a=5, b=5

### Question 9.
> Consider the following program:
```c
#include <stdio.h>

int main(void)
{
    int x, y;

    x = 10;
    y = 5;      /* line 7 */

    y = x + y;  /* line 8 */
    x = x * y;  /* line 9 */
    printf("%d %d\n", x, y);
    return 0;
}
```
> What is the program state after line 7? Line 8? Line 9?
>> After
---
>> Line 7: x=10, y=5
---
>> Line 8: x=10, y=15
---
>> Line 9: x=150, y=15
