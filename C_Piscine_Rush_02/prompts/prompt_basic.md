Write me a complete ready-to-compile project that takes a number and converts it to its **written textual representation** via **full string-based number decomposition** using dictionary file (the default one or a custom one) with mappings of "number"-to-"textual representation".

Basic workflow steps are as follows:

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

1.4 **Important note on working with parsed number in backend**.

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

1.5. Required and actual dictionary mappings validation

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
If all of required key/value paira are present in `dict_mappings`, program goes on and `req_mappings` are freed right here, for we don't need it anymore.
If any key/value pair is missing from `dict_mappings`, the program must output `Dict Error\n` with exit code 3.

2. Converting number textual representation.

Use core conversion algorithm (triplet / scale decomposition).

* Build an ordered list of mappings (scale names by their numeric values) from parsed dictionary file contents.
* Decompose the decimal string into groups of 3 digits from the right (units, thousands, millions, etc.).
* Convert each `0–999` group into words using the mappings.
* Attach the scale name (thousand, million, etc.), where the group is non-zero.
* Join groups from most significant to least significant, collecting converted non-empty group strings. Join with a single space as a separator between major pieces.

If a parsed dictionary mappings does not allow you to perform a conversion of the provided number, the program must output `Dict Error\n` with exit code 4.

In case of successful conversion the result must br printed to console, followed by a newline, with exit code 0.

3. Test cases

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

4. Source code to consider

You may take this Python code as an inspiration.

