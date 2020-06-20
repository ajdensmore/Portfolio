# My soulution to the Validating postal codes question using regex

regex_integer_in_range = r"_________"
regex_alternating_repetitive_digit_pair = r"_________"


import re
P = input()

print (bool(re.match(regex_integer_in_range, P))
and len(re.findall(regex_alternating_repetitive_digit_pair, P)) < 2)
