## Site: CSES

**Link:** [Link](https://cses.fi/problemset/task/1669)

**Topic:** Graph

### Round Trip

Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.

Output
First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".

### Version 1 Give-Up

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | ++++  | #      | #       | #        | #          |
| **Time (min)** | | ## | ## | ## | ## |

### Notes
- No logre encontrar una solucion, hasta el segundo intento.
- Dificultades en encontrar la idea de guardar los padres de cada nodo.
- El guardado del camino final había que quitar los innecesarios.
- Dificultades en el retorno de la funcion para comprobar el ciclo.

### Version 1 1:26:46

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | ++++  | #      | #       | #        | #          |
| **Time (min)** | | ## | ## | ## | ## |

### Notes
- TLE, necesite ayuda para resolverlo. 
- Remplace el stack por solo el guardado de inicio y final.
- Luego solo volvia a recorrer con los datos del padre de cada nodo.
