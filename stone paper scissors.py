import random

print("Hey Guys! Lets play a game of STONE, PAPER and SCISSORS!")
print()
print("So the rule is on the count of 3, you have to enter any one of 'ST' or 'PA' or 'SC' ")
print("So lets start.")

i=0
pi=0
pc=0
li=["ST","PA","SC"]

name=input("Enter your name please")
print()
print("Initial score : LAPPIE = 0 and ",name,"= 0")
print()

while(pi<5 and pc<5):
    print("Round ",i+1,":")
    print("1...  2...  3... Enter your choice")
    imp=input()
    ch=random.choice(li)
    print(ch)
     
    if(ch==imp):
        print("Draw, so the scores remains same")
    
    else:
        if(ch=="ST"):
            if(imp=="PA"):
                pi=pi+1
                print("You won.")
            elif(imp=="SC"):
                pc=pc+1
                print("I won.")
        elif(ch=="PA"):
            if(imp=="SC"):
                pi=pi+1
                print("You won.")
            elif(imp=="ST"):
                pc=pc+1
                print("I won.")
        elif(ch=="SC"):
            if(imp=="ST"):
                pi=pi+1
                print("You won.")
            elif(imp=="PA"):
                pc=pc+1
                print("I won.")
    
    print("LAPPIE = ",pc," and ",name,"= ",pi)
    i=i+1
    print()
          
if(pi==5):
    print("Congo! You won.")
else:
    print("Hurray! I won")       
          