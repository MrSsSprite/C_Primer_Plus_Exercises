# Programming Exercise
Reading about C isn't enough. You should try writing one or two simple programs
to see whether writing a program goes as smoothly as it looks in this chapter.
A few suggestions follow, but you should also try to think up some problems yourself.
You'll find answers to selected programming exercises on the publisher's website.

## Question 1.
> Write a program that uses one `printf()` call to print your first name and last name on one line,
and uses a second `printf()` call to print your first and last names on two separate lines,
and uses a pair of `printf()` calls to print your first and last names on one line.
The output should look like this (but using your name):
```terminal
Gustav Mahler
Gustav
Mahler
Gustav Mahler
```

[source code](ex1.c)

## Question 2.
> Write a program to print your name and address.

[source code](ex2.c)

## Question 3.
> Write a program that converts your age in years to days and displays both values.
At this point, dont't worry about fractional years and leap years.

[source code](ex3.c)

## Question 4.
> Write a program that produces the following output:
```terminal
For he's a jolly good fellow!
For he's a jolly good fellow!
For he's a jolly good fellow!
Which nobody can deny!
```
> Have the program use the user-defined functions in addtion to `main()`:
- one named `jolly()` that prints the "jolly good" message once, and
- one named `deny()` that prints the final line once.

[source code](ex4.c)

## Question 5.
> Write a program that produces the following output:
```terminal
Brazil, Russia, India, China
India, China,
Brazil, Russia
```
> Have the program use two user defined functions in addition to `main()`:
- one named `br()` that prints "Brazil, Russia" once, and
- one named `ic()` that prints "India, China" once.
> Let `main()` take care of any additional printing tasks.

[sources code](ex5.c)

## Question 6.
> Write a program that creates an integer variable called `toes`.
Have the program set `toes` to `10`.
Also have the program calculate what twice `toes` is and what `toes` squared is.
The program should print all three values, identifying them.

[source code](ex6.c)

## Question 7.
> Many studies suggest that smiling has benefits. Write a program that produces the 
following output:
```terminal
Smile!Smile!Smile!
Smile!Smile!
Smile!
```

[source code](ex7.c)

## Question 8.
> In C, one function can call another. Write a program that calls a function named `one_
three()`. This function should display the word `one` on one line, call a second function 
named `two()`, and then display the word `three` on one line. The function `two()` should 
display the word `two` on one line. The `main()` function should display the phrase 
`starting now:` before calling `one_three()` and display `done!` after calling it. Thus, the 
output should look like the following:
```terminal
starting now:
one
two
three
done!
```

[source code](ex8.c)
