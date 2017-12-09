numbers = [x for x in range(1,1000) if x % 3 == 0 or x % 5 == 0]
sum = 0
for number in numbers:
    sum += number
print sum
