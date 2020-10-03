# Program for checking whether a number pair is Amicable or not
# Time complexity - O(n,m)

# user input integers to be checked
N,M = map(int, input().split())

# variable to store sums of factors of N and M
NFactorsSum = 0
MFactorsSum = 0

# summation of factors of N
for i in range(1, N//2+1):
    if(N%i == 0):
        NFactorsSum += i

# summation of factors of M
for i in  range(1,M//2+1):
    if(M%i == 0):
        MFactorsSum += i

#condition for two numbers to be Amicable
if(NFactorsSum == M and MFactorsSum == N):
    print("Amicable")
else:
    print("Not Amicable")