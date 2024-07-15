## Site: LeetCode

**Link:** [Link](https://leetcode.com/problems/jump-game-ii/description/)

**Topic:** Graph - Greedy

### 45. Jump Game II

You are given a 0-indexed array of integers nums of lenght n. You are initially positioned at num[0].

Each element num[i] represents the maximum lenght of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i+j]
where:

0 <= j <= nums[i] and
i+ j < n 

Return the minimum number of jumps to reach num[n-1]. The test cases are generated such that you reach num[n-1].

### Version 1 Timer: 26:16 minutos -No mock

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +++   | +      | +       | ++       | ++         |
| **Time (min)** | | ## | ## | ## | ## |

### Notes
- Obtuve la idea de una entrevista simulada, e imediatamente supe como implementarlo
 usando grafos, sin haber tenido la idea me iba a costar un poco mas imaginar un grafo.
- Mis primeros pensamientos fueron Greedy.
- Fallas con la contruccion del grafo, tuve que imprimirlo para ver que estaba pasando.
- Asignacion del minimo, ya sabemos que el primer encuentro con el grafo siempre sera el
  minimo, pero falto agregar la condicion. 

### Version 2 Timer: 29:54 minutos -No mock

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +++   | +++    | +       | ++       | +++        |
| **Time (min)** | | ## | ## | ## | ## |

### Notes
- Fallos para el tercer caso.
- Mala logica en la asignacion del camino mas corto en los iteradores.
- Falto inicializar el caso base para continuar DP.

### Version 2 Timer: 5:29 minutos -No mock

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +++   | +++    | +       | +++       | +        |
| **Time (min)** | | ## | ## | ## | ## |

### Notes
- Pensamientos vagos para hallar la solucion, tuve que buscar ayuda para implementar
 greedy.