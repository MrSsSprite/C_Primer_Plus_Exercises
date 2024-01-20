# Chapter 10. Arrays and Pointers

## Review Questions

### Question 1.
> What will this program print?
> ```c
> #include <stdio.h>
> 
> int main(void)
> {
>     int ref[] = {8, 4, 0, 2};
>     int *ptr;
>     int index;
> 
>     for (index = 0, ptr = ref; index < 4; index++, ptr++)
>         printf("%d %d\n", ref[index], *ptr);
> 
>     return 0;
> }
> ```

The output should be:
```terminal
8 8
4 4
0 0
2 2

```

### Question 2.
> In question 1, how many elements does `ref` have?

`ref`, in question 1, has four `int` elements.

### Question 3.
> In question 1, `ref` is the address of what? What about `ref + 1`? What does 
  `++ref` point to?

In question 1, `ref` is the address of the zeroth element in the array.
`ref + 1` is the first (if counting from zeroth) element of the array.
`++ref` is not a valid expression.

### Question 4.
> What is the value of `*ptr` and of `*(ptr + 2)` in each case?
>> a.
>> ```c
>> int *ptr;
>> int torf[2][2] = {12, 14, 16};
>> ptr = torf[0];
>> ```
>
>> b.
>> ```c
>> int *ptr;
>> int fort[2][2] = { {12}, {14, 16} };
>> ptr = fort[0];
>> ```

- a.
    `*ptr` is `12` and `*(ptr + 2)` is `16`.
- b.
    `*ptr` is `12` and `*(ptr + 2)` is `14`.

### Question 5.
> What is the value of `**ptr` and of `**(ptr + 1)` in each case?
>> a.
>> ```c
>> int (*ptr)[2];
>> int torf[2][2] = {12, 14, 16};
>> ptr = torf;
>> ```
>
>> b.
>> ```c
>> int (*ptr)[2];
>> int fort[2][2] = { {12}, {14, 16} };
>> ptr = fort;
>> ```

- a.
    `**ptr` is `12` and `**(ptr + 1)` is `16`.
- b.
    `**ptr` is `12` and `**(ptr + 1)` is `14`.

### Quesion 6.
> Suppose you have the following declaration:
> ```c
> int grid[30][100];
> ```
>> a. Express the address of `grid[22][56]` one way.
>>
>> b. Express the address of `grid[22][0]` two ways.
>>
>> c. Express the address of `grid[0][0]` three ways.

- a. `grid[22] + 56`
- b. `grid[22]` or `*(grid + 22)`
- c. `grid[0]` or `*grid` or `&grid[0][0]`

### Question 7.
> Create an appropriate declaration for each of the following variables:
>> a. `digits` is an array of 10 `int`s.
>>
>> b. `rates` is an array of six `float`s.
>>
>> c. `mat` is an array of three arrays of five integers.
>>
>> d. `psa` is an array of 20 pointers to `char`.
>>
>> e. `pstr` is a pointer to an array of 20 `char`s.
- a. `int digits[10];`
- b. `float rates[6];`
- c. `int mat[3][5];`
- d. `char * psa[20];`
- e. `char (*pstr)[20];`

### Queston 8.
> a. Declare an array of six `int`s and initialize it to the values `1`, `2`, 
     `4`, `8`, `16`, and `32`.
>
> b. Use array notation to represent the third element (the one with the value 
     `4`) of the array in part a.
>
> c. Assuming C99/C11 rules are in effect, declare an array of 100 `int`s and 
     initialize it so that the last element is `-1`; don't worry about the other 
     elements.
>
> d. Assuming C99/C11 rules are in effect, declare an array of 100 `int`s and 
     initialize it so that elements 5, 10, 11, 12, and 3 are `101`; don't worry 
     about the other elements.

- a. `int arr[6] = {1, 2, 4, 8, 16, 32};`
- b. `arr[2]`
- c. `int arr[100] = { [99] = -1 };`
- d. `int arr[100] = { [5] = 101, [10] = 101, 101, 101, 101 };`

### Question 9.
> What is the index range for a 10-element array?
0 through 9.

