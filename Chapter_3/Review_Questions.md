# Review Questions

## Question 1.
> Which data type would you use for each of the following kinds of data
(sometimes more than one type could be appropriate)?
> - a. The population of East Simpleton
> - b. The cost of a movie DVD
> - c. The most common letter in this chapter
> - d. The number of times that the letter occurs in this chapter
>> - a. `short`, as it is quite a small value if you try to google it.
>> - b. `float`, the value should not require more than six significant figures
>> - c. `char`
>> - d. `unsigned int` (or long)

## Question 2.
> Why would you use a type `long` variable instead of type `int`?
>> The type `long` accommodate larger numbers. In addition,
even if `long` and `int` have the same size in the system, using
`long` make it more portable in that it guarantees 32 bits on all systems.

## Question 3.
> What portable types might you use to get a 32-bit signed integer,
and what would the rationale be for each choice?
>> `int32_t`. Alternatively, to get the smallest type that could store
at least 32 bits, use `int_least32_t`. And to get the type that would
provide the fastest computations for 32 bits, choose `int_fast32_t`.

## Question 4.
> Identify the type and meaning, if any, of each of the following constants:
> - a. `'\b'`
> - b. `1066`
> - c. `99.44`
> - d. `0XAA`
> - e. `2.0e30`
>> - a. char, move cursor backward
>> - b. int, 1066
>> - c. double, 99.44
>> - d. unsigned int, 176
>> - e. double, 2.0 * pow(10, 30);

## Question 5.
> Dottie Cawm has concacted an error-laden program. Help her find the mistakes.
```c
include <stdio.h>
main
(
  float g; h;
  float tax, rate;

  g = e21;
  tax = rate * g;
)
```
1. Should be `#include <stdio.h>`
2. Should be `int main(void)`
3. Should be `{` instead of `(`
4. Either use `,` to replace `;`, or add `float` before h.
5. Fine
6. Fine (Empty Line)
7. Should be either 1e21 or 1.0e21
8. Fine
9. Should be `}` instead of `)`

Other Problems:
- `h` is never used
- `rate` is used without assigned any value, which is an undefined behavior
- Except for the default return value no meaningful value is outputted,
the values are simply computed, and discarded when the program ends.
- `return`, which is not strictly required for `main` but recommended,
is not explicitly involved

## Question 6.
> Identify the data type (as used in declaration statements) and
the `printf()` format specifier for each of the following constants:

| Constant | Type | Specifier |
| -------- | ---- | --------- |
| 12  | | |
| 0X3 | | |
| 'C' | | |
| 2.34E07| | |
| '\040' | | |
| 7.0 | | |
| 6L | | |
| 6.0f | | |
| 0x5.b6p12 | | |

Ans:
----
| Constant | Type | Specifier |
| -------- | ---- | --------- |
| 12  | `int` | `%d` |
| 0X3 | `unsigned int` | `%#X` |
| 'C' | `char` | `%c` |
| 2.34E07| `double` | `%f` |
| '\040' | `char` | `%c` |
| 7.0 | `double` | `%.1f` |
| 6L | `long` | `%ld` |
| 6.0f | `float` | `%.1f` |
| 0x5.b6p12 | `float` | `%a` |

## Question 7.
> Identify the data type (as used in declaration statements) and
the `printf()` format specifier for each of the following constants
(assume a 16-bit `int`):

| Constant | Type | Specifier |
| -------- | ---- | --------- |
| 012 | | |
| 2.9e05L | | |
| 's' | | |
| 100000 | | |
| '\n' | | |
| 20.0f | | |
| 0x44 | | |
| -40 | | |

Ans:
----
| Constant | Type | Specifier |
| -------- | ---- | --------- |
| 012 | `unsigned int` | `%#o` |
| 2.9e05L | `long double` | `%le` |
| 's' | `char` | `%c` |
| 100000 | `long` | `%ld` |
| '\n' | `char` | `%c` |
| 20.0f | `float` | `%.1f` |
| 0x44 | `unsigned int` | `%#x` |
| -40 | `int` | `%d` |

## Question 8.
> Suppose a program begins with these declarations:
```c
int imate = 2;
long shot = 53456;
char grade = 'A';
float log = 2.71828;
```
> Fill in the proper type specifiers in the following `printf()` statements:
```c
printf("The odds against the %__ were %__ to 1.\n", imate, shot);
printf("A score of %__ is not an %__ grade.\n", log, grade);
```

The appropriate format should be:
```c
printf("The odds against the %d were %ld to 1.\n", imate, shot);
printf("A score of %f is not an %c grade.\n", log, grade);
```

## Question 9.
> Suppose that `ch` is a type `char` variable. Show how to assign the
carriage-return character to `ch` by using an escape sequence, a decimal value,
an octal character constant, and a hex character constant. (Assume ASCII code values).

- Escape Sequence: `ch = '\r';`
- Decimal Value: `ch = 13;`
- Octal Character Constant: `ch = '\015';`
- Hexidecimal Character Constant: `ch = '\0xd';`

## Question 10.
> Correct this silly program. (The / in C means division.)

```c
void main(int)  / this program is perfect /
{
  cows, legs integer;
  printf("How many cow legs did you count?\n);
  scanf("%c", legs);
  cows = legs / 4;
  printf("That implies there are %f cows.\n", cows)
}
```
Ans:
----
```c
int main(void)  /* this program is perfect */
{
  int cows, legs;
  printf("How many cow legs did you count?\n");
  scanf("%d", &legs);
  cows = legs / 4;
  printf("That implies there are %d cows.\n", cows);

  return 0;
}
```

## Question 11.
> Identify what each of the following escape sequences represents:
> - a. `\n`
> - b. `\\`
> - c. `\"`
> - d. `\t`
>> - a. newline character
>> - b. literal backslash
>> - c. literal double quote
>> - d. tab character
