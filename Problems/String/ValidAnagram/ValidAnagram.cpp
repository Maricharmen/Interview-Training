/**
 * Valid Anagram
 * 
 * Given two strings s and t, return true if t is an anagram of s, 
 * and false otherwise.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters 
 * of a different word or phrase, typically using all the original 
 * letters exactly once.
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution_V1{
public:

    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */

    bool isAnagram( string a, string b){

        if( a.size() != b.size() ) return false;
        
        map<char, int> wordA;
        map<char, int> wordB;

        for( int i=0; i<a.size(); i++){
            wordA[a[i]]++;
            wordB[b[i]]++;
        }

        for( int i=0; i<a.size(); i++){

            if( wordA[b[i]] <= 0 || wordB[a[i]] <= 0 ){
                return false;
            }else{
                wordA[b[i]]--;
                wordB[a[i]]--;
            }
        }

        return true;

    }

    void printSolution( string a, string b){
        if( isAnagram(a, b)) cout<<"True"<<"\n";
        else cout<<"False"<<"\n";
    }
};

void testCases(){
    vector<pair<string, string>> testCases {
        {"mari", "iram"}, //Expected: True
        {"cat", "rat"}, //Expected: False
        {" ", " "}, //Expected True
        {"maricarmen", "mari"}, //Expected: False
        {"aacc", "accc"} //Expected: False
    };

    Solution_V1 sol;

    for(auto test :testCases){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}