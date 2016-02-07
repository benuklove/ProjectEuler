# -*- coding: utf-8 -*-
"""
Created on Fri Feb 05 15:03:37 2016

@author: Ben
"""

import string

# problem 42

# Open file, read data to buffer as a string
f = open('p042_words.txt', 'r')
data = f.read()

# Split string and put each name in list, then alphabetize
# NOTE: List of names, arr, is not needed again, so sort() instead of sorted()
words = data.split(",")
arr = []
for word in words:
    arr.append(word.strip('"'))

# starting point for initial triangle number list length estimate
length = 0
for word in arr:
    if len(word) > length:
        length = len(word)
#print "Longest word: ", length

# all triangle numbers in a range (later determined that 20 was enough)
trinumarr = []
for x in range(1, 21):
    trinumarr.append(int((0.5) * x * (x + 1)))

# dict of letters corresponding to numbers
dictionary = dict(zip(string.ascii_uppercase, range(1, 27)))

# iterate over each word, getting total word value and check if a tri num
triwordcount = 0
for word in arr:
    total = 0
    for letter in word:
        total += dictionary[letter]
    if total in trinumarr:
        triwordcount += 1

print "Triwordcount: ", triwordcount

# Close the file
f.close()
