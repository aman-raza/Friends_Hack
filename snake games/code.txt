import pygame
import random
import os

pygame.init()

white = (255,255,255)
red =(255,0,0)
black =(0,0,0)

screen_width = 500
screen_height = 400
gameWindow = pygame.display.set_mode((screen_width,screen_height))

pygame.display.set_caption("snake game")
pygame.display.update()


clock = pygame.time.Clock()
font = pygame.font.SysFont(None,55)


def text_screen(text,color,x,y):
    screen_text = font.render(text,True,color)
    gameWindow.blit(screen_text,[x,y])

def plot_snake(gameWindow,color,snk_list,snake_size):
    for x,y in snk_list:
        pygame.draw.rect(gameWindow,color,[x,y,snake_size,snake_size])

def welcome():
    exit_game = False
    while not exit_game:
        gameWindow.fill(white)
        text_screen("welcome to game",red,100,100)
        text_screen("!!press space!! ",red,100,150)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit_game = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    gameloop()
        pygame.display.update()
        clock.tick(60)



def gameloop():

    score = 0
    exit_game = False
    game_over = False
    snake_x = 40
    snake_y = 50
    velocity_x = 0
    velocity_y = 0
    init_velocity = 1
    food_x = random.randint(30, screen_width / 2)
    food_y = random.randint(30, screen_height / 2)
    snake_size = 10
    fps = 70

    snk_list = []
    snk_length = 1

    if (not os.path.exists("hiscore")):
        with open("hiscore","w") as f:
            f.write("0")


    with open("hiscore", "r") as f:
        hiscore = f.read()
    while not exit_game:
        if game_over:
            with open("hiscore", "w") as f:
                f.write(str(hiscore))

            gameWindow.fill(white)
            text_screen("game over !!",red,120,150)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit_game = True
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RETURN:
                        welcome()

        else:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit_game = True

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RIGHT:
                        velocity_x = init_velocity
                        velocity_y = 0
                    if event.key == pygame.K_LEFT:
                        velocity_x = - init_velocity
                        velocity_y = 0
                    if event.key == pygame.K_UP:
                        velocity_y = - init_velocity
                        velocity_x = 0
                    if event.key == pygame.K_DOWN:
                        velocity_y = init_velocity
                        velocity_x = 0
                    if event.key == pygame.K_q:
                        score = score + 10

            snake_x = snake_x + velocity_x
            snake_y = snake_y + velocity_y

            if abs(snake_x-food_x)<6 and abs(snake_y-food_y)<6:
                score = score + 10
                # print("score: ",score * 10)
                food_x = random.randint(30, screen_width / 2)
                food_y = random.randint(30, screen_height / 2)
                snk_length = snk_length + 5
                if score> int(hiscore):
                    hiscore = score

            gameWindow.fill(white)
            text_screen("score: " + str(score) + "  hiscore :"+ str(hiscore), red, 5, 5)
            pygame.draw.rect(gameWindow,red,[food_x,food_y,snake_size,snake_size])

            head = []
            head.append(snake_x)
            head.append(snake_y)
            snk_list.append(head)
            if len(snk_list) > snk_length:
                del snk_list[0]
            if head in snk_list[:-1]:
                game_over = True

            if snake_x<0 or snake_x>screen_width or snake_y<0 or snake_y>screen_height:
                game_over = True
                print("!!game over!!")


            plot_snake(gameWindow,black,snk_list,snake_size)
        pygame.display.update()
        clock.tick(fps)
    pygame.quit()
    quit()
welcome()
