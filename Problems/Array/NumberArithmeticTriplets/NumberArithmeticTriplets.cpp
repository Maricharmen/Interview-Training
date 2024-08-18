/**
 * 2367. Number of Arithmetic Triplets
 * 
 * You are given a 0-indexed, strictly increasing integer array 
 * nums and a positive integer diff. A triplet (i, j, k) is an arithmetic 
 * triplet if the following conditions are met:
 * 
 * i < j < k,
 * nums[j] - nums[i] == diff, and
 * nums[k] - nums[j] == diff.
 * Return the number of unique arithmetic triplets.
 * 
 */



#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution_V1{
public:
    /**
     * Time Complexity: O(n^3)
     * Space Complexity: O(1)
     */
    int countTriplets( vector<int>& elements, int diff){

        int triplets = 0;

        for( int i=0; i<elements.size(); i++){
            for( int j= i+ 1; j<elements.size(); j++){
                for( int k = j + 1; k<elements.size(); k++){
                    if( elements[j]-elements[i] == diff && elements[k]-elements[j] == diff){
                        triplets++;
                    }
                }
            }            
        }

        return triplets;
    }

    void printSolution( vector<int>& elements, int diff){
        cout<<countTriplets(elements, diff);
    }
};

class Solution_V2{
public:
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    int countTriplets( vector<int>& elements, int diff ){

        int triplets = 0;
        map<int, bool> numbers;

        for( int i=0; i<elements.size(); i++) numbers[elements[i]] = true;

        for( int i=0; i < elements.size(); i++){
            if( numbers[elements[i] - diff] && numbers[elements[i] + diff]) triplets++;
        }
        
        return triplets;
    }

    void printSolution(vector<int>& elements, int diff){
        cout<<countTriplets(elements, diff)<<"\n";
    }

};

void testCases(){
    vector<pair<vector<int>, int>> testCases {
        { {0,1,4,6,7,10}, 3}, // Expected: 2
    };

    Solution_V2 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }  
}

int main(){
    testCases();
}
