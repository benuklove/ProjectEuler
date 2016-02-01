# -*- coding: utf-8 -*-
"""
Created on Wed Jan 29 16:07:29 2016

@author: Ben
"""

#from math import sqrt
import math

print "Enter the limit: "
num = int(raw_input())

# returns 1 if number is prime, otherwise 0
def isprime(n):
    flag = 0
    if n == 0 or n == 1 or n % 2 == 0:
        return 0
    if n == 2 or n == 3:
        return 1
    end = int(math.sqrt(n)) + 1
    for x in range(3, end, 2):
        #print x
        if n % x == 0:
            flag += 1
            break
    if flag == 0:
        return 1
    else:
        return 0

# given a string, bring the last character to the front (rotate once)
# and return the number (as an int)
def rotate(n):
    old = list(n)
    last = old[len(old) - 1]
    temp = []
    for c in range(len(old) - 1):
        temp.append(old[c])
    final = [last] + temp
    number = int("".join(final))
    return number

# given a number, returns 1 if all rotations are prime, otherwise 0
def allrotsprime(n):
    numstr = str(n)
    length = len(numstr)
    flag = 0
    for x in range(length):
        numstr = rotate(str(numstr))
        #print numstr
        if isprime(numstr) == 0:
            flag += 1
            #print "not prime: ", numstr
    if flag == 0:
        return 1
    else:
        return 0

#given an upper limit, find total number of circular primes below limit
def circularprimes(n):
    count = 0
    for x in range(3, n, 2):
        if isprime(x) == 1:
            if allrotsprime(x) == 1:
                count += 1
    return count + 1

print circularprimes(num)
