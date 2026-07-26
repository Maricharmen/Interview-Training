/*
Google's infracstructure operations often break down massive network
packets into smaller batches of specific size to balance cluster loads.

Given a positive integer n, your task is to find all unique sequences 
composed exclusively of the numbers 1 and 2 that add up exactly to n.

Because our processing system requires deterministic scheduling, you 
must return these sequences ordered lexicographically (meaning sequences
starting with 1 should come before those starting with 2)

Input 
n = 3

Output
[1,1,1]
[1,2]
[2,1]

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution_V1{
public:

    vector<vector<int>> sequences; 

    void makingSequence(int n, int currentSum, vector<int> elements){
        
        if( currentSum >= n ){
            if(currentSum == n) sequences.push_back(elements);
            return;
        }

        elements.push_back(1);
        makingSequence( n , currentSum + 1, elements);
        elements.pop_back();
        
        elements.push_back(2);
        makingSequence( n ,  currentSum + 2, elements);
        elements.pop_back();

    }


    vector<vector<int>> uniqueSequence(int n){

        vector<int> elements;
        makingSequence(n, 0, elements);

        return sequences;
    }

    void printSolution( int n){
        for( auto s : uniqueSequence(n)){
            for( auto i : s){
                cout << i << " ";
            }
            cout << "\n";
        }
    }

};

class Solution_V2{
public:

    vector<vector<int>> uniqueSequence(int n){

        vector<vector<int>> sequences;

        stack<pair<int, vector<int>>> sequence;

        sequence.push( {0, {}} );

        while( !sequence.empty() ){

            int currentSum = sequence.top().first;
            vector<int> seq = sequence.top().second;
            sequence.pop();

            if( currentSum == n){
                sequences.push_back(seq);
            }
            
            if(currentSum < n){ 
                seq.push_back(1);
                sequence.push({currentSum + 1, seq });
                seq.pop_back();

                seq.push_back(2);
                sequence.push({currentSum + 2, seq });
                seq.pop_back();
            }

        }

        return sequences;
    }

    void printSolution( int n){
        for( auto s : uniqueSequence(n)){
            for( auto i : s){
                cout << i << " ";
            }
            cout << "\n";
        }
    }
};

int main(){
    vector<int> testCases {
        1,
        2,
        3,
        4   
    };

    for( auto test : testCases){
        Solution_V2 sol;
        sol.printSolution(test);
        cout << "\n";
    }
}


