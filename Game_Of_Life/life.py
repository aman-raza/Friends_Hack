from array_functions import Array2D

# Class for Game of life

class LifeGrid:
    ''' LifeGrid is used to make a Grid for playing the game of Life
    by Conway.
    Here we take the value of dead to be 0 and 1 to be alive'''

    dead = 0
    alive = 1
    # Directions in which the neighbors can be
    _neighbour_directions = (
    (0, 1), (1, 0), (1, 1), (0, -1),
    (-1, 0), (-1, -1), (1, -1), (-1, 1)
    )
    # Initialise a grid, set all cells to dead
    def __init__(self, nrows, ncols):
        self.game_grid = Array2D(nrows, ncols)
        self.game_grid.clear( self.dead )

    # Returns the number of rows of Grid
    def numRows(self):
        return self.game_grid.numRows()

    # Returns the number of columns
    def numCols(self):
        return self.game_grid.numCols()

    # Configures the board for starting the simulation
    def configure(self, coordList):
        self.game_grid.clear(0)
        for row, col in coordList:
            self.setCell(row, col)

    # function to clear a cell
    def clearcell(self, row, col):
        self.game_grid[row, col] = self.dead

    #function to make a cell alive
    def setCell(self, row, col):
        self.game_grid[row, col] = self.alive

    #isLiveCell check whether cell is alive or not
    def isLiveCell(self, row, col):
        return self.game_grid[row, col] == self.alive

    # numLiveNeighbors returns the number of live neighbors of the chosen cell
    def numLiveNeighbors(self, row, col):
        numNeighbors = 0
        for i, j in self._neighbour_directions:
            try:
                numNeighbors += self.isLiveCell(row + i, col + j)
            except AssertionError:
                pass

        return numNeighbors

    def __getitem__(self, indxtuple):
        return self.game_grid[indxtuple[0], indxtuple[1]]

    def __setitem__(self, indxtuple):
        return self.game_grid[indxtuple[0], indxtuple[1]]
