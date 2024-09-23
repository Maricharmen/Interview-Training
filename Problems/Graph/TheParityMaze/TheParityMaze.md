## Site: MariMock

**Link:** [Link]()

**Topic:** Graph

### The Parity Maze

In the mystical land of Graphoria, a network of enchanted nodes and paths forms a sprawling maze. Each path has a magical property, but not all loops in this maze are harmonious. Your quest is to find the most perfectly balanced loop—a loop with an even number of paths.

In this enchanted maze, there are several cycles, but only one cycle will align perfectly with the magical balance of parity. Your goal is to identify whether such a cycle exists and reveal its hidden enchantment.

Input:
An integer n representing the number of enchanted nodes.
A list of paths where each path[i] = [u, v] represents a magical connection between nodes u and v.

Output:
Return true if you find a perfectly balanced loop with an even number of paths, otherwise return false.

Constraints:
2 <= n <= 10^4
0 <= paths.length <= 2 * 10^4
0 <= u, v < n
u != v
No path is duplicated, and each node is connected by no more than one path.

### Version 1 43:08

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +++   | ++     | ++      | ++       | ++         |
| **Time (min)** | | ## | ## | ## | ## |

### Notes
- Proceso de pensamiento largo, en consideras las posibilidades de ciclos y propiedades
 de grafo bipartito.