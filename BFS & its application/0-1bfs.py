#Finding the shortest path in a graph with weights 0 or 1Finding the shortest path in a graph with weights 0 or 1
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

def zero_one_bfs(n, m, edges, s):
	distance = [ float('inf') for i in range(n)]
	queue = deque()
	distance[s] = 0 
	queue.append(s)
	while queue:
		v = queue.popleft()
		for i in range(len(edges[v])):
			if distance[edges[v][i][0]] > distance[v] + edges[v][i][1]:
				distance[edges[v][i][0]] = distance[v] + edges[v][i][1]
				if edges[v][i][1] == 0:
					queue.appendleft(edges[v][i][0])
				else:
					queue.append(edges[v][i][0])
	return distance


def main():
	#Enter the number of nodes and edges:
	n, m = In()
	#Enter the nodes and weight:
	edges = {}
	for i in range(n):
		edges[i] = []
	for i in range(m):
		n1, n2, w = In()
		edges[n1].append([n2, w])
		edges[n2].append([n1, w])
    #Enter the source node:
	s = I()
	lis = zero_one_bfs(n, m, edges, s)
	print(*lis)

    
    
if __name__ == '__main__':
    main()


"""
Input:
n = number of nodes 
m = number of edges
s = source node 
(n, m
next m lines edges
s)
9 13 
0 1 0
0 7 1
1 7 1
1 2 1
2 3 0
2 5 0
2 8 1
3 4 1
3 5 1
4 5 1
5 6 1
6 7 1
7 8 1
0 

Output: distace of each vertex from source node:
0 0 1 1 2 1 2 1 2
"""
