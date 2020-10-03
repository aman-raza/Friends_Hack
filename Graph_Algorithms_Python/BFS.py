#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Python Code for Breadth First Search

@author: Sandip Dutta
"""
# Queue module has inbuilt queue and stack constructors
# Queue is constructor for a Queue
# enqueue : put() ; dequeue: get();
from queue import Queue

# To implement BFS in a graph
# BFS - Breadth First Search
# BFS is used to find the shortest distances between two nodes
# It scans things in a layer wise manner and finds the shortest path
# It puts the unvisited nodes of the current node in a queue. Then  
# it scans the queue and applies BFS to nodes in the queue.

# n = The number of nodes in the graph
n = 5

# g = Adjacency list of the Graph
g = [[1, 4],
     [0, 2],
     [1, 3, 4],
     [2, 4],
     [0, 2, 3]]

# Visited = an array of booleans; visited[i] denotes if ith node is 
# visited or not. <size = n>
visited = [False] * n

# solve: Applies BFS to get shortest path
def solve(s):
    # Define a QUEUE Of size n
    q = Queue(n)
    q.put(s)
    
    # mark the fact that we have visited the node
    visited[s] = True
    # prev , help shortest path
    # prev keeps track of who is who's parent
    # here we select -1 as null value since it will be useful in reversing
    # the list later
    prev = [-1] * n

    #get neighbors of the current node
    while not q.empty():
        node = q.get()
        # get neighbors of this node
        neighbors = g[node]
        
        for next in neighbors:
            if not visited[next]:
                # If unvisited neighbour, put in queue
                q.put(next)
                # mark the queue as visited
                visited[next] = True
                # mark the parent of previous queue
                prev[next] = node
    return prev

# reconstructPath(s, e, prev): 
def reconstructPath(s, e, prev):
    path = []
    at = e
    while at != -1:
        path.append(at)
        at = prev[at]
        
    path.reverse()
    
    if path[0] == s:
        return path
    return []

# BFS function is divided into two parts. 
# solve : executes BFS on start node
# reconstructPath: constructs the path from end to beginning
def BFS(s, e):
    # Do BFS on s
    prev = solve(s)
    
    # method for reconstructing path    
    return reconstructPath(s, e, prev)


#------------------------------------------
## Code for testing
path = BFS(0, 2)

print("path is {}".format(path))







