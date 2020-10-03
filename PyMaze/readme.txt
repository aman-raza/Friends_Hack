This is just a little maze program I wrote which I plan on using in a
larger game. It's licensed under GPLv3, as included.

Running:
Must have Python and PyGame. You can just run:
python PyMaze.py
But there are three different command line args you can do.
The first one is the difficulty of the game, done with --diff:
python PyMaze.py --diff=0
Values are 0 or 1. 0 is an easier maze, 1 (default) is a harder one.
The other shell argument is --dim. It sets the initial dimensions of the maze.
python PyMaze.py --dim=10x20 (10 by 20 maze.) (30x40 is default)
Note that I wouldn't push it past 40x50 because the algorithm probably won't
be iterative until 1.3.
The third arg is --path. This basically lets you know where you've been or
haven't been. It's on by default, but it can be turned off like so:
python PyMaze.py --path=0

Controls:
Up, down, left, right moves the blue circle. Goal is to get to gold dot.
r resets the player, esc quits.

About the generation algorithm: it's fairly simple. It starts at a spot in the
maze (typically the start or end), puts that on the stack, sets the current
cell to the last in the stack, gets the neighbors around that. Then it loops
through the neighbors. If the neighboring cell hasn't been visited, it sets it
to visited, adds the neighbor to the stack, knocks down the wall between the
neighbor and the current cell, then cals the generate method again.
