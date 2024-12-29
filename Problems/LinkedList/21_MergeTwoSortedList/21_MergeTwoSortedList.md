# [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/)

**Site:** LeetCode

**Level:** Easy 

**Topic:** Linked List

**Version 1 1:47:40 -Mock**

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | ++    | +++    | +       | +++      | ++         |
| **Time (min)** | | ## | ## | ## | ## |

**Notes**
- Problemas con la logica inicial, era correcta pero omitiste el detalles que 
 cuando alguna de las dos listas llegaba a null solo que unir la que faltaba pero
 intentaste recorrer todo, lo que hizo que pierdas tiempo.
 - Fallos en la implementacion de insert y buildLinkedList pero resulto al instante.

**Version 2 20:37 minutes**

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +     | ++     | +       | +        | +         |
| **Time (min)** | | ## | ## | ## | ## |

**Notes**
- Fallos en la implementacion de linkedlist.
    - El caso cuando head = nullptr
    - Uso de la funcion insert
    - Nombre repetidos en las estructuras de datos