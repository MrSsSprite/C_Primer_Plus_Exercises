# Chapter 9. Functions

## Review Questions

### Question 1.
> What is the difference between an actual argument and a formal parameter?
An actual argument is the value passed to a function when the function is 
called

In comparison, a formal parameter is a static varible that is declared in a 
function and initialized using the corresponding actual argument.

### Question 2.
> Write ANSI C function headings for the following functions described. Note we 
  are asking just for the headings, not the body.
>> a. `donut()` takes an `int` argument and prints that number of `0`s.
>>
>> b. `gear()` takes two `int` arguments and returns type `int`.
>>
>> c. `guess()` takes no arguments and returns an `int` value.

- a. `void donut(int n);`
- b. `int gear(int, int);`
- c. `int guess(void);`

### Question 3.
> Write ANSI C function headings for the following functions described. Not 
  that you need write only the headings, not the body.
>> a. `n_to_char()` takes an `int` argument and returns a `char`.
>>
>> b. `digits()` takes a `double` argument and an `int` argument and returns an 
      `int`.
>>
>> c. `which()` takes two addresses of `double` as arguments and returns the 
      address of a `double`.
>>
>> d. `random()` takes no argument and returns an `int`.

- a. `char n_to_char(int n)`
- b. `int digits(double n, int m)`
- c. `double *which(double *a, double *b)`
- d. `int random(void)`

### Question 4.
> Devise a function that returns the sum of two integers.

```c
int sum(int a, int b) { return a + b; }
```

### Question 5.
> What changes, if any, would you need to make to have the function of question 
  4 add two `double` numbers instead?

To achieve that, you need to merely change the signature of the function. 
Change the return type, and arguments' type to `double`.

### Question 6.
> Devise a function called `alter()` that takes two `int` variables, `x` and 
  `y`, and changes their values to their sum and their difference, 
  respectively.

```c
#include <stdlib.h>
void alter(int *x, int *y)
{
    int temp[2] = {*x, *y};
    *x = temp[0] + temp[1];
    *y = abs(temp[1] - temp[0]);
}
```

### Question 7.
> Is anything wrong with this function definition?
> ```c
> void salami(num)
> {
>     int num, count;
> 
>     for (count = 1; count <= num; num++)
>         printf(" O salami mio!\n");
> }
> ```

The declaration for `num` should be in the parameter list, instead of in the 
function body.
Logically, the function should increment `count` instead of `num` in the 
increment section of the for loop.

### Question 8.
> Write a function that returns the largest of three integer arguments.

```c
int largest(int a, int b, int c)
{
    if (b > a)
        a = b;
    if (c > a)
        a = c;
    return a;
}
```

### Question 9.
> Given the following output:
> ```terminal
> Please choose one of the following:
> 1) copy files           2) move files
> 3) remove files         4) quit
> Enter the number of your choice:
> ```
>> a. Write a function that displays a menu of four numbered choices and asks 
      you to choose one. (The output should look like the preceding.)
>>
>> b. Write a function that has two `int` arguments: a lower limit and an upper 
      limit. The function should read an integer from input. If the integer is 
      outside the limits, the function should print a menu again (using the 
      function from part "a" of this question) to reprompt the user and then 
      get a new value. When an integer in the proper limits is entered, the 
      function should return that value to the calling function. Entering a 
      noninteger should cause the function to return the quit value of 4.
>>
>> c. Write a minimal program using the functions from parts "a" and "b" of 
      this question. By *minimal* we meant it need not actually perform the 
      actions promised by the menu; it should just show the choices and get a 
      valid response.

- a.
    ```c
    void menu(void)
    {
        printf("Please choose one of the following:\n"
               "1) copy files           2) move files\n"
               "3) remove files         4) quit\n"
               "Enter the number of your choice: ");
    }
    ```
- b.
    ```c
    int get_cmd(const int low, const int up)
    {
        int ret;
        int good;

        while ((good = scanf("%d", &ret)) == 1
               && (ret < low || ret > up))
        {
            printf("%d is not a valid choice\n", ret);
            menu();
        }
        if (good != 1)
        {
            printf("Non-numeric Input\n");
            return 4;
        }
        return ret;
    }
    ```
- c.
    ```c
    int main(void)
    {
        int cmd;

        while (menu(),
               (cmd = get_cmd()) != 4)
            printf("You chose %c.\n", cmd);

        return 0;
    }
    ```

## Programming Exercises

### Exercise 1.
> Devise a function called `min(x, y)` that returns the smaller of two `double` 
  values. Test the function with a simple driver.

[source code](Programming_Exercises\ex1.c)

### Exercise 2.
> Devise a function `chline(ch, i, j)` that prints the requested character in 
  columns `i` through `j`. Test it in a simple driver.

[source code](Programming_Exercises\ex2.c)

### Exercise 3.
> Write a function that takes three arguments: a character and two integers. 
  The character is to be printed. The first integer specifies the number of 
  times that the character is to be printed on a line, and the second integer 
  specifies the number of lines that are to be printed. Write a program that 
  makes use of this function.

[source code](Programming_Exercises\ex3.c)

### Exercise 4.
> The harmonic mean of two numbers is obtained by taking the inverses of the 
  two numbers, averaging them, and taking the inverse of the result. Write a 
  function that takes two `double` arguments and returns the harmonic mean of 
  the two numbers.

[source code](Programming_Exercises\ex4.c)

### Exercise 5.
> Write and test a function called `larger_of()` that replaces the contents of 
  two `double` variables with the maximum of the two values. For example, 
  `larger_of(x, y)` would reset both `x` and `y` to the larger of the two.

[source code](Programming_Exercises\ex5.c)

### Exercise 6.
> Write and test a function that takes the addresses of three `double` 
  variables as arguments and that moves the value of the smallest variable into 
  the first variable, the middle value to the second variable, and the largest 
  value into the third variable.

[source code](Programming_Exercises\ex6.c)

### Exercise 7.
> Write a program that reads characters from the standard input to end-of-file. 
  For each character, have the program report whether it is a letter. If it is 
  a letter, also report its numerical location in the alphabet. For example, 
  `c` and `C` would both be letter 3. Incorporate a function that takes a 
  character as an argument and returns the numerical location if the character 
  is a letter and that returns `-1` otherwise.

[source code](Programming_Exercises\ex7.c)

### Exercise 8.
> Chapter 6, "C Control Statements: Looping," (Listing 6.20) shows a `power()` 
  function that returned the result of raising a type `double` number to a 
  positive integer value. Improve the function so that it correctly handles 
  negative powers. Also, build into the function that 0 to any power other than 
  0 is 0 and that any number to the 0 power is 1.

[source code](Programming_Exercises\ex8.c)

### Exercise 9.
> Redo Programming Exercise 8, but this time use a recursive function.

[source code](Programming_Exercises\ex9.c)

### Exercise 10.
> Generalize the `to_binary()` function of Listing 9.8 to `to_base_n()` 
  function that takes a second argument in the range 2 - 10. It then should 
  print the number that is its first argument to the number base given by the 
  second argument. For example, `to_base_n(129, 8) would display 201, the 
  base-8 equivalent of 129. Test the function in a complete program.

[source code](Programming_Exercises\ex10.c)

### Exercise 11.
> Write and test a `Fibonacci()` function that uses a loop instead of recursion 
  to calculate  numbers.

[source code](Programming_Exercises\ex11.c)
