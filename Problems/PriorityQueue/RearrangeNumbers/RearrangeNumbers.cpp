/**
 * Rearrange numbers in an array such that no two adjacent numbers are same. 
 * 
 * Given an array of integers. The task is to rearrange elements of the array such that
 * no two adjacent elements in the arrays are same. 
 * 
 * Examples:
 * 
 * Input: arr[] = {1, 1, 1, 2, 2, 2}
 * Output: {2, 1, 2, 1, 2, 1}
 * 
 * Input: arr[] = {1, 1, 1, 1, 2, 2, 3, 3}
 * Output: {1, 3, 1, 3, 2, 1, 2, 1}
 * 
 * Assumption:
 * I can to create a new array.
 * 
 * Input: array of integers any size 
 * Output: array with rearrange element
 * 
 * BREAKDOWNS:
 * - I could count the frecuency of every element. 
 * - What happen if are there a element with big frequency?
 *         -No always is possible 
 * - Before to add a element in the new array I need to know what was the previus elemet. 
 * 
 * {1, 1, 1, 1, 2, 2, 3, 3}
 *  1 2 1 3 1 2 3 1 
 * 
 * 1: 4 - 7
 * 2: 2 - 2
 * 3: 2 - 2
 * 
 * PQ: { 4:1 2:2 2:3}
 * 
 * New: { 1,   }
 *
 * Idea: Star with element with greater frequency
 * 
 * 1 2 1 3 1 2 3 1 **
 * 
 */


#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution_V1 {
public: 

    /**
     * Complexity Time: O(nlogn)
     * Complexity Space: O(n)
     */
    vector<int> rearrangeNums( vector<int> & elements ){

        map<int, int> frequencies;
        priority_queue<pair<int, int>> number;

        for( auto num : elements){
            frequencies[num]++;
        }

        for( auto num : frequencies){
            number.push( {num.second, num.first});
        }

        vector<int> newArray;

        pair<int, int> prev = {-1, -1};

        while( !number.empty() ){

            pair<int, int> maxNum = number.top();
            number.pop();

            newArray.push_back(maxNum.second);

            if( prev.first > 0){
                number.push(prev);
            }
            
            maxNum.first--;
            prev = maxNum;
        }

        if( newArray.size() != elements.size()) return {};

        return newArray;
    }

    void printSolution( vector<int>& elements){
        for( auto num : rearrangeNums(elements)){
            cout<<num<<" ";
        }

        cout<<"\n";
    }

};

void testCases(){
    vector<vector<int>> testCases {
        { 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3 }, //Expected: {}
        { 1, 1, 1, 1, 2, 2, 3, 3 }, //Expected: 1, 3, 1, 3, 2, 1, 2, 1
        { 1, 1, 1, 2, 2, 2 } //Expected: 2, 1, 2, 1, 2, 1
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}

