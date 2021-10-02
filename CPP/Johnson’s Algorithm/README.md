# Algorithm johnsonAlgorithm(cost)

###### Input − The cost matrix of given Graph.
###### Output − Matrix to for shortest path between any vertex to any vertex.

### Algorithm :-

```
Begin
   Create another matrix ‘A’ same as cost matrix, if there is no edge between ith row and jth column, put infinity at A[i,j].
   for k := 1 to n, do
      for i := 1 to n, do
         for j := 1 to n, do
            A[i, j] = minimum of A[i, j] and (A[i, k] + A[k, j])
         done
      done
   done
   display the current A matrix
End
Example
```

I added .cpp file example, use below Output to test it

###### Output
```
Enter no of vertices: 3
Enter no of edges: 5
Enter the EDGE Costs:
1 2 8
2 1 12
1 3 22
3 1 6
2 3 4
Resultant adj matrix
0 8 12
10 0 4
6 14 0
```
