# To implement array class in Python

import ctypes

class Array:
    """ Array class implements 1D array in Python"""
    def __init__(self, size):
        assert size > 0, "Array size must be greater than 0"
        self._size = size
        PyArrayType = ctypes.py_object * size
        self._elements = PyArrayType()
        self.clear(None)

    # returns the size of the Array
    def __len__(self):
        return self._size

    # gets content of the array
    def __getitem__(self, index):
        assert index >= 0 and index < len(self), "Array subscript out of range"
        return self._elements[index]

    # Puts the value of the array in that position
    def __setitem__(self, index, value):
        assert index >=0 and index < len(self), "Array subscript out of range"
        self._elements[index] = value

    # returns arrays iterator,  traverse the _elements
    def clear(self, value):
        for i in range(len(self)):
            self._elements[i] = value

    # Returns iterator for the array
    def __iter__(self):
        return _ArrayIterator(self._elements)




# Class for iterator of the array
class _ArrayIterator(object):
    """_ArrayIterator: Returns array iterator for array data type."""

    def __init__(self, Array_element):
        self._arrayRef = Array_element
        self._curr_index = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self._curr_index < len(self._arrayRef):
            entry = self._arrayRef[self._curr_index]
            self._curr_index += 1
            return entry
        else:
            raise StopIteration


# Class for implementing 2D array data structure
class Array2D:
    """ Creates a 2D array using array of arrays concept.
    One array holds the starting index of the remaining arrays"""

    def __init__(self, numRows, numCols):
        # Array of length number of rows to hold the
        # positons of the rows
        self._theRows = Array(numRows)
        for i in range(numRows):
            # Length of each row is equal to the number of columns
            self._theRows[i] = Array(numCols)

    # Number of rows retured
    def numRows(self):
        return len(self._theRows)

    # Number of columns returned
    def numCols(self):
        return len(self._theRows[0])

    # Sets the array to an inital value
    def clear(self, value = None):
        for row in range(self.numRows()):
            self._theRows[row].clear(value)

    # Get item at index [i, j]
    def __getitem__(self, indexTuple):
        assert len(indexTuple) == 2, "Invalid subscripts"
        row = indexTuple[0]
        column = indexTuple[1]

        assert row >= 0 and row < self.numRows()\
        and column >=0 and column < self.numCols(),\
        "Array subscript out of range"

        return self._theRows[row][column]

    # Set item at index [i, j]
    def __setitem__(self, indexTuple, value):
        assert len(indexTuple) == 2, "Invalid subscripts"
        row = indexTuple[0]
        column = indexTuple[1]

        assert row >= 0 and row < self.numRows()\
        and column >=0 and column < self.numCols(),\
        "Array subscript out of range"

        self._theRows[row][column] = value
