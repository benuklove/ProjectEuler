# -*- coding: utf-8 -*-
"""
Created on Thu Feb 04 14:16:28 2016

@author: Ben
"""

# problem 145

# takes a number and reverses the digits
def reverse(n):
    return int(str(n)[::-1])

# returns 1 if all digits in n are odd, otherwise 0
def allodd(n):
    numstr = str(n)
    count = 0
    for x in numstr:
        if int(x) % 2 == 1:
            count += 1
    if count == len(numstr):
        return 1
    else:
        return 0

total = 0
for x in range(1, 80000000):
    numstr = str(x)
    if numstr[len(numstr)-1] == "0":
        continue
    if allodd(x + reverse(x)) == 1:
        total += 1
print total

