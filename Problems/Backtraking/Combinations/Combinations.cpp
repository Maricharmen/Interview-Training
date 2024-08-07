/**
 * Combinations
 * 
 * Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
 * You may return the answer in any order.
 * 
 */

/**
 * Input: n(range) -> integer k (size of subset)-> integer
 * Output: All combinations of subset with size k
 * 
 * BREAKDOWNS:
 * - [2,3] is equal [3,2]
 * - I need vector to store all combination, vector to store subset. 
 * - Using a loop, when go to do a call increcent in + 1 the iterator.
 * 
 * 3 [1,2,3] 2 ->size
 * 
 *  [1]
 *   1->2->3
 *   
 *  [3]
 *
 *  [4]->4   
 * 
 *  
 * 
 *  K: 
 *  SS: 
 *  N: [1,2] [1,3]  [2, 3]
 * 
 * [1,2] [1,3] [2,3]
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Version 1
 * Approach: Backtracking
 */
class Solution_V1 {
public:

    /**
     * Complexity Time: O(k)*O(nCk) -> O(k)*O(n!/(n-k)k!)
     * Complexity Space: O(nCK)
     */

    vector<vector<int>> combinations;
    vector<int> subset;

    void generateCombination( int range, int sizeSet, int i){

        if( sizeSet == subset.size()){
            combinations.push_back(subset);
            return;
        }

        for( int j = i ; j <= range ; j++){

            subset.push_back(j);
            generateCombination( range, sizeSet, j + 1);
            subset.pop_back();
        }
    }

    void printSolution( int n, int k){
        generateCombination(n, k, 1);

        for( auto subset : combinations){   
            cout<<"[";
            for( auto number : subset){
                cout<<number<<" ";
            }
            cout<<"]\n";
        }
    }
};

void testCases(){
    vector<pair<int, int>> testCases {
        {3,2}, // Expected: [1,2] [1,3] [2,3]
    };

    Solution_V1 sol;

    for( auto test: testCases ){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}