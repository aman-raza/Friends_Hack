#Find all the vertices that lie on any shortest path between a given pair of vertices (n1, n2).
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

def vertices_on_shortest_path(n, edges, n1, n2):
	node = [n1, n2]
	arr = []
	for i in range(2):
		colour = [0 for j in range(n)]
		distance = [float('inf') for j in range(n)]
		parent = [-1 for j in range(n)]
		queue = deque()
		queue.append(node[i])
		distance[node[i]] = 0 
		colour[node[i]] = 1
		while queue:
			v = queue.popleft()
			for i in range(len(edges[v])):
				if colour[edges[v][i]] == 0:
					colour[edges[v][i]] = 1
					distance[edges[v][i]] = distance[v] + 1
					parent[edges[v][i]] = v 
					queue.append(edges[v][i])
			colour[v] = -1
		arr.append(distance)
	lis = []
	for i in range(n):
		if (arr[0][i] + arr[1][i]) == arr[0][n2]:
			lis.append(i)
	print(*lis)



def main():
	n, m = In()
	edges = {}
	for i in range(n):
		edges[i] = []
	for i in range(m):
		a, b = In()
		edges[a] += [b]
		edges[b] += [a]
	n1, n2 = In()
	vertices_on_shortest_path(n, edges, n1, n2)

    
    
if __name__ == '__main__':
    main()


""" 
Input:
n = number of nodes 
m = number ofedges
n1 = source node 
n2 = target node
(n, m
next m lines edges
n1, n2)

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
1 8

 Output: 1 2 7 8
"""