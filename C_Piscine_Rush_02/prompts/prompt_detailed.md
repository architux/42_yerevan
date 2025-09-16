Write me a complete ready-to-compile project that takes a number and converts it to its written textual representation via full string-based number decomposition using dictionary file with mappings of "number"-to-"textual representation" (the default one or a custom one).

Basic workflow steps are as follows.

1. Source data validation and parsing.

1.1. Read the raw command-line argument(s).

The executable program in console must take up strictly from 2 to 3 arguments:

Usecase `A`. If there is *only 1 argument*, it is the *number to be represented textually*.
Usecase `B`. If there are *only 2 arguments*, the first argument is the *new reference dictionary* (instead of the default one), and the second argument is the *number to be represented textually*.

If there's any other number of arguments, the program must output `Error\n` with exit code 1.

1.2. Trim leading/trailing whitespaces from arguments, if exist.

1.3. Validate number argument (in both usecases `A` and `B`).

String argument having number must look like a **valid and positive integer only**.
If number argument starts with plus sign, it must be omitted to continue checking for the valid and positive integer.
If number argument has leading zeros, collapse them to a single zero if entire number is zero, otherwise strip leading zeros.

Edge error cases for number argument are:

* It is empty.
* It starts with minus sign, for program does not work with negative numbers.
* It looks like a floating point number (having dot or comma inside).
* It has any other non-digit chars within (anything beyond chars from '0' to '9').

In any of these cases the program must output `Error\n` with exit code 2.

1.4 Note on working with parsed number in backend.

The program must handle numbers **from zero to undecillion**, maybe even larger numbers, if they will be added to custom dictionary. Programming logic must be efficient to work with such numbers, so do not encode input number to any numeric data type in C. Instead, keep the entire number as a decimal string to walk it through to get textual representations of all its actual content.

Work with triplet strings: pad left to multiple of 3, slice substrings s[i:i+3], convert each triple by mapping characters to numeric digits locally, not by converting to an integer type.

Avoid any library integer arithmetic: operate on string indices and digit characters only.

1.4. Dictionary file validation and parsing (for the default dictionary file in usecase `A` and for a custom dictionary file in usecase `B`).

The program must *parse the corresponding dictionary file* to get mappings of numbers to their respective textual representations.

Dictionary file keys are **valid and positive integers only**, to comply with number being parsed from command-line. Dictionary file values are their respective textual representations. Separator is `:` sign, leading and trailing whitespaces are optional.

All of the valid mapping lines must look like this **mapping line mask**:
`[0 to n spaces][number as key][0 to n spaces]:[0 to n spaces][any printable characters as value][0 to n spaces]\n`.
This is the only valid mapping line mask to work with. So such lines must be parsed by taking keys and corresponding values as strings (see *Note on working with parsed number in backend*), ignoring optional leading and trailing whitespaces around.

The default dictionary (for usecase `A`) is called `numbers.dict`. It is stored in the same project directory as other `*.c` files.

The custom dictionary file (for usecase `B`) is parsed from the first command line argument representing **a local or absolute path to that custom dictionary file** on the same machine. Just the filename says it's located in the same project folder, some path indicates the respective location on the same machine.

Mapping lines can be stored in any order, so the mappings may be sorted after parsing, if needed for efficiency.

Dictionary file may have empty lines inside, so those must be skipped.

Programming logic must rely on parsed dictionary mappings (from default or custom dictionary file) as **the only source of truth** for composing number textual representation, *not to copy any of those hardcoded values in backend*.

