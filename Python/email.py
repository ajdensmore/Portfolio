# Python script that verifies valid emails from a list

import re;

def isValidEmail(s):
    return None != re.match(r'^[\w_-]+@[a-zA-Z0-9]+\.[a-zA-Z]{1,3}$',s);

if __name__ == "__main__":
    print(sorted(list(filter(
                 isValidEmail,
                 [input() for i in range(int(input()))]
                 ))));
