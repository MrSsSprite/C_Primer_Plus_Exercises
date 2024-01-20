# Chapter 7. Control Statements: Branching and Jumps
## Review Questions

### Question 1.
> Determine which expressions are `true` and which are `false`.
>> a. `100 > 3 && 'a' > 'c'`
>> b. `100 > 3 || 'a' > 'c'`
>> c. `!(100 > 3)`

- a. `false`
- b. `true`
- c. `false`

### Question 2.
> Construct an expression to express the following conditions:
>> a. `number` is equal to or greater than 90 but smaller than 100.
>> b. `ch` is not a `q` or a `k` character.
>> c. `number` is between 1 and 9 (including the end values) but not a 5.
>> d. `number` is not between 1 and 9.

- a. `number >= 90 && number < 100`
- b. `ch != 'q' && ch != 'k'`
- c. `number >= 1 && number <= 9 && number != 5`
- d. `!(number >= 1 && number <= 9)` or `number < 1 || number > 9`

### Question 3.
> The following program has unnecessarily complex relational expressions as well as some 
  outright errors. Simplify and correct it.
> ```c
> #include <stdio.h>
> int main(void)
> {
>     int weight, height;
>     scanf("%d", weight, height);
>     if (weight < 100 && height > 64)
>         if (height >= 72)
>             printf("You are very tall for your weight.\n");
>         else if (height < 72 && > 64)
>             printf("You are tall for your weight.\n");
>     else if (weight > 300 && ! (weight <= 300)
>              && height < 48)
>         if (!(height >= 48) )
>             printf(" You are quite short for your weight.\n");
>     else
>         printf("Your weight is ideal.\n");
> 
>     return 0;
> }
> ```

The revised version:
```c
#include <stdio.h>
int main(void)
{
    int weight, height;
    scanf("%d %d", weight, height);
    if (weight < 100)
    {
        if (height >= 72)
            printf("You are very tall for your weight.\n");
        else if (height > 64)
            printf("Your are tall for your weight.\n");
    }
    else if (weight > 300 && height < 48)
        printf("You are quite short for your weight.\n");
    else
        printf("Your weight is ideal.\n");

    return 0;
}
```

### Question 4.
> What is the numerical value of each of the following expressions?
>> a. `5 > 2`
>
>> b. `3 + 4 > 2 && 3 < 2`
>
>> c. `x >= y || y > x`
>
>> d. `d = 5 + ( 6 > 2 )`
>
>> e. `'X' > 'T' ? 10 : 5`
>
>> f. `x > y ? y > x : x > y`

- a. `1`
- b. `0`
- c. `1`
- d. `6`
- e. `10`
- f. `0`

### Question 5.
> What will the following program print?
> ```c
> #include <stdio.h>
> int main(void)
> {
>     int num;
>     for (num = 1; num <= 11; num++)
>     {
>         if (num % 3 == 0)
>             putchar('$');
>         else
>             putchar('*');
>             putchar('#');
>         puchar('%');
>     }
>     putchar('\n');
>     return 0;
> }
> ```

The output should be:
```terminal
*#%*#%$%*#%*#%$%*#%*#%$%*#%*#%

```

### Question 6.
> What will the following program print?
> ```c
> #include <stdio.h>
> int main(void)
> {
>     int i = 0;
>     while (i < 3) {
>         switch(i++) {
>             case 0 : printf("fat ");
>             case 1 : printf("hat ");
>             case 2 : printf("cat ");
>             default: printf("Oh no!");
>         }
>         puchar('\n');
>     }
>     return 0;
> }
> ```

The program should print:
```terminal
fat hat cat Oh no!
hat cat Oh no!
cat Oh no!

```

### Question 7.
> What's wrong with this program?
> ```c
> #include <stdio.h>
> int main(void)
> {
>     char ch;
>     int lc = 0;     /* lowercase char count
>     int uc = 0;     /* uppercase char count
>     int oc = 0;     /* other char count
> 
>     while ((ch = getchar()) != '#')
>     {
>         if ('a' <= ch >= 'z')
>             lc++;
>         else if (!(ch < 'A') || !(ch > 'Z')
>             uc++;
>         oc++
>     }
>     printf(%d lowercase, %d uppercase, %d other, lc, uc, oc);
>     return 0;
> }
> ```

