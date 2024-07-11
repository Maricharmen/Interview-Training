## Site: LeetCode - Mock

**Link:** [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

**Topic:** Array

### 121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock
on the i th day.

You want to maximize your profit by choosing a single day to buy one stock
and choosing a different day in the future to sell that stack.

Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.

### Version 1 

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | +     |  +     | +       | +         | ++         |
| **Time (min)** | | 5 | 2 | 2 | 5 |

### Notes
- Estaba obteniendo la diferencia de los iteradores y no de los valores.

### Version 2

|           | Level | Coding | Testing | Thinking | Debugging  |
|-----------|-------|--------|---------|----------|------------|
| **Score** | ++    | ++      | +      | ++      | ++          |
| **Time (min)** | | 5 | 5 | 10 | 5 |

### Notes
- Inicializacion de la variable minBuy, estaba intentando usar -INFINITY pero
  no era necesario, bastaba con pensar un el primer caso, del primer dia. 