Edge error cases for dictionary file parsing are:
* File does not exist by its path (`numbers.dict` in the same project folder or custom dictionary by its given path).
* Any key is empty (whitespaces only from the start of the line till the `:` separator).
* Any value is empty (whitespaces only after the `:` separator till the end of the line).
* Any line does not comply with the aforementioned *mapping line mask*.
* Any *required mapping* from ``.default.dict` is missing.
* Any key is not a *valid and positive integer*.
* Any duplicated keys.
* If the parsed number has more triplet groups than you have keys for.

In any of these cases the program must output `Dict Error\n` with exit code 3.

1.5. Required and actual dictionary mappings valiadtion

The **required mappings that must be present in any dictionary** (either in a default `numbers.dict` in usecase `A` or in a custom in usecase `B`) are stored in the special project file called `.default.dict`. It is stored in the same project directory, and therefore **it must not be edited**. 

This file has the following required mappings:
```
0: zero
1: one
2: two
3: three
4: four
5: five
6: six
7: seven
8: eight
9: nine
10: ten
11: eleven
12: twelve
13: thirteen
14: fourteen
15: fifteen
16: sixteen
17: seventeen
18: eighteen
19: nineteen
20: twenty
30: thirty
40: forty
50: fifty
60: sixty
70: seventy
80: eighty
90: ninety
100: hundred
1000: thousand
1000000: million
1000000000: billion
1000000000000: trillion
1000000000000000: quadrillion
1000000000000000000: quintillion
1000000000000000000000: sextillion
1000000000000000000000000: septillion
1000000000000000000000000000: octillion
1000000000000000000000000000000: nonillion
1000000000000000000000000000000000: decillion
1000000000000000000000000000000000000: undecillion
```

The values of these required mappings in actual usecase dictinary files can be modified, more entries can be added, but the initial keys from `.default.dict` **must not be removed**.

The list of required mappings from `.default.dict` is to be parsed into `req_mappings` array.
The list of mappings from the actual usecase dictionary file are to be parsed into `dict_mappings` array.
And then, two arrays are compared by having the same key/value pairs in both of them.
If the same key/value pair exists in both arrays, it gets deleted from `dict_mappings`.
If any key/value pair is missing from `dict_mappings`, the program must output `Dict Error\n` with exit code 3.

1.6. Required and actual dictionary mappings role in conversion precedence

By default the required mappings from `.default.dict` cover just the necessary source building blocks as **atomic tokens** (0–19, 20, 30, ..., 100, 1000, etc.). The algorithm composes larger numbers by decomposition.

With optional arbitrary user mappings in actual usecase dictinary files, dictionary may contain whole numbers of any length as an **override table for full numbers**, like:
* 42: "forty-two" (standard, redundant with decomposition).
* 123789456: "groovy number" (non-standard, custom alias).
* 3141592653589793: "pi disguised" (arbitrary long).

So the actual usecase dictionary mappings may become a set of both.

A I've said before, in positive case (when all the `req_mappings` key value pairs correspond with `dict_mappings` ones) `dict_mappings` get those required mappings deleted, having only custom arbitrary user mappings. 

After that, to work with optional arbitrary user mappings correctly, **configurable policy** is the best compromise. Set an app setting as `#define` macro value in `main.c` as `DICT_PRIORITY` with options:
* `DIRECT`: exact dictionary match takes precedence.
* `COMPOSE`: ignore arbitrary full-number entries, only use dictionary for canonical tokens.
* `HYBRID`: use direct-match if possible, otherwise stick to canonical tokens.

2. Preparing number textual representaion.

Use core conversion algorithm (triplet / scale decomposition). Split the decimal string into groups of 3 digits from the right (units, thousands, millions, etc.). Convert each `0–999` group into words; attach the scale name (thousand, million, etc.), where the group is non-zero. Join groups from most significant to least.

2.1. Prepare scale names.

* Build an ordered list of scale names by their numeric value from parsed dictionary file contents.
* For each scale numeric key, attempt to read the textual name from dictionary. If not present, the program must output `Dict Error\n` with exit code 4.
* Align scale array so scale[0] = "" (units), scale[1] = "thousand", scale[2] = "million" etc.

2.2. Split the number string into triplets.

* If number string length is not divisible by 3, pad left with leading zero chars to make length divisible by 3.
* Break it into groups of 3 characters from left or right.

Example: 1234567 -> groups ["001", "234", "567"].

2.3. Convert a single 3-digit group (value `000..999`) to words.

For each group value `abc` where `a`, `b`, `c` are digits (hundreds, tens, units):

2.3.1. Hundreds place:

If `a != 0`:

* Lookup `a` in dictionary mappings, say, key "1" -> "one".
* Lookup "100" in dictionary mappings, say, "100" -> "hundred".
* Output values for "1" and "100".
* Optionally apply the conjunction rule: in some English variants you insert "and" before tens/units when hundreds present and the tens/units nonzero (e.g. "one hundred and twenty-three").

2.3.2. Tens and units (two-digit number `bc`):

If `b == 1` (i.e., 10–19):
* Lookup the entire teen number in dictionary mappings keys "10" to "19", output value.

Else:

If `b != 0`:
* Lookup the tens value as `b*10` ("20", "30", etc.) in dictionary, output value.

If `c != 0`:
* Lokup the units `c` in dictionary, output value.

Decide punctuation for combining tens and units:

In English: hyphenate compound tens and units for 21–99 when both tens and units present (e.g. "twenty-three").

If the dictionary provides a direct entry for a specific two-digit number, prefer it (e.g. maybe the dictionary explicitly has 42: "forty two" or "something else").

