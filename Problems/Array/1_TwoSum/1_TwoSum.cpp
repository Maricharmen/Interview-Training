/**
 * Two Sum
 * Given an array of integers nums and an integer target, return 
 * indices of the two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * Follow-up: Can you come up with an algorithm that is less than 
 * O(n2) time complexity?
 * 
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution_V1 {
public:

    /**
     * Complexity Time: O(n)
     * Complexity Space: O(1)
     */
    vector<int> twoSum( vector<int>& elements, int target){
        map<int, int> element;

        for( int i=0; i<elements.size(); i++ ){

            int searchElement = target - elements[i];

            if( element.count(searchElement)){
                return {element[searchElement], i};
            }

            element[elements[i]] = i;
        }

        return {};
    }

    void printSolution(  vector<int>& elements, int target ){
        for( auto index : twoSum(elements, target)){
            cout<<index<<" ";
        }
    }
};

void testCases(){
    vector<pair<vector<int>, int>> testCases {
        { {1,2,6,3,7} , 5 } // [1,3]
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}