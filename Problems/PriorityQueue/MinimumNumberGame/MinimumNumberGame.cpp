/**
 * Minimum Number Game
 * 
 * You are given a 0-indexed array nums of even lenght and there is also 
 * an empty array arr. Alice and Bob decided to play a game where in 
 * every round Alice and Bob will do one move. The rules if the game are 
 * as follows;
 * 
 * - Every round, first Alice will remove the minimum element from nums, 
 * and then Bob does the same.
 * - Now, first Bob will append the removed element in the array arr,
 * and then Alice does the same.
 * - The game continues until nums becomes empty.
 * 
 * Return the resulting array arr.
 */

/**
 * Input:  array of integers(Elements) and empty array
 * Output: array of choises 
 * 
 * BREAKDOWNS:
 * - Each player have one turn.
 * - First Alice then Bob
 * - Every player in your turn, always remove the minimun element (ELements) 
 * - The element of Bob add to array and then Alice 
 * - Return array of choises 
 * 
 * APPROACH:
 * - for every play traverse the array and find the minimun element 
 *   Time: O(n^2) Space: O(n)
 * 
 * - Build priority queue -> nlogn 
 * -for every play traverse the array and find the minimun element -> o(n)
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Version 1
 * Approach: Min Heap
 */
class Solution_V1{
public:

    /**
     * Complexity Time: O(nlogn)
     * Complexity Space: O(n)
     */
    vector<int> minimumNumberGame( vector<int>& elements, vector<int>& choices){
        priority_queue<int, vector<int>, greater<> > minimum;

        for( auto element : elements){
            minimum.push(element);
        }

        while(!minimum.empty()){
            
            int AliceChoice = minimum.top(); minimum.pop();
            int BobChoice = minimum.top(); minimum.pop();

            choices.push_back(BobChoice);
            choices.push_back(AliceChoice);
        
        }

        return choices;
    }

    void printSolution( vector<int>& elements, vector<int>& choices ){
        for( auto choice : minimumNumberGame(elements, choices)){
            cout<<choice<<" ";
        }
        cout<<"\n";
    }
};

void testCases(){
    vector<pair<vector<int>, vector<int>>> testCases {
        {{5,4,6,8,2,1}, {}}, // Expected [ 2, 1, 5, 4, 8, 6]
        {{3,2,5,4}, {}}, // Expected [3,2,5,4 ]
        {{2,5}, {}} //Expected [5,2]
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}



