/**
 * Find the first repeating element in an array of integers
 * 
 * Given an array of integers arr[], The task is to find the index of
 * first repeating element in it i.e. the element that occurs more than
 * once and whose index of the first occurrence is the smallest.
 */

/**
 * Version 1
 * Approach: Hash Map
 * Assumption:
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution_V1{
public:

    /**
     * Complexity Time: O(n)
     * Complexity Space: O(1)
     */

    int firstRepeatingElement( vector<int>& elements ){

        map<int, int> index;
        int minIndex = elements.size();

        for( int i=0; i<elements.size(); i++){

            if( index.count(elements[i])){
                minIndex = min( index[elements[i]], minIndex);
            }

            index[elements[i]] = i;
        }

        return elements[minIndex];
    }

    void printSolution( vector<int>& elements){
        cout<<firstRepeatingElement(elements)<<"\n";
    }
};

void testCases(){
     vector<vector<int>> testCases {
        {10, 5, 3, 4, 3, 5, 6 }, //Expected 5
        {1, 2, 3, 3, 1, 2,}, //Expected 1
        {6, 10, 5, 4, 9, 120, 4, 6, 10} //Expected 6
     };

     Solution_V1 sol;

     for( auto test : testCases){
        sol.printSolution(test);
     }
}

int main(){
    testCases();
}