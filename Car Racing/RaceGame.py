#!/usr/bin/python3
import pgzrun
from random import randint # import randint module from random lib

WIDTH = 700                 # width of the window
HEIGHT = 800                # height of the window
trackLeft = []              # list to store left barriers
trackRight = []             # list to store right barriers
trackCount = 0              # count the number of barriers
trackPosition = 350
trackWidth = 150            # width between left and right barriers
trackDirection = False
SPEED = 4                   # sets speed of the game
gameStatus = 0              # check the game state   0 : game running
                            #                        1 : car crashed
                            #                        2 : you win

gameStarted = False

car = Actor("racecar")              # load the race car image
car.pos = 350,560                   # position of the race car


def makeTrack():                    # function to make one barrie at the left and right
    global trackCount, trackLeft, trackRight, trackPosition, trackWidth
    trackLeft.append(Actor("bare", pos = (trackPosition-trackWidth, 0)))
    trackRight.append(Actor("bare", pos = (trackPosition + trackWidth, 0)))
    trackCount +=1

def updateTrack():
    global trackCount, trackPosition, trackDirection, trackWidth, gameStatus, SPEED
    b = 0
    while b < len(trackLeft):
        if car.colliderect(trackLeft[b]) or car.colliderect(trackRight[b]):
            gameStatus = 1
        trackLeft[b].y += SPEED
        trackRight[b].y += SPEED
        b += 1
    if trackLeft[len(trackLeft)-1].y > 32:
        if trackDirection == False: trackPosition += 16
        if trackDirection == True:  trackPosition -= 16
        if randint(0,4) == 1:   trackDirection = not trackDirection
        if trackPosition > 700 - trackWidth:
            trackDirection = True
        if trackPosition < trackWidth:
            trackDirection = False
        makeTrack()


def draw():  # pygame Zero draw function
    global gameStatus, trackCount, gameStarted
    screen.fill((128, 128, 128))

    if gameStatus == 0:
        car.draw()
        b = 0
        while b < len(trackLeft):
            trackLeft[b].draw()
            trackRight[b].draw()
            b += 1
        screen.draw.text("Your Current Score : " + str(trackCount), (10, 10), color=(255, 255, 255))
    if gameStatus == 1:
        #Red Flag
        screen.blit("redflag", (230, 230))
        screen.draw.text("To Win You Should Reach 500 !",(100, 60), color=(255, 128, 0), fontsize = 50 )
        screen.draw.text("Your Score : " + str(trackCount), (250, 130), color=(255, 255, 255), fontsize = 40 )
    if gameStatus == 2:
        #Chequered Flag
        screen.blit("finishflag", (230, 230))



def update():
    global gameStatus, trackCount, SPEED, trackWidth
    if gameStatus == 0:
        if keyboard.left:
            car.x -= 2
        if keyboard.right:
            car.x += 2
        if keyboard.up:
            car.y -= 2
        if keyboard.down:
            car.y += 2
        updateTrack()
   # rise the speed of the game
    if trackCount > 50   : SPEED = 5
   # if trackCount > 150  : trackWidth = 150     # low the track width
    if trackCount > 250  : SPEED = 6
   # if trackCount > 350  : trackWidth = 150
    if trackCount > 500  : gameStatus = 2       # you win: pass 500 barriers


makeTrack()  # Make first block of track
pgzrun.go()
