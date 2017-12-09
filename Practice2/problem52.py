# -*- coding: utf-8 -*-
"""
Created on Wed Jan 27 16:07:29 2016

@author: Ben
"""

# problem52
from itertools import permutations

#largest = raw_input()
largest = 10000000
smallest = 0

for x in range(12, largest):
    print x
    count = 0
    xs = str(x)
    perms = list(permutations(xs))
    perarr = []
    for a in perms:
        element = []
        i = 0
        for digit in a:
            element += a[i]
            i += 1
        newelement = "".join(y.strip("''") for y in element)
        perarr.append(newelement)
    
    # doubled
    dub = 2 * x
    ds = str(dub)
    if ds in perarr:
        count += 1

    # tripled
    trip = 3 * x
    ts = str(trip)
    if ts in perarr:
        count += 1

    # quadrupled
    quad = 4 * x
    qs = str(quad)
    if qs in perarr:
        count += 1
    
    # pentoupled
    pent = 5 * x
    ps = str(pent)
    if ps in perarr:
        count += 1
    
    # hexoupled
    hexa = 6 * x
    hs = str(hexa)
    if hs in perarr:
        count += 1
    
    # if each product is a permutation of original
    if count == 5:
        print smallest
        smallest = x
        break
        
print smallest
