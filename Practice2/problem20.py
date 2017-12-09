# -*- coding: utf-8 -*-
"""
Created on Mon Jan 18 19:28:31 2016

@author: Ben
"""

import math

num = raw_input()

fact = math.factorial(int (num))
print fact
def sum_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s

print "The sum of digits is: "
print sum_digits(fact)