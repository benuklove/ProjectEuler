# -*- coding: utf-8 -*-
"""
Created on Mon Jan 18 20:10:27 2016

@author: Ben
"""

# simply gets the sum of proper divisors of a number
def sumproperdivisors(n):
    summ = 0
    for i in range(1,n):
        if n % i == 0:
            summ += i
    return summ

# gets the sum of proper divisors of the sum of proper divisors of a number
# (recursive once)
def spd_ofthe_spd(n):
    spd = sumproperdivisors(n)
    return sumproperdivisors(spd)

# returns sum of amicable numbers below n
def sum_amicable_nums(n):
    total = 0
    amnums_array = []
    for i in range(1,n):
        if spd_ofthe_spd(i) == i and spd_ofthe_spd(i) != sumproperdivisors(i):
            total += i
            amnums_array.append(i)
    print "The amicable numbers are: ", amnums_array
    return total

print sum_amicable_nums(10000)
