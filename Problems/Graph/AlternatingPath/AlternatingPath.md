## Site: UCP Homework

**Link:** 

**Topic:** Graph

### AlternatingPath

Given an origin and a destination in a directed graph in which edges can be
blue or red, determine the length of the shortest path from the origin to the
destination in which the edges traversed alternate in color. Return -1 if no 
such path exists.

### Version 1: - Mock

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +++   | #      | #       | #        | #          |
| **Time (min)** |  | ## | ## | ## | ## |

### Notes
- TIEMPO EXCEDIDO, SIN SCORE. 
- Pensé en una solucion, que no funcionaba del todo, tardé al momento de codear.
- Recurrí a dibujar a mano y debugear, dandome cuenta que habían más cosas por definir.
- Recurrí por ayuda.
- Luego de la ayuda se resolvió el problema.

### Version 2: - No mock

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +++   | +++    | ++      | +        | +++        |
| **Time (min)** |  | 20 | 5 | 10 | 15 |

### Notes
- Funcionó para casos de prueba, fallo en el caso en el que contemplaba que para el nodo destino
llegaba rojo y azul, cuando no necesariamente. 
- Se agrego nuevo caso de el origen y destino son el mismo, se hizieron modificaciones sin problema.