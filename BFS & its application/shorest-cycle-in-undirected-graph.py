#Given an undirected unweighted graph. 
#The task is to find the length of the shortest cycle in the given graph. 
#If no cycle exists print -1.
import sys, os.path
if(os.path.exists('input_file.txt')):
    sys.stdin = open("input_file.txt","r")
    sys.stdout = open("output_file.txt","w")
import math
from itertools import permutations, combinations
from collections import defaultdict
from bisect import bisect_left 
from bisect import bisect_right
from collections import deque
 
def L():
    return list(map(int, input().split()))
 
def In():
    return map(int, input().split())
 
def I():
    return int(input())

P = 1000000007

def shortest_cycle(n, edges):
 	ans = P
 	for i in range(n):
 		dis = [float('inf') for i in range(n)]
 		parent = [-1 for i in range(n)]
 		queue = []
 		queue.append(i)
 		dis[i] = 0
 		while queue:
 			v =queue.pop(0)
 			for node in edges[v]:
 				if dis[node] == float('inf'):
 					dis[node] = dis[v] +1 
 					parent[node] = v
 					queue.append(node)
 				if parent[v] != node and parent[node] != v:
 					ans = min(ans, (dis[node]+dis[v]+1))
 	print(ans)
   
 
def main():
    n, m= In()
    edges = {}
    for i in range(n):
        edges[i] = []
    for i in range(m):
        a, b = In()
        edges[a] += [b]
    for i in range(n):
        edges[i].sort()
    shortest_cycle(n, edges)
    
    
if __name__ == '__main__':
    main()

""" 
Input:
n = number of nodes 
m = number ofedges
n1 = source node 
n2 = target node
(n, m
next m lines edges)

9 13
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

 Output: 3
"""