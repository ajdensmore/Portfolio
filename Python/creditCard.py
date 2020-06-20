# Python script to verify credit card numbers
"""
Constraints:
► It must start with a 4, 5 or 6.
► It must contain exactly 16 digits.
► It must only consist of digits (0-9).
► It may have digits in groups of 4, separated by one hyphen "-".
► It must NOT use any other separator like ' ' , '_', etc.
► It must NOT have 4 or more consecutive repeated digits.
"""

def ok(s):
    import re
    if not s[0] in "456": return False
    if not re.match("[0-9-]+", s): return False
    if sum([1 if "0" <= _ and _ <= "9" else 0 for _ in s]) != 16: return False
    if not (len(s) == 16 or len(s) == 19 and s[4] == "-" and s[9] == "-" and s[14] == "-"): return False
    s = s.replace("-", "")
    for i in range(len(s)-3):
        if s[i] == s[i+1] and s[i] == s[i+2] and s[i] == s[i+3]: return False
    return True

import sys

stdin = sys.stdin

t = int(stdin.readline())
import re
for z in range(t):
    line = stdin.readline().rstrip()
    if(ok(line)):
        print("Valid")
    else:
        print("Invalid")