The corrected version:
```c
#include <stdio.h>
int main(void)
{
    char ch;
    int lc = 0;     /* lowercase char count */
    int uc = 0;     /* uppercase char count */
    int oc = 0;     /* other char count */

    while ((ch = getchar()) != '#')
    {
        if ('a' <= ch && ch <= 'z')
            lc++;
        else if ('A' <= ch && ch <= 'Z')
            uc++;
        else
            oc++;
    }
    printf("%d lowercase, %d uppercase, %d other\n", lc, uc, oc);

    return 0;
}
```

### Question 8.
> What will the following program print?
> ```c
> /* retire.c */
> #include <stdio.h>
> int main(void)
> {
>     int age = 20;
>     
>     while (age++ <= 65)
>     {
>         if ((age % 20) == 0)    /* is age divisible by 20? */
>             printf("You are %d. Here is a raise.\n", age);
>         if (age = 65)
>             printf("You are %d. Here is your gold watch.\n", age);
>     }
>     return 0;
> }
> ```

The above program prints:
"`You are 65. Here is your gold watch.`"
indefinitely as the test expression in the second if statement in the loop set 
`age` to `65`, and is evaluated as `true`.

### Question 9.
> What will the following program print when given this input?
> ```terminal
> q
> c
> h
> b
> ```
> ```c
> #include <stdio.h>
> int main(void)
> {
>     char ch;
> 
>     while ((ch = getchar()) != '#')
>     {
>         if (ch == '\n')
>             continue;
>         printf("Step1\n");
>         if (ch == 'c')
>             continue;
>         else if (ch == 'b')
>             break;
>         else if (ch == 'h')
>             goto laststep;
>         printf("Step 2\n");
>     laststep:   printf("Step 3\n");
>     }
>     printf("Done\n");
>     return 0;
> }
> ```

The output should be:
```terminal
Step1
Step2
Step3
Step1
Step1
Step3
Step1
Done!

```

### Question 10.
> Rewrite the program in Review Question 9 so that it exhibits the same 
  behavior but does not use a continue or a goto.
```c
#include <stdio.h>
int main(void)
{
    char ch;

    while ((ch = getchar()) != '#')
    {
        if (ch != '\n')
        {
            printf("Step 1\n");
            if (ch == 'b')
                break;
            else if (ch != 'c')
            {
                if (ch != 'h')
                    printf("Step 2\n");
                printf("Step 3\n");
            }
        }
    }
    printf("Done\n");
    return 0;
}
```

## Programming Exercises

### Exercise 1.
> Write a program that reads input until encountering the `#` character and 
  then reports the number of spaces read, the number of newline characters read, 
  and the number of all other characters read.

[source code](Programming_Exercises/ex1.c)

### Exercise 2.
> Write a program that reads input until encountering `#`. Have the program 
  print each input character and its ASCII decimal code. Print eight 
  character-code pairs per line.
>>Suggestion: Use a character count and the modulus operator(`%`) to print a 
  newline character for every eight cycles fo the loop.

Caution: This version is modified so that you can input multiple lines of text 
and get the input only after you enter #. Nevertheless, this requires dynamic 
storage that is not yet taught.

[source code](Programming_Exercises/ex2.c)

### Exercise 3.
> Write a program that reads integers until 0 is entered. After input 
  terminates, the program should report the total number of even integers 
  (excluding the 0) entered, the average value of the even integers, the total 
  number of odd integers entered, and the average value of the odd integers.

[source code](Programming_Exercises/ex3.c)

### Exercise 4.
> Using `if else` statements, write a program that reads input up to `#`, 
  replaces each period with an exclamation mark, replaces each exclamation mark 
  initially present with two exclamation marks, and reports at the end the 
  number of substitutions it has made.

[source code](Programming_Exercises/ex4.c)

