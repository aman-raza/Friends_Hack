n=int(input("Enter a range"))
for i in range(1,n+1):
  if (i%3==0 and i%5==0):
    print(i,"= FizzBuzz")
  else:
    if(i%3==0):
      print(i,"= Fizz")
    elif(i%5==0):
      print(i,"= Buzz")
    else:
      print(i)
