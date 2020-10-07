#Find the shortest path of even length from a source vertex s to a target vertex t in an unweighted graph.
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

def edges_on_shortest_path(n, edges, s, t):
	arr = []
	colour = [0 for j in range(2*n)]
	distance = [float('inf') for j in range(2*n)]
	parent = [-1 for j in range(2*n)]
	queue = deque()
	queue.append(s)
	distance[s] = 0 
	colour[s] = 1
	while queue:
		v = queue.popleft()
		for i in range(len(edges[v])):
			if colour[edges[v][i]] == 0:
				colour[edges[v][i]] = 1
				distance[edges[v][i]] = distance[v] + 1
				parent[edges[v][i]] = v 
				queue.append(edges[v][i])
		colour[v] = -1
	print(distance[t])



def main():
	n, m = In()
	edges = {}
	for i in range(n):
		edges[i] = []
		edges[i+n] = []
	for i in range(m):
		a, b = In()
		edges[a] += [(b+n)]
		edges[(b+n)] += [a]
		edges[b] += [(a+n)]
		edges[(a+n)] += [b]
	s, t = In()
	edges_on_shortest_path(n, edges, s, t)

    
    
if __name__ == '__main__':
    main() 

"""
Input : 5 vertices (0 to 4), 6 edges
Source 0, Target 2

5 6
0 1
0 2
1 3
2 3
2 4
3 4
0 2

Output = 4

"""