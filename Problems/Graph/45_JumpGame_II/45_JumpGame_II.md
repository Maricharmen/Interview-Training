# [45. Jump Game II](https://leetcode.com/problems/jump-game-ii/description/)

**Site:** LeetCode

**Level:** Medium

**Topic:** Graph - Greedy

**Version 1 Timer: 26:16 minutos -No mock**

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +++   | +      | +       | ++       | ++         |
| **Time (min)** | | ## | ## | ## | ## |

**Notes**
- Obtuve la idea de una entrevista simulada, e imediatamente supe como implementarlo
 usando grafos, sin haber tenido la idea me iba a costar un poco mas imaginar un grafo.
- Mis primeros pensamientos fueron Greedy.
- Fallas con la contruccion del grafo, tuve que imprimirlo para ver que estaba pasando.
- Asignacion del minimo, ya sabemos que el primer encuentro con el grafo siempre sera el
  minimo, pero falto agregar la condicion. 

**Version 2 Timer: 29:54 minutos -No mock**

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +++   | +++    | +       | ++       | +++        |
| **Time (min)** | | ## | ## | ## | ## |

**Notes**
- Fallos para el tercer caso.
- Mala logica en la asignacion del camino mas corto en los iteradores.
- Falto inicializar el caso base para continuar DP.

**Version 3 Timer: 5:29 minutos -No mock**

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +++   | +++    | +       | +++       | +        |
| **Time (min)** | | ## | ## | ## | ## |

**Notes**
- Pensamientos vagos para hallar la solucion, tuve que buscar ayuda para implementar
 greedy.