### Exercise 5.
> Redo exercise 4 using a `switch`.

[source code](Programming_Exercises/ex5.c)

### Exercise 6.
> Write a program that reads input up to `#` and reports the number of times 
  that the sequence `ei` occurs.

[source code](Programming_Exercises/ex6.c)

### Exercise 7.
> Write a program that requests the hours worked in a week and then prints the 
  gross pay, the taxes, and the net pay. Assume the following:
>> a. Basic pay rate = $10.00/hr
>>
>> b. Overtime (in excess of 40 hours) = time and a half
>>
>> c. Tax rate:
>>> - 15% of the first $300
>>> - 20% of the next $150
>>> - 25% of the rest
>> Use `#define` constants, and don't worry if example does not conform to 
   current tax law.

[source code](Programming_Exercises/ex7.c)

### Exercise 8.
> Modify assumption a. in exercise 7 so that the program presents a menu of pay 
  rates from which to choose. Use a `switch` to select the pay rate. The 
  beginning of a should look something like this:
> ```terminal
> *****************************************************************
> Enter the number corresponding to the desired pay rate or action:
> 1) $8.75/hr                     2) $9.33/hr
> 3) $10.00/hr                    4) $11.20/hr
> 5) quit
> *****************************************************************
> ```
> If choices 1 through 4 are selected, the program should request the hours 
  worked. The program should recycle until 5 is entered. If something other than 
  choices 1 through 5 is entered, the program should remaind the user what the 
  proper choices are and then recycle. Use `#define` constants for the various 
  earning rates and tax rates.

[source code](Programming_Exercises/ex8.c)

### Exercise 9.
> Write a program that accepts a positive integer as input and then displays 
  all the prime numbers smaller than or equal to that number.

[source code](Programming_Exercises/ex9.c)

### Exercise 10.
> The 1988 United States Federal Tax Schedule was the simplest in recent times. 
  It had four categories, and each category had two rates. Here is a summary 
  (dollar amounts are taxable income):
>
> | Category          | Tax                                     |
> | ----------------- | --------------------------------------- |
> | Single            | 15% of first $17,850 plus 28% of excess |
> | Head of Household | 15% of first $23,900 plus 28% of excess |
> | Married, Joint    | 15% of first $29,750 plus 28% of excess |
> | Married, Separate | 15% of first $14,875 plus 28% of excess |
> 
> For example, a single wage earner with a taxable income of $\$20,000$ ows 
  $0.15 \times \$17,850 + 0.28 \times (\$20,000-\$17,850)$. Write a program 
  that lets the user specify the tax category and the taxable income and that 
  then calculates the tax. Use a loop so that the user can enter several tax 
  cases.

[source code](Programming_Exercises/ex10.c)

### Exercise 11.
> The ABC Mail Order Grocery sells artichokes for $\$2.05$ per pound, beets for 
  $\$1.15$ per pound, and carrots for $\$1.09$ per pound. It gives a $5%$ 
  discount for orders of $\$100$ or more prior to adding shipping costs. It 
  charges $\$6.50$ shipping and handling for any order of 5 pounds or under, 
  $\$14.00$ shipping and handling for orders over 5 pounds and under 20 pounds, 
  and $\$14.00$ plus $\$0.50$ per pound for shipments of 20 pounds or more. 
>
> Write a program that uses a `switch` statement in a loop such that a response 
  of `a` lets the user enter the pounds of artichokes desired, `b` the pounds of 
  beets, `c` the pounds of carrots, and `q` allows the user to exit the ordering 
  process. The program should keep track of cumulative totals. That is, if the 
  user enters 4 pounds of beets and later enters 5 pounds of beets, the program 
  should use report 9 pounds of beets. The program then should compute the total 
  charges, the discount, if any, the shipping charges, and the grand total. The 
  program then should display all purchase information: the cost per pound, the 
  pounds ordered, and the cost for that order for each vegetable, the total cost 
  of the order, the discount (if there is one), the shipping charge, and the 
  grand total of all charges.

[source code](Programming_Exercises/ex11.c)
