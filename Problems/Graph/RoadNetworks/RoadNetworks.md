## Site: UCP Homework

**Link:**

**Topic:** Graph

### RoadNetworks

In some states, it is not possible to drive between any two towns because they are not connected to the same road network. Given a list of towns and a list of pairs representing roads between towns, return the number of road networks. (For example, a state in which all towns are connected by roads has 1 road network, and a state in which none of the towns are connected by roads has 0 road networks).

### Version 1: - Mock

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** |  +    | ++     | ++      | ++       | +++        |
| **Time (min)** | | 15      | 10      | 15       | 20         |

### Notes
- Pensamiento de la solución a primera vista.
- Dificultades en hallar si era undirected o directed. -> Comprensión lectora
- Dominio en el recorrido DFS.
- Codeo normal.
- Lentitud en testCases.
- Explorar town by town lo que causó que towns sin conexiones sean contados. Cambié la visita de cada ciudad por la visita de nodos en el grafo.
- Al construir el grafo y no limpiarlo causó que para el test 2 se reutilicen datos. Agregué la limpieza del grafo.
- Tuve que imprimir el grafo para ver qué estaba pasando.

