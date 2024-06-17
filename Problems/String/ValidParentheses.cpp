/*
Site: GeekForGeeks
Link: https://leetcode.com/problems/valid-parentheses/description/
Topic: String - Stack

20. Valid Parentheses

Approach: Stack
Required Time: +++
Complexity Time: O(n)
Complexity Space: O(n)
Assumpitions: 

*/

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
using namespace std;

class Solution{
public:
    bool isValid_V1(string s) {

        stack<char> verification;

        for( int i=0; i<s.size(); i++){
            
            char open = s[i];

            if(  open == '(' || open == '{' || open =='['){
                verification.push(open);
            }else{
                if( !verification.empty() && 
                  ( (open == ')' && verification.top() == '(' )
                ||  (open == '}' && verification.top() == '{' )
                ||  (open == ']' && verification.top() == '[' ) ) ){
                    verification.pop();
                } else {
                    return false;
                }
            }

        }

        if( verification.empty())return true;
        else return false;
    }

    bool isValid_V2( string s){
        stack<int> verification;

        map<char,char> parenthesis {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };

        for( int i=0; i<s.size(); i++){

            char open = s[i];

            if( open == '(' || open == '{' || open =='['){
                verification.push(open);
            }else if( !verification.empty() && parenthesis[verification.top()] == open){
                verification.pop();
            }else{
                return false;
            }

        }

        if( verification.empty())return true;
        else return false;

    }

    void printSolution( string s){
        if( isValid_V2(s)) cout<<"True"<<"\n";
        else cout<<"False"<<"\n";
    }

};

void testCases(){

    vector<string> testCases = {
        {"{"}, //False
        {"()"}, //True
        {"()[]{}"}, //True
        {"(]"}, //False
        {"({}])"}, //False
        {"){"}, //False
        {"(("}, //False
        {")(){}"} //False
    };

    for( auto test : testCases){
        Solution sol;
        sol.printSolution(test);
    }

}

int main(){
    testCases();
    return 0;
}