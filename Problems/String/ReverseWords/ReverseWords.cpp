/**
 * Reverse Words
 * 
 * Given a string, return with the order of the space-separed
 * word reversed
 * 
 */

/**
 * Input: String
 * Output: reversed words in the string
 * 
 * Example:
 * 
 * Hello, I am Maricarmen 
 * R: Maricarmen am I Hello, 
 * 
 * BREAKDOWNS:
 * - I can split all word and then add to stack.
 * - Take the top and add to new string, with a space.
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/**
 * Version
 * Approach: Stack
 */
class Solution_V1 {
public:

    /**
     * Complexity Time: O(n)
     * Compelxity Space: O(n)
     */

    string reversedWord(  string word ){

        stack<string> S;
        string reversedWord;
        int finalSubWord = 0, sizeSubWord = 0;

        while(  finalSubWord < word.size() ){

            if( !isspace(word[finalSubWord]) ){
                sizeSubWord++;
            }else if( sizeSubWord > 0 ){
                string subWord = word.substr(finalSubWord - sizeSubWord, sizeSubWord);
                S.push(subWord);
                sizeSubWord = 0;
            }

            finalSubWord++;
        }
 
        if( !isspace( word[word.size()-1] ) ){
            string subWord = word.substr(finalSubWord - sizeSubWord, sizeSubWord);
            S.push(subWord);
        }

        while( !S.empty()){
            reversedWord += S.top() + " ";
            S.pop();
        }

        reversedWord.pop_back();

        return reversedWord;
    }

    void printSolution( string s ){
        cout<<reversedWord(s)<<"\n";
    }
};

void testCases(){
    vector<string> testCases {
        {"Hello, I am Maricarmen"}, //Expected: "Maricarmen am I Hello,"
        {"Mari  a del   Carmen"}, //Expected: "Carmen del a Mari"
        {" M a r i "}, // Expected: "i r a M"
        {"  hello world  "} // Expected: "world hello"
    };

    Solution_V1 sol;

    for( auto test :testCases){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}
