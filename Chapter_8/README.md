# Chapter 8. Character Input/Output and Input Validation

## Review Questions

### Question 1.
> `putchar(getchar())` is a valid expression; what does it do? Is 
  `getchar(putchar())` also valid?

`putchar(getchar())` get a character from `stdin` input stream and print that 
character to `stdout` output stream.
`getchar(putchar())`, however, is not valid. First, `putchar` takes an argument.
Second, `getchar` takes no argument.

### Question 2.
> What would each of the following statements accomplish?
>> a. `putchar('H');`
>>
>> b. `putchar('\007');`
>>
>> c. `putchar('\n');`
>>
>> d. `putchar('\b');`

- a. Display the `H` character
- b. Sound the alert if the system uses ASCII.
- c. Move the cursor to the beginning of the next line.
- d. Backspace.

### Question 3.
> Suppose you have an executable program named `count` that counts the 
  characters in its input. Devise a command-line command using the `count` 
  program to count the number of characters in the file `essay` and to store 
  the result in a file named `essayct`.

The command-line command should be:
`./count <essay >essayct`

Note that windows powershell use a difference approach for input redirection:
`Get-Content essay | .\count >essayct`

### Question 4.
> Given the program and files in question 3, which of the following are valid 
  commands?
>> a. `essayct <essay`
>> b. `count essay`
>> c. `essay >count`

None are valid

### Question 5.
> What is `EOF`?

`EOF` is a special value returned by input stream functions like `getchar()` 
and `scanf()` to indicate the end of a file.

### Question 6.
> What is the output of each of the following fragments for the indicated input 
  (assume that `ch` is type `int` and that the input is buffered)?
>> a. The input is as follows:
>> ```terminal
>>  If you quit, will.[enter]
>> ```
>> The fragment is as follows:
>> ```c
>> while ((ch = getchar()) != 'i')
>>   putchar(ch);
>> ```
>
>> b. The input is as follows:
>> ```terminal
>> Harhar[enter]
>> ```
>> The fragment is as follows:
>> ```c
>> while ((ch = getchar()) != '\n')
>> {
>>     putchar(ch++);
>>     putchar(++ch);
>> }
>> ```

- a. `If you qu`
- b. `HJacrthjacrt`

### Question 7.
> How does C deal with different computers systems having different file and 
  newline conventions?

C's standard I/O library maps diverse file forms to uniform streams that can 
be handled equivalently.

### Question 8.
> What potential problem do you face when intermixing numeric input with 
  character input on buffered system?

Numeric input skips over spaces and newlines, but character input does not. 
That means you have to handle carefully the remnant that is left in the stream 
(because of the mechanism of `scanf`) so that the remnant does not affect the 
following sections or iterations.

## Programming Exercises

### Exercises 1.
> Devise a program that counts the number of characters in its input up to the 
  end of file.

[source code](Programming_Exercises\ex1.c)

### Exercise 2.
> Write a program that reads input as a stream of characters until encountering 
  `EOF`. Have the program print each input character and its ASCII decimal 
  value. Note that characters preceding the space character in the ASCII 
  sequence are nonprinting characters. Treat them specially. If the nonprinting 
  character is a newline or tab, print `\n` or `\t`, respectively. Otherwise, 
  use control-character notation. For instance, ASCII 1 is Ctrl+A, which can be 
  displayed as `^A`. Note that the ASCII value for `A` is the value for Ctrl+A 
  plus 64. A similar relation holds for the other nonprinting characters. Print 
  10 pairs per line, except start a fresh line each time a newline character is 
  encountered. (Note: The operating system may have special interpretations for 
  some control characters and keep them from reaching the program.)

[source code](Programming_Exercises\ex2.c)

### Exercise 3.
> Write a program that reads input as a stream of characters until encountering 
  `EOF`. Have it report the number of uppercase letters, the number of 
  lowercase letters, and the number of other characters in the input. You may 
  assume that the numeric values for the lowercase letters are sequential and 
  assume the same for uppercase. Or, more portably, you can use appropriate 
  classification functions from the `ctype.h` library.

[source code](Programming_Exercises\ex3.c)

### Exercise 4.
> Write a program that reads input as a stream of characters until encountering 
  `EOF`. Have it report the average number of letters per word. Don't count 
  whitespace as letters in a word. Actually, punctuation shouldn't be counted 
  either, but don't worry about that now. (If you do want to worry about it, 
  consider using the `ispunct()` function from the `ctype.h` family.)

[source code](Programming_Exercises\ex4.c)

### Exercise 5.
> Modify the guessing program of Listing 8.4 so that it uses a more intelligent 
  guessing strategy. For example, have the program initially guess 50, and have 
  it ask the user whether the guess is high, low, or correct. If, say, the 
  guess is low, have the next guess be halfway between 50 and 100, that is, 75. 
  If that guess is high, let the guess be halfway between 75 and 50, and so on. 
  Using this **binary search** strategy, the program quickly zeros in the 
  correct answer, at least if the user does not cheat.

[source code](Programming_Exercises\ex5.c)

### Exercise 6.
> Modify the `get_first()` function of Listing 8.8 so that it returns the first 
  non-whitespace character encountered. Test it in a simple program.

A sub-function of the source code of execise 5 implements that already.

### Exercise 7.
> Modify the Programming Exercise 8 from Chapter 7 so that the menu choices are 
  labeled by characters instead of by numbers; use `q` instead of `5` as the 
  cue to terminate input.

### Exercise 8.
> Write a program that shows you a menu offering you the choice of addition, 
  subtraction, multiplication, or division. After getting your choice, the 
  program asks for two numbers, then performs the requested operation. The 
  program should accept only the offered menu choices. It should use type 
  `float` for the numbers and allow the user to try again if he or she fails to 
  enter a number. In the case of division, the program should prompt the user 
  to enter a new value if `0` is entered as the value for the second number. A 
  typical program run should look like this:
> ```terminal
> Enter the operation of your choice:
> a. add          s. subtract
> m. multiply     d. divide
> q. quit
> a
> Enter first number: 22.4
> Enter second number: one
> one is not an number.
> Please enter a number, such as 2.5, -1.78E8, or 3: 1
> 22.4 + 1 = 23.4
> Enter the operation of your choice:
> a. add          s. subtract
> m. multiply     d. divide
> q. quit
> d
> Enter first number: 18.4
> Enter second number: 0
> Enter a number other than 0: 0.2
> 18.4 / 0.2 = 92
> Enter the operation of your choice:
> a. add          s. subtract
> m. multiply     d. divide
> q. quit
> q
> Bye.
> 
> ```

[source code](Programming_Exercises\ex8.c)
