#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
@author - Sandip Dutta
'''
#----------------------------------------------------------------
# Python Program to implement Depth First Search
# Depth First Search is a very Simple Algorithm to traverse
# the graph
#----------------------------------------------------------------

#n : number of connected nodes in the graph
n = 5
# g is the adjacency list
# It is going to be a list of lists
# Index of each element is going to be the list of
# neighbors of that index
g = [[1, 4],
     [0, 2],
     [1, 3, 4],
     [2, 4],
     [0, 2, 3]]

# visited marks if each index is visited or not
# index of one element marked means we have visited it
visited = [False]*n 

# DFS function:
# Base Case: If we have visited a node, return
# Normal case, get one node and dfs on it


def DFS(at_):    #at_: specifies 'at' which node we are on
    # Base Case: if we have visited a node, return, we have no work here
    if visited[at_]:
        print(f"Came at_{at_}. Lets Go Back") 
        return
    # If we have not visited the node, mark the node as visited first
    visited[at_] = True
    
    # Print the node we have visited
    print(f"At_node_{at_}")    
    
    # Now we extract the node one by one, and do DFS in each
    for next_node in g[at_]:
        DFS(next_node)
        
# Testing Code
start_node = 0
DFS(start_node)
