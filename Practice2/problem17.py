# -*- coding: utf-8 -*-
"""
Created on Thu Jan 21 14:31:39 2016

@author: Ben
"""
# Total number of letters in all numbers as words, one to one thousand
 
def countdigits(n):
    digits = len(str(n))
    return digits

def tens(n):
    numstr = str(n)
    total = 0
    # for forty, fifty, or sixty
    if numstr[0] == "4" or numstr[0] == "5" or numstr[0] == "6":
        total = 5
    # for twenty, thirty, eighty, or ninety
    elif numstr[0] == "2" or numstr[0] == "3" or numstr[0] == "8" or numstr[0] == "9":
        total = 6
    # for seventy
    elif numstr[0] == "7":
        total = 7
    return total

def teens(n):
    total = 0
    numstr = str(n)
    if numstr[1] == "0":
        total += 3
    elif numstr[1] == "1" or numstr[1] == "2":
        total += 6
    elif numstr[1] == "5" or numstr[1] == "6":
        total += 7
    elif numstr[1] == "3" or numstr[1] == "4" or numstr[1] == "8" or numstr[1] == "9":
        total += 8
    elif numstr[1] == "7":
        total += 9
    return total

def ones(n):
    numstr = str(n)
    total = 0
    if numstr == "1" or numstr == "2" or numstr == "6":
        total += 3
    elif numstr == "4" or numstr == "9" or numstr == "5":
        total += 4
    elif numstr == "3" or numstr == "7" or numstr == "8":
        total += 5
    return total

def hundreds(n):
    # add in number of hundreds
    total = ones(n)
    # then add for "hundred and"
    total += 10
    return total

# Function to use all number-word letter counts as needed in loop
def combine(n):
    numstr = str(n)
    total = 0
    # single digits
    if countdigits(n) == 1:
        total += ones(n)
    # double digits
    elif countdigits(n) == 2:
        if numstr[0] == "1":
            total += teens(n)
        else:
            total += tens(n)
            total += ones(n % 10)
    # hundreds
    elif countdigits(n) == 3:
        if numstr[1] == "0" and numstr[2] == "0":
            total += hundreds(n // 100)            
            total -= 3
        elif numstr[1] == "1":
            total += hundreds(n // 100)
            total += teens(n % 100)
        else:
            total += ones(n % 10)
            total += hundreds(n // 100)
            total += tens((n // 10) % 10)
    return total

# Function to iterate through range of numbers summing letter counts
def sumitup(n):
    summ = 0    
    for x in range(1, n+1):
        summ += combine(x)
    if n == 1000:
        summ += 11
    return summ

print "The total is: ", sumitup(1000)
