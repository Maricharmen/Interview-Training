/*
Site: LeetCode
Link: https://leetcode.com/problems/two-sum/description/
Topic: Array - HashTable

1. Two Sum

Given an array of integers nums and an integer target, return 
indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order.

Follow-up: Can you come up with an algorithm that is less than 
O(n2) time complexity?


Approach: Combination using nested loop
Required Time: +
Complexity Time: O(n^2) 
Complexity Space: O(1)
Assumpitions: 

Approach: Hash Table
Required Time: +++
Complexity Time: O(n) 
Complexity Space: O(n)
Assumpitions:

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution{
public:
    vector<int> twoSum( vector<int>& elements , int target){

        for( int i=0; i<elements.size(); i++){
            for( int j=i + 1; j<elements.size(); j++){
                if( elements[i] + elements[j] == target){
                    return {i, j};
                }
            }
        }

        return {};
    }

    vector<int> twoSumFollowUP(vector<int>& elements, int target ){
        map<int, int> value;
    
        for( int i=0; i< elements.size(); i++){
            
            int seeking = target-elements[i];

            if(value.count(seeking) ){
                return {value[seeking], i};
            }

            value[elements[i]] = i;
        }

        return {};
    }

    void printSolution( vector<int>& elements , int target){
        cout<<"[ ";
        for( auto value : twoSumFollowUP(elements, target )){
            cout<<value <<" ";
        }
        cout<<"] \n";
    }
};

void testCases(){
    vector<pair<vector<int>, int>> testCases {
        {{2,7,11,15}, 9}, //[0,1]
        {{3,2,4}, 6}, //[1,2]
        {{3,3}, 6}, //[0,1]
    };

    Solution sol;
    
    for( auto test : testCases) {
        sol.printSolution(test.first, test.second);
    }


}

int main(){
    testCases();
    return 0;
}