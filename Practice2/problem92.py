# -*- coding: utf-8 -*-
"""
Created on Mon Feb 01 20:10:23 2016

@author: Ben
"""

# problem92

# Sum of the squares of the digits
def ssd(n):
    summ = 0
    while n:
        summ += (n % 10) ** 2
        n //= 10
    return summ

""" As long as I know all numbers will end at 1 or 89 
    (my attempt to use 'while num not in sumlist' didn't work)
"""
# Returns number of starting numbers that will arrive at 89
def count89(n):
    count = 0
    for x in range(1, n):
        at89 = 0
        sumlist = []
        num = x
        flag = 0
        while flag == 0:
            sumlist.append(ssd(num))
            num = sumlist[len(sumlist) - 1]
            if num == 89:
                at89 += 1
                flag += 1
            elif num == 1:
                flag += 1
            #print num, at89, at1
        if at89 == 1:
            count += 1
        #print sumlist
    return count

print count89(10000000)

