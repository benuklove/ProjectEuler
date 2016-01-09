fiblist1 = []    # list of fib numbers
def fibi(n):
    a, b = 1, 2
    for i in range(n-1):
        a, b = b, a + b
        fiblist1.append(a)
    return a    # all of them

print fibi(33)
print fiblist1[0:33]    # all of them
fiblist = []
for number in fiblist1:
    if number %2 == 0:
        fiblist.append(number)

print fiblist    # just the even fib numbers
sum = 0
for item in fiblist:
    sum += item    # add all the even fib numbers
print sum
