/**
 * Word Pattern
 * 
 * Given a pattern and a string s, find if s follows the same 
 * pattern.
 * 
 * Here follow means a full match, such that there is a bijection 
 * between a letter in pattern and a non-empty word in s.
 * 
 */

/*
Input: string s and pattern code
Output: boolean true or false

BREAKDOWN:
- Every letter in my patter represent a word in my string s.
- A new word is when I finf space.
- Size pattern == number of word into my stirng
- 

Example:

pattern: "abba" s: "dog cat cat dog"

a -> dog  -> dog 
b -> cat ->cat

output: true


pattern: "abba" s: "dog cat dog dog"

a-> dog
b->cat
return false
output: false

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution_V1{
public:

    /**
     * Time Complexity: O(n log n)
     * Space Complexity: O(n)
     */

    bool wordPattern(string pattern, string s){

        map<string, char> validWord;
        map<char, string> validChar;

        int i=0, j=0, p=0;

        while( i < s.size() && p < pattern.size()){

            if( isspace(s[i]) ){

                string word = s.substr(j, i - j); 
                j = i + 1; 

                if( !validWord.count(word) && !validChar.count(pattern[p]) ){

                    validWord[word] = pattern[p];
                    validChar[pattern[p]] = word;
                    
                }else if( validWord[word] != pattern[p] || validChar[pattern[p]] != word) return false;
                
                p++;
            }

            i++;

        }

            if( p < pattern.size() - 1 || i < s.size() ) return false;

            string lastWord = s.substr(j, i - j);

            if( !validWord.count(lastWord) && !validChar.count(pattern[p])){
                validWord[lastWord] = pattern[p];
            }else if( validWord[lastWord] != pattern[p] || validChar[pattern[p]] != lastWord) return false;
            

        return true;
    }

    void printSolution( string s, string pattern){
        if( wordPattern(pattern, s)) cout<< "True \n";
        else cout<<"False \n";
    }
        
};


void testCases(){
    vector<pair<string, string>> testCases {
        {"abba", "dog cat cat dog"}, // Expected: True
        {"abba", "dog cat dog dog"}, // Expected: False
        {"abba", "dog dog dog dog"}, // Expected: False
        {"aaaa", "dog cat cat dog"}, // Expected: False
        {"a", "a"}, // Expected: True
        {"he","unit"}, // Expected: False
        {"a", "dog cat"}  // Expected: False

    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.second, test.first);
    }
}

int main(){
    testCases();
}
