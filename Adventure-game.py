import time
import sys

answer_left=["left","Left","LEFT"]
answer_right=["right","Right","RIGHT"]
answer_forward=["forward","Forward","FORWARD"]
answer_backward=["backward","Backward","BACKWARD"]

#Correct Answer : Right -> Left -> Forward -> Right

def intro():
print("You are in ROOM 1 now.")
print("What do you see in Room 1?")
    room1= input(" ")
print("Alright, You are in Room1 and you saw ",room1)
print("Enter the direction in which you want to continue :")
print("Left,Right,Forward")
time.sleep(1)
choice = input (">>>")
    direction1=choice
while (choice):
if choice in answer_left or choice in answer_forward:
            direction1=choice
print("You are in Room 1 and now you want to move ",direction1)
print("Walls present, can't move further in this direction ")
print("Re enter choice")
print("Left,Right,Forward")
time.sleep(1)
choice = input (">>>")
elif choice in answer_right: 
            direction1=choice
print("------------------------------------------------------------------------------------------------------")
print("Doors found. You opened the door and moved into ROOM 2")
print("So after starting the game in ROOM 1, you moved ",direction1," to go to room 2.")
print("What do you see in Room 2?")
            room2= input(" ")
print("Alright, You are in Room2 and you saw ",room2)
print("Enter direction you want to continue")
print("Left,Right,Forward,Backward")
time.sleep(1)
choice = input (">>>")
            direction2=choice
while (choice):
if choice in answer_right or choice in answer_forward :
                    direction2=choice
print("After starting in Room 1 you moved ",direction1," to go to room 2. Now you want to move ")
print(direction2," to go to Room 3")
print("Walls present, can't move further in this direction ")
print("Re enter choice")
print("Left,Right,Forward,Backward")
time.sleep(1)
choice = input (">>>")
elif choice in answer_backward:
                    direction2=choice
print("Oops we went back to Room 1 again by moving ",direction2,". Lets go back and try again.")
print("Re enter choice")
print("Left,Right,Forward,Backward")
time.sleep(1)
choice = input (">>>")
elif choice in answer_left:
                    direction2=choice
print("------------------------------------------------------------------------------------------------------")
print("Doors found. You opened the door and moved into ROOM 3")
print("So after starting the game in ROOM 1, you moved ",direction1," to go to room 2 and then you moved .")
print(direction2," to go to Room 3.")
print("What do you see in Room 3?")
                    room3= input(" ")
print("Alright, You are in Room3 and you saw ",room3)
print("Enter direction you want to continue")
print("Left,Right,Forward,Backward")
time.sleep(1)
choice = input (">>>")
                    direction3=choice
while (choice):
                        direction3=choice
if choice in answer_left or choice in answer_right:
                            direction3=choice
print("After starting in room 1 you moved ",direction1," to go to room 2.")
print("Then you moved ",direction2," to go to Room 3. Now you want to move ",direction3)
print("Walls present, can't move further in this direction ")
print("Re enter choice")
print("Left,Right,Forward,Backward")
time.sleep(1)
choice = input (">>>")
elif choice in answer_backward:
                            direction3=choice
print("Oops we went back to Room 2 again by moving ",direction3," Lets go back and try again.")
print("Re enter choice")
print("Left,Right,Forward,Backward")
time.sleep(1)
choice = input (">>>")
elif choice in answer_forward:
                            direction3=choice
print("------------------------------------------------------------------------------------------------------")
print("Doors found. You opened the door and moved into ROOM 4")
print("So after starting the game in ROOM 1, you moved ",direction1," to go to room 2 and then you moved ")
print(direction2," to go to Room 3 and then you moved ",direction3," to go to Room 4")
print("What do you see?")
                            room4= input(" ")
print("Alright, You are in Room4 and you saw ",room4)
print("Enter direction you want to continue")
print("1. Enter 1 to go left")
print("2. Enter 2 to go right")
print("3. Enter 3 to move forward")
print("4. Enter 4 to move backwards")
time.sleep(1)
choice = input (">>>")
                            direction4=choice
while (choice != "2"):         
if choice =="1" or choice == "3":
                                            direction4=choice
print("So after starting the game in ROOM 1, you moved ",direction1," to go to room 2 and then you moved ")
print(direction2," to go to Room 3 and then you moved ",direction3," to go to Room 4. Now you want to move ")
print(direction4," to go out of the house. ")
print("Walls present, can't move further in this direction ")
print("Re enter choice")
print("1. Enter 1 to go left")
print("2. Enter 2 to go right")
print("3. Enter 3 to move forward")
print("4. Enter 4 to move backwards")
time.sleep(1)
choice = input (">>>")

elif choice =="4":
                                            direction4=choice
print("Oops we went back to Room 3 again by moving ",direction4,".Lets go back and try again.")
print("Re enter choice")
print("1. Enter 1 to go left")
print("2. Enter 2 to go right")
print("3. Enter 3 to move forward")
print("4. Enter 4 to move backwards")
time.sleep(1)
choice = input (">>>")

else:
print("Wrong Choice. Please re enter.")
print("1. Enter 1 to go left")
print("2. Enter 2 to go right")
print("3. Enter 3 to move forward")
print("4. Enter 4 to move backwards")
time.sleep(1)
choice = input (">>>")
                                            direction4=choice
if choice == "2":
                                    direction4=choice
print("------------------------------------------------------------------------------------------------------")
print("Congratulations! You reached the exit.")
print("After starting the game in ROOM 1, you moved ",direction1," to go to ROOM 2, then moved ",direction2)
print(" to go to ROOM 3, then moved ",direction3," to go to ROOM 4 and finally moved right to go outside the house.")
print("You saw ",room1," in Room 1")
print("You saw ",room2," in Room 2")
print("You saw ",room3," in Room 3")
print("You saw ",room4," in Room 4")
print("GAME OVER.")
sys.exit()
else:
print("Wrong choice. Please re enter.")
print("Left,Right,Forward,Backward")
time.sleep(1)
choice = input (">>>")
                            direction3= choice
else:
print("Wrong choice. Please re enter.")
print("Left,Right,Forward,Backward")
time.sleep(1)
choice = input (">>>")
                    direction2=choice
else:
print("Wrong choice. Please re enter.")
print("Left,Right,Forward")
time.sleep(1)
choice = input (">>>")
            direction2=choice
intro()