```python
#!/usr/bin/python
# Paste and run in any Python 3 environment.
# Works with arbitrarily large integers passed as a string.

ONES = {
	0: "zero", 1: "one", 2: "two", 3: "three", 4: "four",
	5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine"
}
TEENS = {
	10: "ten", 11: "eleven", 12: "twelve", 13: "thirteen",
	14: "fourteen", 15: "fifteen", 16: "sixteen",
	17: "seventeen", 18: "eighteen", 19: "nineteen"
}
TENS = {
	2: "twenty", 3: "thirty", 4: "forty", 5: "fifty",
	6: "sixty", 7: "seventy", 8: "eighty", 9: "ninety"
}
SCALES = ["", "thousand", "million", "billion", "trillion",
		"quadrillion", "quintillion", "sextillion", "septillion",
		"octillion", "nonillion", "decillion", "undecillion"]

def three_digit_to_words(n, insert_and_within_hundreds=True):
	"""Convert integer 0..999 to words. Returns '' for 0."""
	n = int(n)
	if n == 0:
		return ""
	parts = []
	hundreds = n // 100
	rem = n % 100
	if hundreds:
		parts.append(ONES[hundreds] + " hundred")
		if rem and insert_and_within_hundreds:
			parts.append("and")
	if rem:
		if rem < 10:
			parts.append(ONES[rem])
		elif 10 <= rem < 20:
			parts.append(TEENS[rem])
		else:
			tens = rem // 10
			ones = rem % 10
			if ones:
				parts.append(TENS[tens] + " " + ONES[ones])
			else:
				parts.append(TENS[tens])
	return " ".join(parts)

def integer_to_english(num_str, british_and=True, hyphenate=False):
	"""
	Convert an integer given as a string to English words.
	- british_and: if True, uses 'and' inside the final hundreds group where British usage expects it.
	- hyphenate: if True, uses 'twenty-one' hyphenation for 21..99 with ones; if False, uses 'twenty one'.
	"""
	s = num_str.strip()
	if not s:
		raise ValueError("Empty input")
	sign = ""
	if s[0] in "+-":
		if s[0] == "-":
			sign = "minus "
		s = s[1:].lstrip()
	# remove leading zeros
	s = s.lstrip("0")
	if s == "":
		return "zero"
	# split into 3-digit groups from right
	groups = []
	i = len(s)
	while i > 0:
		start = max(0, i - 3)
		groups.append(s[start:i])
		i -= 3
	groups = list(reversed(groups))  # left to right

	# Optionally adjust TENS hyphenation
	global TENS, ONES
	# We'll apply hyphen at final join stage if requested.

	# Convert each group
	group_words = []
	for g in groups:
		# ensure three-digit integer for processing
		g_val = int(g)
		group_words.append(g_val)  # keep numeric for decision logic

	# Build textual phrases with scale names; decide where to put 'and'
	phrases = []
	nonempty_indices = [i for i, val in enumerate(group_words) if val != 0]
	last_nonempty_index = nonempty_indices[-1] if nonempty_indices else None

	for idx, val in enumerate(group_words):
		if val == 0:
			continue
		# For deciding whether to include 'and' inside this group:
		# - British typical rule: insert 'and' inside the final group when it's < 100 and there is a higher non-zero group.
		insert_and = True
		if idx != last_nonempty_index:
			# not the last nonzero group => do not insert 'and' within hundreds (usually)
			insert_and = False
		else:
			# last nonzero group: follow british_and flag for numbers over 100 where interior 'and' would appear
			insert_and = british_and

		words = three_digit_to_words(val, insert_and_within_hundreds=insert_and)
		# hyphenate option: replace 'X Y' for tens+ones into 'X-Y' only for two-word tens+ones patterns
		if hyphenate:
			# naive hyphenation: look for TENS + ONES where pattern matches e.g., "twenty one"
			for ten_word in TENS.values():
				for one_word in ONES.values():
					old = ten_word + " " + one_word
					if old in words:
						words = words.replace(old, ten_word + "-" + one_word)
		scale_name = SCALES[len(group_words) - 1 - idx]
		if scale_name:
			phrases.append(words + " " + scale_name)
		else:
			phrases.append(words)

	# Join phrases with spaces; use commas between large scale boundaries if you prefer:
	# For nicer readability you can insert commas after each phrase except the last; this implementation omits commas.
	result = " ".join(phrases)

	# Extra British rule: when the highest group exists and the last group is < 100, British style often inserts "and" before that final group:
	# e.g. 1002 -> "one thousand and two"
	if british_and and last_nonempty_index is not None:
		# if last group value < 100 and there exists any higher non-zero group:
		if group_words[last_nonempty_index] < 100 and last_nonempty_index != 0:
			# find the point to insert 'and' before the final group's phrase
			# we can rebuild: all but last phrase + 'and' + last phrase
			parts = [p for p in phrases]
			if len(parts) >= 2:
				result = " ".join(parts[:-1]) + " and " + parts[-1]

	return (sign + result).strip()

# Example:
if __name__ == "__main__":
	tests = ["0", "5", "42", "100", "342", "500342", "1002", "123456789012345678901234567890"]
	for t in tests:
		print(t, "->", integer_to_english(t, british_and=True, hyphenate=False))
```

But the actual project must be written in C, see the next point number 5.

5. **The most important part**: Programming implementation

Make it using C programming language, rely on older and more convenient C standard (late 1980s - early 1990s).

You must be able to use only only `write`, `malloc`, `free`, `open`, `read` and `close` functions from the standard library. No any other useful and shorthand features: no `for` cycles, `switch` statements, ternary operators, structs, global variables, `extend` keywords, etc.

Parsing of command line arguments must be done in `main.c` file using `argc`/`argv` feature.

Each memory allocated on the heap using `malloc` must be freed correctly using `free` at the end of program execution.

The project must comply with the following syntax restrictions and should be **strictly norminette-compliant C project**:
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
* Split the whole logic into multiple `*.c` files for separation of concerns, but without additional header files.
* Each `*.c` file should have not more than 5 functions.

Do not try to generate code blocks or several files in various iterations, give me a complete ready-to-compile project in the first place.

Prepare the Makefile with basic commands using `cc` compiler and `rush-02` as the target.

Show me these source files one by another as copyable code blocks for latter pasting.
