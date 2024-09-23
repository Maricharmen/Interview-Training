/*
Problem 3: Number of Subarrays That Match a Pattern I

Description:

You are given a 0-indexed integer array nums of size n, and a 0-indexed integer array pattern of size m consisting of the integers -1, 0, and 1.

A subarray nums[i..j] of size m + 1 is said to match the pattern if the following conditions hold for each element pattern[k]:

nums[i + k + 1] > nums[i + k] if pattern[k] == 1.
nums[i + k + 1] == nums[i + k] if pattern[k] == 0.
nums[i + k + 1] < nums[i + k] if pattern[k] == -1.
You need to return the count of subarrays in nums that match the given pattern.

Input:

An integer array nums of size n.
An integer array pattern of size m consisting of the integers -1, 0, and 1.
Output:

Return an integer representing the number of subarrays in nums that match the pattern.

Input: nums = [1,2,3,4,5,6], pattern = [1, 1]
Output: 4

*/

#include <iostream>
#include <vector>
using namespace std;

int countmatchPattern( vector<int>& elements, vector<int>& pattern){

}