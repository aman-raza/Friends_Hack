#Find all connected components in an undirected graph in O(n+m) time.
import sys, os.path
if(os.path.exists('input_file.txt')):
    sys.stdin = open("input_file.txt","r")
    sys.stdout = open("output_file.txt","w")
import math
from itertools import permutations, combinations
from collections import defaultdict
from bisect import bisect_left 
from bisect import bisect_right
 
def L():
    return list(map(int, input().split()))
 
def In():
    return map(int, input().split())
 
def I():
    return int(input())

def find_connected_nodes(n, edges):
    colour = [0 for i in range(n)]
    distance = [float('inf') for i in range(n)]
    parent = [-1 for i in range(n)]
    arr = []
    for i in range(n):
        if colour[i] == 0:
            queue = [i]
            parent[i] = 'NIL'
            lis = [i]
            while queue:
                x = queue.pop(0)
                for i in range(len(edges[x])):
                    if colour[edges[x][i]] == 0:
                        colour[edges[x][i]] = 1 
                        parent[edges[x][i]] = x 
                        queue.append(edges[x][i])
                        lis.append(edges[x][i])
                colour[x] = -1
            arr.append(lis)
    return arr 
 
def main():
    n, m= In()
    edges = {}
    for i in range(n):
        edges[i] = []
    for i in range(m):
        a, b = In()
        edges[a] += [b]
        edges[b] += [a]
    for i in range(n):
        edges[i].sort()
    arr = find_connected_nodes(n, edges)
    for a in arr:
        print(*a)



    
    
if __name__ == '__main__':
    main()

""" 
Input:
n = number of nodes 
m = number of edges
(n, m
next m lines edges)

5 3
1 0 
2 3 
3 4


 Output:
0 1
2 3 4
"""