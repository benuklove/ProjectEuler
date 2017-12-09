# -*- coding: utf-8 -*-
"""
Created on Tue Feb 02 13:42:01 2016

@author: Ben
"""

# problem 36

# function to determine if a number is a palindrome
def intpal(x):
    numstr = str(x)
    length = len(numstr)
    if length % 2 == 0:
        total = 0
        half = length / 2
        last = length - 1
        for x in range(0, half):
            if numstr[x] == numstr[last]:
                total += 1
            last -= 1
        if total == half:
            return 1
        else:
            return 0
    if length % 2 == 1:
        total = 0
        mid = (length - 1) / 2
        last = length - 1
        for x in range(0, mid):
            if numstr[x] == numstr[last]:
                total += 1
            last -= 1
        if total == mid:
            return 1
        else:
            return 0

# function to determine if both base 10 and base 2 numbers are palindromes
def bothpals(x):
    if intpal(x) == 1 and intpal(int(str(bin(x))[2:])) == 1:
        return 1
    else:
        return 0

# function to find the sum of all double-base palindrome numbers,
# below a specified number
def palsum(n):
    summ = 0
    for number in range(1, n):
        if bothpals(number) == 1:
            summ += number
    return summ

print palsum(1000000)

