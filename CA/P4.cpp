/*
Problem 4: Triplet Difference Counter
Description:

Given a set of operations that modify a set of numbers, you must determine the number of valid triplets that satisfy a constant difference between their elements. The sequence of operations is provided as a list of strings, where each string represents an operation and an associated number.

Operations:

+x: Adds the number x to the set.
-x: Removes the number x from the set if it is present.
A valid triplet is one that satisfies the condition a - b = b - c = diff for a given value diff.

Input:

A list of strings operations representing the operations.
An integer diff representing the constant difference.
Output:

Return a list of integers representing the number of valid triplets after each operation.

Input: operations = ["+1", "+2", "+3", "+4", "-1"], diff = -1
Output: [0, 0, 1, 2, 1]

Explanation: 
- After the "+1" operation: No valid triplets exist.
- After the "+2" operation: No valid triplets exist.
- After the "+3" operation: A valid triplet (3, 2, 1) is formed.
- After the "+4" operation: Another valid triplet (4, 3, 2) is formed.
- After the "-1" operation: One triplet is removed, leaving one.

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> minimumRotation( vector<string>& elements){

}