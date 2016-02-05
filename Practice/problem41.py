# -*- coding: utf-8 -*-
"""
Created on Wed Feb 03 19:24:51 2016

@author: Ben
"""

import math

# problem 41

# returns 1 if number is prime, otherwise 0
def isprime(n):
    flag = 0
    if n == 0 or n == 1 or n % 2 == 0:
        return 0
    if n == 2 or n == 3:
        return 1
    end = int(math.sqrt(n)) + 1
    for x in range(3, end, 2):
        if n % x == 0:
            flag += 1
            break
    if flag == 0:
        return 1
    else:
        return 0
        
# returns 1 if number is pandigital, otherwise 0
def ispandigital(n):
    numstr = str(n)
    length = len(numstr)
    count = 0
    for x in range(1, length+1):
        #print x
        if str(x) in numstr:
            count += 1
    if count == length:
        return 1
    else:
        return 0

# find local largest pandigital prime until it's global
for x in range(7654321, 1, -2):
    if isprime(x) + ispandigital(x) == 2:
        print x
        break

