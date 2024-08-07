/**
 * Custom Sort String
 * 
 * You are given two strings order and s. All the characters of order 
 * are unique and were sorted in some custom order previously.
 * 
 * Permute the characters of s so that they match the order that order 
 * was sorted. More specifically, if a character x occurs before a 
 * character y in order, then x should occur before y in the permuted 
 * string.
 * 
 * Return any permutation of s that satisfies this property.
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution_V1{
public:

    string customSortString(string order, string s) {
        map<char, int> totalABC;

        for( auto c : s){
            totalABC[c]++;
        }

        string permutation;

        for( auto c : order){

            if( totalABC.count(c) ){

                while( totalABC[c] > 0 ){
                    permutation.push_back(c);

                     totalABC[c]--;
                }

            }

        }

        for( auto c : totalABC){
            if( c.second != 0){
                while( c.second > 0 ){
                    permutation.push_back(c.first);

                     c.second--;
                }
            }
        }

        return permutation;
    }

    void printSolution( string order, string s){
        cout<<customSortString(order,s)<<"\n";
    }
};

void testCases(){
    vector<pair<string, string>> testCases {
        {"cba","abcd"}, // Expected: cbad
        {"bcafg","abcd"} // Expected: bcad
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}