#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: Sandip Dutta
"""

#number of nodes of tree
n = 10

'''we take starting node to be 0th node'''
''' tree is a directed graph in CSE.'''
tree = [[1, 2],#0
        [3, 5],#1
        [7, 8],#2
        [4],#3
        [],#4
        [6],#5
        [],#6
        [],#7
        [9],#8
        []]#9

#Records if visited or not
visited = [False] * n

def isLeafNode(neighbour):
    '''checks if leaf node or not'''
    #[] evaluates to False
    # if tree[neighbour] is [], return True
    return not tree[neighbour]

def height(node):
    if not tree:
        # If empty tree return 1
        return -1
    if isLeafNode(node):
        return 0
    
    return max([height(x) for x in tree[node]])  + 1


## Height of the given tree
print(height(0))


              
              
    



