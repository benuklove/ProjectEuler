# -*- coding: utf-8 -*-
"""
Created on Mon Jan 18 19:01:10 2016

@author: Ben
"""

num = 2**1000
print num

def sum_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s

print "The sum of digits is: "
print sum_digits(num)
    