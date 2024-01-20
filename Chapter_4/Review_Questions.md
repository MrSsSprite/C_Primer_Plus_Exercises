# Review Questions

## Question 1.
> Run Listing 4.1 again, but this time give your first and last name
when it asks you for your first name. What happens? Why?

Only the first name is utilized. The reason is that scanf stops when reaching a
whilespace character, which is typically used to separate your first name and 
last name. Thus, only the first name is recorded into the address.

## Question 2.
> Assuming that each of the following examples is part of a complete program, what 
will each one print?
>> a. `printf("He sold the painting for $%2.2f.\n", 2.345e2);`
>
>> b. `printf("%c%c%c\n", 'H', 105, '\41');`
>
>> c.
>>```c
>>#define Q "His Hamlet was funny without being vulgar."
>>printf("%s\nhas %d characters.\n", Q, strlen(Q));
>>```
>
>> d. `printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);`

- a. He sold the painting for $234.50.
- b. Hi!
- c.
    ```terminal
    His Hamlet was funny without being vulgar.
    has 42 characters.
    ```
- d. Is 1.20e+003 the same as 1201.00?

## Question 3.
> In Question 2c, what changes could you make so that string `Q` is printed
out enclosed in double quotation marks?
>> You can add `\"` to the left and right of `%s`. As in the following:
>>
>> `printf("\"%s\"\nhas %d characters.\n", Q, strlen(Q));`

## Question 4.
> It's find the error here!
> ```c
> define B booboo
> define X 10
> main(int)
> {
>     int age;
>     char name;
> 
>     printf("Please enter your first name.");
>     scanf("%s", name);
>     printf("All right, %c, what's your age?\n", name);
>     scanf("%f", age);
>     xp = age + X;
>     printf("That's a %s! You must be at least %d.\n", B, xp);
> 
>     return 0;
> }
> ```
> The corrected version:
> ```c
> #define B "booboo"
> #define X 10
> int main(void)
> {
>     int age;
>     char name[40];
> 
>     printf("Please enter your first name.\n");
>     scanf("%s", name);
>     printf("All right, %s, what's your age?\n", name);
>     scanf("%d", age);
>     printf("That's a %s! You must be at least %d.\n", B, age + X);
> 
>     return 0;
> }
> ```

## Question 5.
> Suppose a program starts as follows:
> ```c
> #define BOOK "War and Peace"
> int main(void)
> {
>     float cost = 12.99;
>     float percent = 80.0;
> ```
> Construct a `printf()` statement that uses `BOOK`, `cost`, and `percent`
to print the following:
> ```terminal
> This copy of "War and Peace" sells for $12.99.
> That is 80% of list.
> ```
>> Solution:
```c
#define BOOK "War and Peace"
int main(void)
{
    float cost = 12.99;
    float percent = 80.0;

    printf("This copy of \"%s\" sells for $%f.\n", BOOK, cost);
    printf("That is %.0f of list.\n", percent);

    return 0;
}
```

## Question 6.
> What conversion specification would you use to print each of the following?
>
> - a. A decimal integer with a field width equal to the number of digits
> - b. A hexadecimal integer in the form 8A in a field width of 4
> - c. A floating-point number in the form 232.346 with a field width of 10
> - d. A floating-point numbber in the form 2.33e+002 with a field width of 12
> - e. A string left-justified in a field of width 30
>
> Ans:
> - a. `%d`
> - b. `%4X`
> - c. `%10.3f`
> - d. `%12.2e`
> - e. `%-30s`

## Question 7.
> Which **conversion specification** would you use to print each of the following?
> - a. An `unsigned long` integer in a field width of 15
> - b. A hexadecimal integer in the form `0x8a` in a field width of 4
> - c. A floating-point number in the form `2.33E+02` that is left-justified to
        a field width of 12
> - d. A floating-point number in the form `+232.346` in a field width of 10
> - e. The first eight characters of a string in a field eight characters wide
>
> Ans:
> - a. `%15lu`
> - b. `%#4x`
> - c. `%-12.2E`
> - d. `%+10.3f`
> - e. `%8.8s` or equivalently `%.8s` (only if the string is guaranteed to be at
least 8 characters long)

## Question 8.
> What **conversion specification** would you use to print each of the following?
> - a. A decimal integer having a minimum of four digits in a field width of 6
> - b. An octal integer in a field whose width will be given in the argument
        list
> - c. A character in a field width of 2
> - d. A floating point number in the form `+3.13` in a field width equal to the 
        number of characters in the number
> - e. The first five characters in a string left-justified in a field of width 7
>
> Ans:
> - a. `%6.4d`
> - b. `%*o`
> - c. `%2c`
> - d. `%+.2f`
> - e. `%-7.5s`

## Question 9.
> For each of the following input lines, provide a `scanf()` statement to read it.
Also declare any variables or arrays used in the statement.
> - a. `101`
> - b. `22.32 8.34E-09`
> - c. `linguini`
> - d. `catch 22`
> - e. `catch 22` (but skip over catch)
>
> Ans:
> ```c
> int iVal;
> float fVal0, fVal1;
> char str[40];
> scanf("%d", &iVal);                 // a
> scanf("%f %e", &fVal0, &fVal1);     // b
> scanf("%s", str);                   // c
> scanf("%s %d", str, &iVal);         // d
> scanf("%*s %d", &iVal);             // e
> ```

## Question 10.
> What is whitespace?
>> In C++, whitespace involves newline character ('\n'), plain space (' '), and 
tab ('\t');

## Question 11.
> What's wrong with the following statement and how can you fix it?
>
> `printf("The double type is %z bytes..\n", sizeof (double));`
>> The problem in the statement is that the `z` after `%` is modifier character
but not specifier. Thus, it is not a valid specifier. To correct the statement, 
you can add a valid specifier after the modifier `z`. For example, `%zd` would 
print the expression in decimal base, or `%zx` would print the expression in 
hexidecimal base, and so on.

## Question 12.
> Suppose that you would rather use parentheses than braces in your programs.
How well would the following word?
> ```c
> #define ( {
> #define ) }
> ```
>> The above would be problematic as all the `(` and `)` would be replaced by 
`{` and `}` respectively. That means you cannot commit any function call as 
there is no way to write a true `(` or `)`.
