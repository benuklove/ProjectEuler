"""

  Created on 6/27/2016 by Ben

  benuklove@gmail.com
  
  Starting from the top left and going to the bottom right,
  only moving right or down, how many routes are there through
  a 20 X 20 grid?

  I struggled for days to figure this out programmatically.
  I did notice Pascal's triangle and had to look up the combinatorics.

"""

from math import factorial

#  Dimension of grid
n = 20

#  Number of paths are the central binomial coefficients
paths = int((factorial(2 * n)) / ((factorial(n)) ** 2))
print(paths)
