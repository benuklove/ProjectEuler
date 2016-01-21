# -*- coding: utf-8 -*-
"""
Created on Tue Jan 19 12:25:44 2016

@author: Ben
"""


def count_digits(n):
    c = 0
    while n:
        c += 1
        n //= 10
    return c

# Print index of first Fibonacci number to have n digits
def fib(n):
    a, b, i = 0, 1, 0
    count = 0
    while count < n:
        result = b
        a, b = b, a+b
        i += 1
        count = count_digits(result)
    print "Index: ", i
    print "Digits: ", count
    print "Last Fib num: ", a
    return 0

print fib(1000)
