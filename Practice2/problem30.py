# -*- coding: utf-8 -*-
"""
Created on Wed Jan 27 14:07:46 2016

@author: Ben
"""

#problem 30

summ = 0
n = 12
while n < 1000000:
    x = n
    total = 0
    while x:
        total += (x % 10) ** 5
        x //= 10
    if total == n:
        summ += total
    n += 1

print summ
