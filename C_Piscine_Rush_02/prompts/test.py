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
