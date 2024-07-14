## Site: LeetCode

**Link:** [Link](https://leetcode.com/problems/maximal-network-rank/description/)

**Topic:** Graph

### 1615. Maximal NetWork Rank

There is an infrastructure of n cities with some number of roads 
connecting the cities. Each roads[i] = [a_i, b_i] indicates that 
there is a bidirectional road between cities a_i and b_i.

The network rank of two different cities is defined as the total
number of dictly connected roads to either city. If a road is directly
connected to both cities, it is only counted once. 

The maximal network rank of the infrastructure is the maximum
network rank of all pairs of different cities.

Given the integer n and the arrays roads, return the maximal 
network rank of the entire infrastructure.

### Version 1 Timer 45 minutes + 30 minutes - Mock

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +++   | ++     | +       | ++       | +++          |
| **Time (min)** | | 20 | 10 | 25 | 30 |

### Notes
- Para el caso de disconected graph tuvimos que modificar el codigo e imprimir
para ver los resultados que lazaba, aumento la complejidad. 