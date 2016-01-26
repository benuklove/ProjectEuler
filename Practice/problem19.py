# -*- coding: utf-8 -*-
"""
Created on Fri Jan 22 20:52:21 2016

@author: Ben
"""

# Count the number of Sundays occurring on the 1st of the month

days = 0
months = 0
years = 0
SundayCount = 0
dayofweek = 0
for year in range(1900, 2001):
    if year % 4 == 0 or year % 400 == 0:
        for month in range(1, 13):
            if month == 2:
                for day in range(1, 30):
                    days += 1
                    dayofweek += 1
                    if dayofweek == 8:
                        if day == 1:
                            SundayCount += 1
                        dayofweek = 1
                months += 1
                #print month, "29"
            if (
                month == 4 or month == 6 or
                month == 9 or month == 11
               ):
                for day in range(1, 31):
                    days += 1
                    dayofweek += 1
                    if dayofweek == 8:
                        if day == 1:
                            SundayCount += 1
                        dayofweek = 1
                months += 1
                #print month, "30"
            if (
                month == 1 or month == 3 or month == 5 or month == 7 or
                month == 8 or month == 10 or month == 12
               ):
                for day in range(1, 32):
                    days += 1
                    dayofweek += 1
                    if dayofweek == 8:
                        if day == 1:
                            SundayCount += 1
                        dayofweek = 1
                months += 1
                #print month, "31"
    else:
        for month in range(1, 13):
            if month == 2:
                for day in range(1, 29):
                    days += 1
                    dayofweek += 1
                    if dayofweek == 8:
                        if day == 1:
                            SundayCount += 1
                        dayofweek = 1
                months += 1
                #print month, "28"
            if (
                month == 4 or month == 6 or
                month == 9 or month == 11
               ):
                for day in range(1, 31):
                    days += 1
                    dayofweek += 1
                    if dayofweek == 8:
                        if day == 1:
                            SundayCount += 1
                        dayofweek = 1
                months += 1
                #print month, "30"
            if (
                month == 1 or month == 3 or month == 5 or month == 7 or
                month == 8 or month == 10 or month == 12
               ):
                for day in range(1, 32):
                    days += 1
                    dayofweek += 1
                    if dayofweek == 8:
                        if day == 1:
                            SundayCount += 1
                        dayofweek = 1
                months += 1
                #print month, "31"
        
print days, "days"
print months, "months"
print SundayCount, "Sundays on the 1st of the month"
print dayofweek, "day of the week (number)"
