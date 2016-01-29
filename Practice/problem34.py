# -*- coding: utf-8 -*-
"""
Created on Wed Jan 27 13:53:14 2016

@author: Ben
"""

#problem 34

from math import factorial

summ = 0
n = 3
while n < 5000000:
    x = n
    total = 0
    while x:
        total += factorial(x % 10)
        x //= 10
    if total == n:
        summ += total
    n += 1

print summ
