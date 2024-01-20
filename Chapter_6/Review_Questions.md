# Review Questions

## Question 1.
> Find the value of `quack` after each line; each of the final five statements 
  uses the value of `quack` produced by the preceding statement.
> ```c
> int quack = 2;
> quack += 5;
> quack *= 10;
> quack -= 6;
> quack /= 8;
> quack %= 3;
> ```
The value of `quack` in each line is listed below:
1. 2
2. 7
3. 70
4. 64
5. 8
6. 2

## Question 2.
> Given that `value` is an `int`, what ouput would the following loop produce?
> ```c
> for ( value = 36; value > 0; value /= 2)
>     printf("%3d", value);
> ```
> What problems would there be if `value` were `double` instead of `int`?
If `value` were `double` instead of `int`, this code will be executed many
times until `value` underflows and gets the value 0. Also the specifier 
`"%3d"` malfunctions.

## Question 3.
> Represent each of the following conditions:
> - a. x is greater than 5.
> - b. `scanf()` attempts to read a single `double` (called `x`) and fails.
> - c. `x` has the value `5`.
Ans:
> - `x > 5`
> - `scanf("%lf", &x) != 1`
> - `x == 5`

## Question 4.
> Represent each of the following test conditions:
> - a. `scanf()` succeeds in reading a single integer.
> - b. `x` is not 5.
> - c. `x` is `20` or greater.
Ans:
- a. `scanf("%d", &iVal) == 1`
- b. `x != 5`
- c. `x >= 20`

## Question 5.
> You suspect that the following program is not perfect.
What errors can you find?
> ```c
> #include <stdio.h>
> int main(void)
> {
>     int i, j, list(10);
> 
>     for (i = 1, i <= 10, i++)
>     {
>         list[i] = 2*i + 3;
>         for (j = 1, j > = i, j++)
>             printf(" %d", list[j]);
>         printf("\n");
>     }
> ```
The corrected version:
```c
#include <stdio.h>
int main(void)
{
    int i, j, list[10];     // use brackets to declare an array

    for (i = 0; i < 10; i++)    // semicolon to separate, from 0 - 9
    {
        list[i] = 2 * i + 3;
        for (j = 0; j <= i; j++)    // zero indexed and up to i
            printf("%d", list[j]);
        printf("\n");
    }
    // complete the rest
    return 0;
}
```

## Question 6.
> Use nested loops to write a program that produces this pattern:
> ```terminal
> $$$$$$$$
> $$$$$$$$
> $$$$$$$$
> $$$$$$$$
> ```
Solution:
```c
#include <stdio.h>
int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
            printf("$");
        printf("\n");
    }

    return 0;
}
```

## Question 7.
> What will each of the following programs print?
> - a.
> ```c
> #include <stdio.h>
> 
> int main(void)
> {
>     int i = 0;
> 
>     while (++i < 4)
>         printf("Hi!");
>     do
>         printf("Bye! ");
>     while (i++ < 8);
>     return 0;
> }
> ```
> - b.
> ```c
> #include <stdio.h>
> 
> int main(void)
> {
>     int i;
>     char ch;
> 
>     for (i = 0, ch 'A'; i < 4; i++, ch += 2 * i)
>         printf("%c", ch);
>     return 0;
> }
> ```
Ans:
- a. `Hi! Hi! Hi! Bye! Bye! Bye! Bye! Bye!`
- b. `ACGM`

## Question 8.
> Given the input `Go west, young man!`, what would each of the following 
  programs produce for output? (The `!` follows the space character in the 
  ASCII sequence.)
