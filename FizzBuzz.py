def fizzbuzz(num):
    if x % 3 == 0 and x % 5 == 0:
        return "Fizz Buzz"
    elif x % 3 == 0:
        return "Fizz"
    elif x % 5 == 0:
        return "Buzz"
    else:
        return x    

MAX_NUM = int(input("Enter Maximum Number: "))
for x in range (MAX_NUM):
    print (fizzbuzz(x))