2.3.3. If the group is exactly zero (`000`).

Skip output for this group entirely (do not print "zero" for interior groups). The overall zero should be handled at top-level.

2.4. Attach scale name

If the 3-digit group value is nonzero, after converting the group to words append the scale name corresponding to the group index (e.g., group index = 1 -> "thousand").

The scale name is obtained from dictionary keys for 1000, 1000000, etc., if present. Otherwise the program must output `Dict Error\n` with exit code 4.

2.5. Combine groups

Process groups from most significant to least significant, collecting converted non-empty group strings.

Join with separators:

* A single space between major pieces by default.
* Optionally insert commas between any large scale blocks (purely punctuation).
* Respect conjunction rules (e.g., insert "and" in British English between the last nonzero hundreds and tens/units portion).

If a parsed dictionary does not allow you to perform a conversion of the provided number, the program must output `Dict Error\n` with exit code 4.

In case of successful conversion the result must br printed to console followed by a newline, with exit code 0.

3. Example of step-by-step English conversion of "1234567" number.

3.1. Normalize: no sign, digits OK, remove optional leading zeros → "1234567".
3.2. Pad & group into triplets from right: groups = ["001", "234", "567"], pad first to "001", but conceptually groups: 1 (millions), 234 (thousands), 567 (units).
3.3 Convert group 1 → lookup "1" -> "one". Attach scale for group index 2 (millions) -> lookup "1000000" -> "million". Produce "one million".
3.4. Convert group 234:
* hundreds digit 2 -> "two hundred".
* tens+units 34 -> tens 30 -> "thirty", units 4 -> "four", join as "thirty-four" (hyphen optional).
* Combined -> "two hundred thirty-four".
* Attach scale index 1 (thousand) -> "thousand" → "two hundred thirty-four thousand".
3.5. Convert group 567 similarly -> "five hundred sixty-seven".
3.6. Join non-empty groups in order with spaces: "one million two hundred thirty-four thousand five hundred sixty-seven".

4. File structure suggestions

Modules:

* CLI parser (handles args and options).
* Dictionary loader & validator (returns a normalized token → string map).
* Number normalizer (handles sign, separators, leading zeros).
* Decomposer (splits into triplets or other grouping strategy).
* Triple-to-words converter (core logic using the map).
* Assembler/formatter (joins segments, punctuation, and conjunctions).
* Error & diagnostics module.

5. Test cases

Negative test cases:

* Empty number command line argument
* Negative numbers (starting with minus sign)
* Floating-point numbers
* Anything unable to be parsed as *valid and positive number*

Positive test cases:

* Zero: 0.
* Small numbers 1..19.
* Tens 20, 30, ..., 90.
* Compound tens like 42, 21, 99.
* Hundreds 100, 101, 110, 999.
* Thousands, millions, billions: 1000, 1001, 23456, 1000000.
* Numbers with interior zero groups: 1000005 => one million five.
* Very long numbers (hundreds of digits): ensure no integer overflow and proper grouping.

6. Programming implementation

Make it using C programming language, rely on older and more convenient C standard (late 1980s - early 1990s).

You must be able to use only only `write`, `malloc`, `free`, `open`, `read` and `close` functions from the standard library. No any other useful and shorthand features: no `for` cycles, `switch` statements, ternary operators, structs, global variables, `extend` keywords, etc.

Parsing of command line arguments must be done in `main.c` file using `argc`/`argv` feature.

Each memory allocated on the heap using `malloc` must be freed correctly using `free` at the end of program execution.

The project must comply with the following syntax restrictions of the `norminette` console application:
* Each function and variable name must be names only using lowercase characters, digits or underscore.
* Each function must not have more than 4 arguments.
* Each function must not have more than 25 lines of code.
* Each function must not have more than 5 variables declared inside.
* All the function variables must be declared at the start of function body without values, to fill values later, and this initial declaration block must be separated with newline.
* Every variable being set must be used within the function.
* Each function definition must have tabulation symbol between `function` and its name. Arguments definition within brackets must have regular spaces inside.
* Each variable definition must have tabulation symbol between variable data type and its name.
* All function return values must be wrapped into parenthesis.
* Each curly braces block must be symmetrical (not to leave opening brace at the end of the line, make it vertically aligned with the closing brace).

Split the whole logic into multiple `*.c` files for separation of concerns, but without additional header files, complying to additional restriction that **each `*.c` file should have not more than 5 functions**.

Prepare the Makefile with basic commands using `cc` compiler and `rush-02` as the target.

Show me these source files one by another as copyable code blocks for latter pasting.