>
>> a.
>> ```c
>> #include <stdio.h>
>> int main(void)
>> {
>>     char ch;
>> 
>>     scanf("%c", &ch);
>>     while (ch != 'g')
>>     {
>>         printf("%c", ch);
>>         scanf("%c", &ch);
>>     }
>>     return 0;
>> }
>> ```
>
>> b.
>> ```c
>> #include <stdio.h>
>> int main(void)
>> {
>>     scanf("%c", &ch);
>>     while ( ch != 'g' )
>>     {
>>         printf("%c", ++ch);
>>         scanf("%c", &ch);
>>     }
>>     return 0;
>> }
>> ```
>
>> c.
>> ```c
>> #include <stdio.h>
>> 
>> int main(void)
>> {
>>     char ch;
>> 
>>     do {
>>         scanf("%c", &ch);
>>         printf("%c", ch);
>>     } while ( ch != 'g' );
>>     return 0;
>> }
>> ```
>
>> d.
>> ```c
>> #include <stdio.h>
>> 
>> int main(void)
>> {
>>     char ch;
>> 
>>     scanf("%c", &ch);
>>     for ( ch = '$'; ch != 'g'; scanf("%c", &ch) )
>>         printf("%c", ch);
>> 
>>     return 0;
>> }
>> ```
Outputs:
--------
- a. `Go west, youn`
- b. `Hp!xftu-!zpvo`
- c. `Go west, young`
- d. `$o west, youn`

## Question 9.
> What will the following program print?
> ```c
> #include <stdio.h>
> int main(void)
> {
>     int n, m;
> 
>     n = 30;
>     while (++n <= 33)
>         printf("%d|", n);
> 
>     n = 30;
>     do
>         printf("%d|", n);
>     while (++n <= 33);
> 
>     printf("\n***\n");
> 
>     for (n = 1; n*n < 200; n += 4)
>         printf("%d\n", n);
> 
>     printf("\n***\n");
> 
>     for (n = 2, m = 6; n < m; n *= 2, m += 2)
>         printf("%d %d\n", n, m);
> 
>     printf("\n***\n");
> 
>     for (n = 5; n > 0; n--)
>     {
>         for (m = 0; m <= n; m++)
>             printf("=");
>         printf("\n");
>     }
>     return 0;
> }
> ```
Output:
```terminal
31|32|33|30|31|32|33|
***
1
5
9
13

***
2 6
4 8
8 10

***
======
=====
====
===
==

```

## Question 10.
> Consider the following declaration:
> ```c
> double mint[10];
> ```
>> a. What is the array name?
>> b. How many elements does the array have?
>> c. What kind of value can be stored in each element?
>> d. Which of the following is correct usage of `scanf()` with this array?
>>> 1. `scanf("%lf", mint[2])`
>>> 2. `scanf("%lf", &mint[2])`
>>> 3. `scanf("%lf", &mint)`
Ans:
- a. `mint`
- b. 10 elements
- c. `double`
- d. the second usage is correct.

## Question 11.
> Mr. Noah likes counting by twos, so he's written the following to create an
  array and to fill it with the integers 2, 4, 6, 8, and so on. What, if 
  anything, is wrong with this program?
> ```c
> #include <stdio.h>
> #define SIZE 8
> int main(void)
> {
>     int by_twos[SIZE];
>     int index;
> 
>     for (index = 1; index <= SIZE; index++)
>         by_twos[index] = 2 * index;
>     for (index = 1; index <= SIZE; index++)
>         printf("%d ", by_twos);
>     printf("\n");
>     return 0;
> }
> ```
The corrected version:
```c
#include <stdio.h>
#define SIZE 8
int main(void)
{
    int by_twos[SIZE];
    int index;

    for (index = 0; index < SIZE; index++)
        by_twos[index] = (index + 1) * 2;
    for (index = 0; index < SIZE; index++)
        printf("%d ", by_twos[index]);
    printf("\n");
    return 0;
}
```

## Question 12.
> You want to write a function that returns a `long` value. What should your 
  definition of the function include?
It should declare the return type as `long`, and it should have a `return` 
statement that returns a `long` value.

## Question 13.
> Define a function that takes an `int` argument and that returns, as a `long`,
  the square of that value.
```c
long square_it(int value) { return (long) value * value; }
```

## Question 14.
> What will the following program print?
> ```c
> #include <stdio.h>
> int main(void)
> {
>     int k;
>     for (k = 1, printf("%d: Hi!\n", k);
>          printf("k = %d\n", k), k*k < 26;
>          k += 2, printf("Now k is %d\n", k) )
>       printf("k is %d in the loop\n", k);
> 
>     return 0;
> }
> ```
The output should be:
```terminal
1: Hi!
k = 1
k is 1 in the loop
Now k is 3
k = 3
k is 3 in the loop
Now k is 5
k = 5
k is 5 in the loop
Now k is 7
k = 7

```
