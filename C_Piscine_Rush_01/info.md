## Prompt

Write me a complete ready-to-compile project to solve a task of N x N skyscrapers, by following the logic-based deduction approach (deduce obvious placements, and then apply backtracking for the rest).

Do it with C programming language, but without any standard library useful and shorthand features (without `for` cycles, structs, global variables), being able to use only `malloc`, `free` or `write` functions (only if needed).

The project must comply with the following restrictions:
* Any function and variable name must have only lowercase characters, digits or underscore.
* Any function must have not more than 4 arguments.
* Each function must have not more than 25 lines of code.
* Each function must have not more than 5 variables inside.
* All the function variables must be declared at the start of function body, but without values, to fill values later, and to separate such initial declaration blocks with newline.
* Any function definition must have tabulation symbol between `function` and its name. Arguments definition within brackets must have regular spaces inside.
* Any variable definition must have tabulation symbol between variable data type and its name.
* Every variable being set must be used within the function.
* All function return values must be wrapped into parenthesis.
* Each curly braces block must be symmetrical (not to leave opening brace at the end of the line, make it vertically aligned with the closing brace).

Add parsing of clues from command line input in `main` function, to parse one big string argument containing top, bottom, left and right clues, separated by spaces (using `argc`/`argv` feature).

Write it in general way in terms of actual code, i.e. without hard-coding the square size within the code, take it from the size ot clues divided by 4 at the start of `main` function.

Try to use some optimizational techniques to make it responsive and prettty quick for square sizes from 4 to 9:
* Deterministic deductions (like pre-fill rows/columns when clue = `1` or clue = `N`).
* Row permutation filtering (precompute only rows compatible with left/right clues).
* Bitmask column checks (to quickly detect duplicates).
* Most-constrained-first order (choose the row with the fewest candidates next).

Split the whole logic into multiple `*.c` files for separtion of concerns, but without additional header files.

## Test cases

Re-generate test cases to solve a task of N x N skyscrapers, for square sizes from 4 to 9.
Each test case should have:
1) a list of top, bottom, left and right clues, indicating that corresponding column (for top and bottom clues) or row (for left and right clues) must have specified number of visible skyscrapers. That number should be tested against the line of numbers in column or row by checking if the next value in line is bigger than the previous max value. Say, for `4` clue it should have `1 2 3 4` values in the line only, because only in that case all of those skyscrapers will be visible, because 1 is the initial max value, and then 2 > 1, 3 > 2, 4 > 3, so we get the clue of 4 totally. Contrary, for `1` clue it should have `4` as the first value in the line only, because only in that case we will see only that the largest skyscraper, hiding everything else, because 4 is the initial max value, and then nothing is bigger than it, so we get the clue of 1 totally. And so on.
2) the same clues represented as one string containing top, bottom, left and right clues respectively, separated by spaces.
3) a N x N square filled with correct values to test against.

### 4 x 4

Top:    [4, 3, 2, 1]
Bottom: [1, 2, 2, 2]
Left:   [4, 3, 2, 1]
Right:  [1, 2, 2, 2]

./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3

### 5 x 5

Top: [5, 4, 3, 2, 1]
Bottom: [1, 2, 2, 2, 2]
Left: [5, 4, 3, 2, 1]
Right: [1, 2, 2, 2, 2]

./rush01 "5 4 3 2 1 1 2 2 2 2 5 4 3 2 1 1 2 2 2 2"

1 2 3 4 5
2 3 4 5 1
3 4 5 1 2
4 5 1 2 3
5 1 2 3 4

### 6 x 6

Top: [6, 5, 4, 3, 2, 1]
Bottom: [1, 2, 2, 2, 2, 2]
Left: [6, 5, 4, 3, 2, 1]
Right: [1, 2, 2, 2, 2, 2]

./rush01 "6 5 4 3 2 1 1 2 2 2 2 2 6 5 4 3 2 1 1 2 2 2 2 2"

1 2 3 4 5 6
2 3 4 5 6 1
3 4 5 6 1 2
4 5 6 1 2 3
5 6 1 2 3 4
6 1 2 3 4 5

### 7 x 7

Top: [7, 6, 5, 4, 3, 2, 1]
Bottom: [1, 2, 2, 2, 2, 2, 2]
Left: [7, 6, 5, 4, 3, 2, 1]
Right: [1, 2, 2, 2, 2, 2, 2]

./rush01 "7 6 5 4 3 2 1 1 2 2 2 2 2 2 7 6 5 4 3 2 1 1 2 2 2 2 2 2"

1 2 3 4 5 6 7
2 3 4 5 6 7 1
3 4 5 6 7 1 2
4 5 6 7 1 2 3
5 6 7 1 2 3 4
6 7 1 2 3 4 5
7 1 2 3 4 5 6

### 8 x 8

Top: [8, 7, 6, 5, 4, 3, 2, 1]
Bottom: [1, 2, 2, 2, 2, 2, 2, 2]
Left: [8, 7, 6, 5, 4, 3, 2, 1]
Right: [1, 2, 2, 2, 2, 2, 2, 2]

./rush01 "8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2"

1 2 3 4 5 6 7 8
2 3 4 5 6 7 8 1
3 4 5 6 7 8 1 2
4 5 6 7 8 1 2 3
5 6 7 8 1 2 3 4
6 7 8 1 2 3 4 5
7 8 1 2 3 4 5 6
8 1 2 3 4 5 6 7

### 9 x 9

Top: [9, 8, 7, 6, 5, 4, 3, 2, 1]
Bottom: [1, 2, 2, 2, 2, 2, 2, 2, 2]
Left: [9, 8, 7, 6, 5, 4, 3, 2, 1]
Right: [1, 2, 2, 2, 2, 2, 2, 2, 2]

./rush01 "9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2 9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2"

1 2 3 4 5 6 7 8 9
2 3 4 5 6 7 8 9 1
3 4 5 6 7 8 9 1 2
4 5 6 7 8 9 1 2 3
5 6 7 8 9 1 2 3 4
6 7 8 9 1 2 3 4 5
7 8 9 1 2 3 4 5 6
8 9 1 2 3 4 5 6 7
9 1 2 3 4 5 6 7 8
