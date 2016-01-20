# -*- coding: utf-8 -*-
"""
Created on Mon Jan 18 23:27:35 2016

@author: Ben
"""

# Open file, read data to buffer as a string
f = open('names.txt', 'r')
data = f.read()

# Split string and put each name in list, then alphabetize
# NOTE: List of names, arr, is not needed again, so sort() instead of sorted()
names = data.split(",")
arr = []
for name in names:
    arr.append(name.strip('"'))
arr.sort()

# Create list of name-values based on letters
totals = []
for name in arr:
    total = 0
    for letter in name:
        total += ord(letter) - 64
    totals.append(total)

# Make each value in that list a product of name-value and position, then sum
summ = 0
for i in range(0, len(totals)):
    summ += (i + 1) * totals[i]
print summ

# Close the file
f.close()
