# -*- coding: utf-8 -*-
"""
Created on Wed Feb 03 15:16:35 2016

@author: Ben
"""

# problem 40

numstr = ""
for x in range(1, 1000001):
    numstr += str(x)

prod = int(numstr[0]) * int(numstr[9]) * int(numstr[99]) * int(numstr[999]) * \
          int(numstr[9999]) * int(numstr[99999]) * int(numstr[999999])
          
print "Product: ", prod
