# Extra Requirement pygame
import pygame
import math
import colorsys

win_width, win_height = 700, 700
pygame.init()
background = pygame.display.set_mode((win_width, win_height))
background.fill((0,0,0))
clock = pygame.time.Clock()

def hsv2rgb(h,s,v):
    return tuple(round(i * 255) for i in colorsys.hsv_to_rgb(h,s,v))

n = 1
out = False
wide = 0.4
while not out:
    clock.tick(60)
 
    for event in pygame.event.get():                     
        if event.type == pygame.QUIT:                    
            out = True 

    a = n * 137.5
    r = wide * math.sqrt(a)
    x = int(r * math.cos(a) + win_width/2)
    y = int(r * math.sin(a) + win_height/2)
    
    pygame.draw.circle(background, hsv2rgb((n%256)/100,1,1), (x, y), 2)
    pygame.display.update()
    n += 1
    if x > win_width:
        break
pygame.quit()
