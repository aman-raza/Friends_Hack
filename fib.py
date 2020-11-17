# This is n-th fibonnaci number, and only works if n >= 0
def fib(n):
  prev, curr = 1, 0
  for i in range(n):
    prev, curr = curr, prev+curr
  return curr
  
# This is nearest fibonnaci number to n
def nearestFib(n):
  prev, curr = 1, 0
  while curr <= n:
    prev, curr = curr, prev+curr
  if abs(prev+curr) < abs(curr):
    return prev+curr
  return curr