### Question 10.
> Suppose you have these declarations:
> ```c
> float rootbeer[10], things[10][5], *pf, value = 2.2;
> int i = 3;
> ```
> Identify each of the following statements as valid or invalid:
>> a. `rootbeer[2] = value;`
>>
>> b. `scanf("%f", &rootbeer);`
>>
>> c. `rootbeer = value;`
>>
>> d. `printf("%f", rootbeer);`
>>
>> e. `things[4][4] = rootbeer[3];`
>>
>> f. `things[5] = rootbeer;`
>>
>> g. `pf = value;`
>>
>> h. `pf = rootbeer;`

- a. valid
- b. invalid
- c. invalid
- d. invalid
- e. valid
- f. invalid
- g. invalid
- h. valid

### Question 11.
> Declare an 800x600 array of `int`.

```c
int arr[800][600];
```

### Question 12.
> Here are three array declarations:
> ```c
> double trots[20];
> short clops[10][30];
> long shots[5][10][15];
> ```
>> a. Show a function prototype and a function call for a traditional `void` 
      function that processes `trots` and also for a C function using a VLA.
>>
>> b. Show a function prototype and a function call for a traditional `void` 
      function that processes `clops` and also for a C function using a VLA.
>>
>> c. Show a function prototype and a function call for a traditional `void` 
      function that processes `shots` and also for a C function using a VLA.
- a.
    ```c
    void func0(double arr[], int sz);
    func0(trots, 20);
    ```
- b.
    ```c
    void func1(short arr[][30], int sz);
    void func2(int row, int col, arr[row][col]);
    func1(clops, 10);
    func2(10, 30, clops);
    ```
- c.
    ```c
    void func3(long arr[][10][15], int sz);
    void func4(int i, int j, int k, arr[i][j][k]);
    func3(shots, 5);
    func4(5, 10, 15, shots);
    ```

### Question 13.
> Here are two function prototypes:
```c
void show(const double ar[], int n);        // n is number of elements
void show2(const double ar2[][3], int n);   // n is number of rows
```
>> a. Show a function call that passes a compound literal containing the values 
      `8`, `3`, `9`, and `2` to the `show()` function.
>>
>> b. Show a function call that passes a compound literal containing the values 
      `8`, `3`, and `9` as the first row and the values `5`, `4`, and `1` as the 
      second row to the `show2()` function.

- a.
    `show((int [4]) {8, 3, 9, 2}, 4)`
- b.
    `show2((int [2][4]) { {8,3,9}, {5,4,1} }, 2)`

## Programming Exercises

### Exercise 1.
> Modify the rain program in Listing 10.7 so that it does the calculations 
  using pointers instead of subscripts. (You still have to declare and 
  initialize the array.)

[source code](Programming_Exercises\ex1.c)

### Exercise 2.
> Write a program that initializes an array-of-`double` and then copies the 
  contents of the array into three other arrays. (All four arrays should be 
  declared in the main program.) To make the first copy, use a function with 
  array notation. To make the second copy, use a function with a pointer 
  notation and pointer incrementing. Have the first two functions take as 
  arguments the name of the target array, the name of the source array, and the 
  number of elements to be copied. Have the third function take as arguments the 
  name of the target, the name of the source, and a pointer to the element 
  following the last element of the source. That is, the function calls would 
  look like this, given the following declarations:
> ```c
> double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
> double target1[5];
> double target2[5];
> double target3[5];
> copy_arr(target1, source, 5);
> copy_ptr(target2, source, 5);
> copy_ptrs(target3, source, source + 5);
> ```

[source code](Programming_Exercises\ex2.c)

### Exercise 3.
> Write a function that returns the largest value stored in an array-of-`int`. 
  Test the function in a simple program.

[source code](Programming_Exercises\ex3.c)

### Exercise 4.
> Write a function that returns the index of the largest value stored in an 
  array-of-`double`. Test the function in a simple program.

[source code](Programming_Exercises\ex4.c)

### Exercise 5.
> Write a function that returns the difference between the largest and smallest 
  elements of an array-of-`double`. Test the function in a simple program.

[source code](Programming_Exercises\ex5.c)

### Exercise 6.
> Write a function that reverses the contents of an array of `double` and test 
  it in a simple program.

[source code](Programming_Exercises\ex6.c)

### Exercise 7.
> Write a program that initializes a two-dimensional array-of-`double` and uses 
  one of the copy functions from exercise 2 to copy it to a second 
  two-dimensional array. (Because a two-dimensional array is an array of 
  arrays, a one-dimensional copy function can be used with each subarray.)
