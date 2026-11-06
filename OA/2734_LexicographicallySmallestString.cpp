/**
 * 2734. Lexicographically Smallest String Afeter Substring Operation
 * 
 * Given a string s consisting of lowercase English letters.
 * Perform the following operation
 * 
 * Select any non-empty substring then replace every letter of the substring
 * with the preceding letter of the English alphabet. For example 'b' is converted to
 * 'a', and 'a' converted to 'z'.
 * 
 * Return the lexicographically smallest string after performing the operation
 * 
 * Link: https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/description/
 * Topic: Greedy
 * 
 */

 /*
 acbbc
 abaab

 a-z
 97-122
 A-Z
 65-90
 */

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string smallestString(string s) {

        string duplicado = s;
        int band = 0;

        for( int i=0; i<s.size(); i++){

            if( s[i] != 'a'){
                duplicado[i] = s[i]-1;
                band = 1;
            }else if(band){
                break;
            }
        }

        if( duplicado == s ){
            duplicado[s.size()-1] = 'z'; 
        }

        return duplicado;
        
    }
};

int main(){
    Solution sol;
    vector<string> testCases = {
        "cbabc",
        "a",
        "aa",
        "acbbc",
        "leetcode",
        "bbbbbb",
        "abbbbabz",
        "aabcdacac"

    };
    
    for(auto test : testCases){
        cout << sol.smallestString(test) << '\n';
    }

}
