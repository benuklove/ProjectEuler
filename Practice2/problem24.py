# -*- coding: utf-8 -*-
"""
Created on Thu Jan 21 13:55:32 2016

@author: Ben
"""

from itertools import permutations

# Print the one-millionth lexicographic permutation of digits 0 - 9
perms = list(permutations(range(10), 10))

number = "".join(str(e).strip("[]") for e in perms[999999])
print number
