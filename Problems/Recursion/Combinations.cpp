/*
Site: LeetCode 
Topic: Combination

77. Combinations

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.

Approach: Recursion
The combine function generates all combinations of integers from 1 to range 
of a specified size sizeSubSet using recursive backtracking. It maintains a 
subset vector that stores the current combination being constructed. When 
the size of subset reaches sizeSubSet, it is added to the output vector of 
vectors that holds all valid combinations. The function iterates through 
possible elements starting from element up to range, recursively calling 
itself to explore further combinations by adding each element to subset 
and then backtracking by removing it before exploring the next possibility. 
This process continues until all valid combinations of the specified size 
are generated and stored in output. 

Required Time: 

Complexity Time: 
Add this part to the solution its going to cost us lenght K time, because
there is K elements in subset, because that is the item that 
we are looking for and calling list on a basically a list of K elements
is going to take O(k) times so that portion is O(k) and we do this
for every single combination that we generate so how many combinations
are there (math formula).

    O(k)*O(nCk) -> O(k)*O(n!/(n-k)k!)

Complexity Space: O(nCk)

Assumpitions: 

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void combine(vector<vector<int>>& output, vector<int>&subset, int range, int sizeSubSet, int element ){

        if( subset.size( ) == sizeSubSet ){
            output.push_back( subset ); 
            return; 
        }

        for( int j=element ; j <= range ; j++){
            subset.push_back(j);
            combine(output, subset, range, sizeSubSet, j+1 );
            subset.pop_back(); 

        }

    }

    void printSolution( int range, int sizeSubSet ){
        vector<vector<int>> output;
        vector<int> subset;
        combine(output, subset, range, sizeSubSet, 1 );

        for( auto subset : output ){
            cout<<"[ "; 
            for( auto element : subset ){
                cout<<element<<" ";
            }
            cout<<"]"; 
            
        }
        cout<<"\n";
    }
};

void testCases(){

    vector<pair<int, int>> testCases {
        {4, 2},
        {4, 3},
        {1, 1}
    };

    for( auto test :  testCases ){

        Solution sol;
        sol.printSolution(test.first, test.second);

    }

}


int main(){
    testCases();
    return 0;
}


