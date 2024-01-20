# Review Questions

## Question 1.
> Assume all variable are of type `int`. Find the value of each of the
  following variables:
>> a. `x = (2 + 3) * 6;`
>>
>> b. `x = (12 + 6) / 2 * 3;`
>>
>> c. `y = x = (2 + 3) / 4;`
>>
>> d. `y = 3 + 2 * (x = 7 / 2);`
>
> Ans:
>> a. `x`=`30`
>>
>> b. `x`=`27`
>>
>> c. `y`=`x`=`1`
>>
>> d. `y`=`9`, `x`=`3`

## Question 2.
> Assume all variables are of type `int`. Find the value of each of the
  following variables:
>> a. `x = (int) 3.8 + 3.3;`
>>
>> b. `x = (2 + 3) * 10.5;`
>>
>> c. `x = 3 / 5 * 22.0;`
>>
>> d. `x = 22.0 * 3 / 5;`
>
> Ans:
>> a. `x`=`6`
>>
>> b. `x`=`52`
>>
>> c. `x`=`0`
>>
>> d. `x`=`13`

## Question 3.
> Evaluate each of the following expressions:
>> a. `30.0 / 4.0 * 5.0;`
>>
>> b. `30.0 / (4.0 * 5.0);`
>>
>> c. `30 / 4 * 5;`
>>
>> d. `30 * 5 / 4;`
>>
>> e. `30 / 4.0 * 5;`
>>
>> f. `30 / 4 * 5.0;`
>
> Ans:
>> a. `37.5`
>>
>> b. `1.5`
>>
>> c. `35`
>>
>> d. `37`
>>
>> e. `37.5`
>>
>> f. `35.0`

## Question 4.
> You suspect that there are some errors in the next program. Can you find them?
> ```c
> int main(void)
> {
>     int i = 1,
>     float n;
>     printf("Watch out! Here come a bunch of fractions!\n");
>     while (i < 30)
>         n = 1 / i;
>         printf(" %f", n);
>         printf("That's all, folks!\n");
>         return;
> }
> ```
The following is the corrected version:
```c
// include the header file that declares the function used
#include <stdio.h>
int main(void)
{
    int i = 1;      // use semi-colon to end the declaration
    float n;
    printf("Watch out! Here come a bunch of fractions!\n");
    while (i++ < 30)    // increment to avoid infinite loop
    {                   // use compound statement
        n = 1.0 / i;    // correct the division
        printf(" %f", n);
    }
    printf("That's all, folks!\n");

    return 0;           // correct the return statement
}
```

## Question 5.
> Here's an alternative design for Listing 5.9. It appears to simplify the code 
    by replacing the two `scanf()` statements in Listing 5.9 with a single `scanf()` 
    statement. What makes this design inferior to the original?
> ```c
> #include <stdio.h>
> #define S_TO_M 60
> int main(void)
> {
>     int sec, min, left;
>     
>     printf("This program converts seconds to minutes and ");
>     printf("seconds.\n");
>     printf("Just enter the number of seconds.\n")
>     printf("Enter 0 to end the program.\n");
>     while (sec > 0) {
>         scanf("%d", &sec);
>         min = sec/S_TO_M;
>         left = sec % S_TO_M;
>         printf("%d sec is %d min, %d sec.\n", sec, min, left);
>         printf("Next input?\n");
>     }
>     printf("Bye!\n");
>     return 0;
> }
> ```
The major problem of this program is that it does not fetch `sec` before the first 
test case. That means it would be garbage value to be stored in `sec` at the moment
of first test case. One solution is to set the test case `1` (always true), and have 
an `if` statement after fetching `sec` in the compound statement that `break`s the 
loop if `sec` is `<=` 0.

## Question 6.
> What will this program print?
> ```c
> #include <stdio.h>
> #define FORMAT "%s! C is cool!\n"
> int main(void)
> {
>     int num = 10;
> 
>     printf(FORMAT, FORMAT);
>     printf("%d\n", ++num);
>     printf("%d\n", num++);
>     printf("%d\n", num--);
>     printf("%d\n", num);
>     return 0;
> }
> ```
The program should print:
```terminal
%s! C is cool!
! C is cool!
11
11
12
11
```

## Question 7.
> What will the following program print?
```c
#include <stdio.h>
int main(void)
{
    char c1, c2;
    int diff;
    float num;

    c1 = 'S';
    c2 = 'O';
    diff = c1 - c2;
    num = diff;
    printf("%c%c%c:%d %3.2f\n", c1, c2, c1, diff, num);
    return 0;
}
```
The above program should print:
```terminal
SOS:4 4.00
```

## Question 8.
> What will this program print?
```c
#include <stdio.h>
#define TEN 10
int main(void)
{
    int n = 0;

    while (n++ < TEN)
        printf("%5d", n);
    printf("\n");
    return 0;
}
```
The above program should print:
```terminal
    1    2    3    4    5    6    7    8    9   10
```

## Question 9.
> Modify the last program so that it prints the letters a through g instead.
The modified program:
```c
#include <stdio.h>
int main(void)
{
    char c = 'a';

    while (c <= 'g')
        printf("%5c", c++);
    printf("\n");
    return 0;
}
```

## Question 10.
> If the following fragments were part of a complete program, what would they print?
>
> a.
> ```c
> int x = 0;
> 
> while (++x < 3)
>     printf("%4d", x);
> ```
> 
> b.
> ```c
> int x = 100;
> 
> while (x++ < 103)
>     printf("%4d\n", x);
>     printf("%4d\n", x);
> ```
> 
> c.
> ```c
> char ch = 's';
> 
> while (ch < 'w')
> {
>     printf("%c", ch);
>     ch++;
> }
> printf("%c\n", ch);
> ```
They should print:

a.
```terminal
   1   2   3
```

b.
```terminal
101
102
103
104
```

c.
```terminal
stuvw
```

## Question 11.
> What will the following program print?
> ```c
> #define MESG "COMPUTER BYTES DOG"
> #include <stdio.h>
> int main(void)
> {
>     int n = 0;
> 
>     while (n < 5)
>         printf("%s\n", MESG);
>         n++;
>     printf("That's all.\n");
>     return 0;
> }
> ```
As `n` is not incremented in the while statement, this program will print the 
statement "COMPUTER BYTES DOG" indefinitely.

## Question 12.
> Construct statements that do the following (or, in other terms, have the
following side effects):
>> a. Increase the variable `x` by 10.
>>
>> b. Increase the variable `x` by 1.
>>
>> c. Assign twice the sum of `a` and `b` to `c`;
>>
>> d. Assign `a` plus twice `b` to `c`.
Ans:
- a. `x = x + 10;`
- b. `x++;`
- c. `c = 2 * (a + b);`
- d. `c = a + 2 * b;`

## Question 13.
> Construct statements that do the following:
>> a. Decrease the variable `x` by 1.
>> 
>> b. Assigns to `m` the remainder of `n` divided by `k`.
>> 
>> c. Divide `q` by `b` minus `a` and assign the result to `p`.
>> 
>> d. Assign to `x` the result of dividing the sum of `a` and `b` by the product of
>> `c` and `d`.
Ans:
- a. `x--;`
- b. `m = n % k;`
- c. `p = q / b - a;`
- d. `x = (a + b) / (c * d);`
