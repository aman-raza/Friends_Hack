#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: Sandip Dutta
"""
# To implement simple tree algorithms
# DFS on Binary Tree, 
# Problem Stateent :  sum of all leaf nodes

#number of nodes of tree
n = 10

'''we take starting node to be 0th node'''
''' tree is a directed graph here'''
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

def sum_of_leaf_nodes():
    '''sum of leaf nodes calculated'''
    # Empty tree
    if tree == None:
        return 0
    
    # Set 0 as visited
    visited[0] = True
    # total of all leaf nodes
    total = 0
    # Traverses the tree
    for node in range(n):
        # Get neighbours
        for neighbour in tree[node]:
            # If not visited neighbours, then go inside
            if not visited[neighbour]:
                # Mark as visited
                visited[neighbour] = True
                # if leaf node, add that value to total
                if isLeafNode(neighbour):
                    total += neighbour
    # Return the total                
    return total
# Print the sum  of the root nodesz
print("sum is {}".format(sum_of_leaf_nodes()))

# =============================================================================
# Make sure to turn visited to all False values as we will be reusing that 
# array again
# =============================================================================

# Recursive version of the above function
def sum_of_leaf_nodes_R(node):
    # Empty tree
    if tree == None:
        return 0
    
    total = 0
    # Set 0 as visited
    visited[node] = True

    # If leaf node, return the value of the node
    if isLeafNode(node):
        return node        
    
    # checks for all neighbours
    for neighbour in tree[node]:
        # If unvisited neighbours, visit
        if not visited[neighbour]:
            # Add leaf node sum to total
            total += sum_of_leaf_nodes_R(neighbour)
        
    # Return the total                
    return total

# Print the sum  of the root nodesz
print("sum is {}".format(sum_of_leaf_nodes_R(0)))

    
