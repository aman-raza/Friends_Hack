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

def bfs(n, edges, s):
    colour = [0 for i in range(n)]
    distance = [float('inf') for i in range(n)]
    parent = [-1 for i in range(n)]
    colour[s] = 1 
    distance[s] = 0 
    parent[s] = 'NIL'
    queue = [s]
    arr = []
    while queue:
        x = queue.pop(0)
        arr.append(x)
        for i in range(len(edges[x])):
            if colour[edges[x][i]] == 0:
                colour[edges[x][i]] = 1 
                distance[edges[x][i]] = distance[x] + 1
                parent[edges[x][i]] = x 
                queue.append(edges[x][i])
        colour[x] = -1

    return arr 
 
def main():
    n, m, s = In()
    edges = {}
    for i in range(n):
        edges[i] = []
    for i in range(m):
        a, b = In()
        edges[a] += [b]
        edges[b] += [a]
    for i in range(n):
        edges[i].sort()
    arr = bfs(n, edges, s)
    print(*arr)



    
    
if __name__ == '__main__':
    main()

"""
Input:
n = number of nodes 
m = number of edges
s = source node 
(n, m, s
next m lines edges)
9 13 0
0 1
0 7
1 7
1 2
2 3
2 5
2 8
3 4
3 5
4 5
5 6
6 7
7 8

Output: array Breadth first traversal starting from source node
 0 1 7 2 6 8 3 5 4

"""