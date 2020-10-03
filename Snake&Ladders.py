import random

lad={1:38,4:14,8:30,21:42,28:76,50:67,71:92,80:99}
snk={97:78,95:56,88:24,62:18,48:26,44:3,34:6,32:10}

def play():
    p1=0
    p2=0
    
    print("Hey!! Lets play a game of Snakes and Ladders today.")
    print("The ladders are as follows:")
    print(lad)
    print()
    print("The Snakes are as follows:")
    print(snk)
    print()
    
    print("To roll the die press 1 and to quit press 0")
    
    p1n=input("Enter ypur name Player1:       ")
    p2n=input("Enter ypur name Player2:       ")
    
    
    while(p1n!=100 and p2n!=100):
        
        print(p1n," roll the die")
        ip1=int(input())
        
        if ip1==1:
            d=random.randint(1,6)
            print(p1n,"You got a ",d)
            p1=p1+d
            print("Your now at",p1)
            p1=ladder(p1)
            p1=snake(p1)
        else:
            break
        
        print(p2n," roll the die")
        ip2=int(input())
        if ip2==1:
            d=random.randint(1,6)
            print(p2n,"You got a ",d)
            p2=p2+d
            print("Your now at",p2)
            p2=ladder(p2)
            p2=snake(p2)
        else :
            break
        
        print(p1n,"=",p1,"and",p2n,"=",p2)
        print(d)
        if(p1n==100 or p2n==100):
            break
    
    if(p1==100):
        print("Hurray",p1n," you won")
    if(p2==100):
        print("Hurray",p2n," you won")
    
def ladder(p):
    f=0
    for i in lad:
        if i==p:
            p=lad[i]
            f=1
            break
        else:
            continue
    if f==1:
        print("Ladder")
        print("Your final position is ",p)
    return p

def snake(p):
    k=0
    for i in snk:
        if i==p:
            p=snk[i]
            k=1
            break
        else:
            continue
    if k==1:
        print("Snake")
        print("Your final position is ",p)
    return p
play()
