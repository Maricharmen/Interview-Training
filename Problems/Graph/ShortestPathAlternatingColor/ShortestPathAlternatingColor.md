## Site: Sergio Mock

**Link:** [Link] (https://leetcode.com/problems/shortest-path-with-alternating-colors/description/)

**Topic:** Graph

### 1129. Shortest Path with Alternating Colors

You are given an integer n, the number of nodes in a directed graph
where the nodes are labeled from o to n-1. Each edge is read o blue 
in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:
redEdges[i] = {a_i, b_i} indicates that there is a directed red edge
from node a_i to node b_i in the graph, and

blueEdges[j] = [u_j, v_j] indicates that there is a directed blue edge
from node u_j to node v_j in the graph.

Return an array answer of lenght n, where each answer[x] is the length 
of the shortest path grom node 0 to node x such that the edge colors 
alternate aling the path, or -1 if such a path does not exist.

### Version 1 -No mock

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +++   | ++     | ++      | ++       | ++++       |
| **Time (min)** | | 15 | 5 | 10 | 30 |

### Notes
- Para debugear no me di cuenta que habia encrito mal para la visita de los vecinos 
  verificaba si el nodo actual era el visitado en vez del vecino. Tuve que imprimir
  el grafo y hacer comentarios para ver que estaba pasando.
