# THIS IS A GUESS THE NUMBER GAME
import random

print("Hello, what is your name?")
name=input()

print("well," +name+ ",i am thinking of a number between 1 to 20.")
secretnumber=random.randint(1,20)

for guessesTaken in range(1,7):
          print("Take a guess")
          guess = int(input())
          if guess < secretnumber:
               print("Your guess is too low")
          elif guess > secretnumber:
               print("Your guess is too high")
          else:
              break
               

if guess == secretnumber:
    print("good job,"+name+"!you guessed my number in " +str(guessesTaken)+ " guesses")
else:
    print("nope. the number i was thinking of was"+str(secretnumber))
