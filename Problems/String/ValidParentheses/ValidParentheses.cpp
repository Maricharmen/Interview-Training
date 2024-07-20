/**
 * 20. Valid Parentheses
 * 
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 * 
 */

#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class Solution_V1{
public:

    bool isValid( string s){

        stack<char> S;

        map<char, char> parentheses {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        for( int i=0; i < s.size(); i++){

            if( s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                S.push(s[i]);
            }else if( !S.empty() ){
                if( S.top() != parentheses[s[i]]) return false;
                else S.pop();
            }else return false;
        }

        if( !S.empty() ) return false;
        
        return true;

    }

    void printSolution( string s){
        cout<<isValid( s)<<" \n";
    }
};

void testCases(){
    vector<string> testCases {
        {"([][{}])"}, //Expected: 1
        {"{"}, // Expected 0
        {"{]}"}, //Expected 0
        {"{"}, // Expected 0
        {"()"}, // Expected 1
        {"()[]{}"}, // Expected 1
        {"(]"}, //Expected 0
        {"({}])"}, // Expected 0
        {"){"}, // Expected 0
        {"(("}, // Expected 0
        {")(){}"} //Expected 0
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}