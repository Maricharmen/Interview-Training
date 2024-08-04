
## Site: CSES

**Link:** [Link](https://cses.fi/problemset/task/1624)

**Topic:** Backtracking

### Chessboard and Queens

Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output
Print one integer: the number of ways you can place the queens.

### Version 1

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | ++++  | ++     | ++      | +++      | +++        |
| **Time (min)** | | ## | ## | ## | ## |

### Notes
- El problema ya lo habia realizado antes. Fallas en la logica de verificacion de cada casilla,
  solucionado por que no necesariamente todos lo despues son validos si depende de la columna,
  fila y diagonales. 