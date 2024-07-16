## Site: LeetCode

**Link:** [Link](https://leetcode.com/problems/minimum-number-game/description/)

**Topic:** Array Sorting Heap

### 2974. Minimum Number Game

You are given a 0-indexed array nums of even lenght and there is also an empty array arr. Alice and Bob decided to play a game where in every round Alice and Bob will do one move. The rules if the game are as follows;
    - Every round, first Alice will remove the minimum element from nums, and then Bob does the same.
    - Now, first Bob will append the removed element in the array arr,
    and then Alice does the same.
    - The game continues until nums becomes empty.

Return the resulting array arr.

### Version 1 Timer: 21:42 minutes -Mock

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | ++    | +      | ++      | +        | ++         |
| **Time (min)** | | ## | ## | ## | ## |

### Notes
- Fallo en el segundo recorrido, es cuando la pq se vuelve vacia.