/*
Given an arbitrary list of words, find the longest word that can have 
individual letters removed such that it remains a valid word all the ways
down to a single letter. 

List of Words: [a, at, sat, sin, stat, state, sting, string, estate,
restate, restated, restarted, resharpen, staring, starling]

Example chains could be:
starling -> staring -> string -> sting -> sing -> sin -> in -> i (8)
restarted -> restated -> restate -> estate -> state -> state -> sat -> a (9)

Similar:
https://leetcode.com/problems/longest-string-chain/description/


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

class Solution{
public:

    int findLongestString( string &word, set<string> &words, map<string, int> &memo){
        if( memo.count(word)) return memo[word];
        if( !words.count(word) ) return -1;
        if( word.size() == 1) return memo[word] = 1;

        int bestChildChain = 0;

        for( int i = 0; i < word.size(); i++ ){
            string substring = word.substr(0, i) + word.substr(i+1);
            if( words.count(substring)){
                int childChain = findLongestString(substring, words, memo);
                bestChildChain = max( bestChildChain, childChain); 
            }
        }

        if( bestChildChain > 0 ){
            memo[word] = 1 + bestChildChain;
        }else{
            memo[word] = 0;
        }

        return memo[word];

    }
    /*
    Time Complexity: ( N * L^2) N: number of valid words Y: Maximum length of a word
    O(NxL) to store set and map
    */
    string longestStringChain( vector<string>& validWords ){
        set<string> words;
        for( string word : validWords) words.insert(word);
        
        int maximumValue = 0;
        string longestString = "";
        map<string, int> memo;

        for( string word : validWords ){
            int maximum = findLongestString(word, words, memo);
            if( maximum > maximumValue ){
                maximumValue = maximum;
                longestString = word;
            }
        }

        return longestString;
    }

    
    /*
    Time Complexity: ( NlongN + N * L^2) N: number of valid words Y: Maximum length of a word
    O(NxL) to store set and map
    */
    string longestStringChain_V2( vector<string>& validWords ){

        if( validWords.empty()) return "";

        sort(validWords.begin(), validWords.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });

        unordered_map<string, int> values;
        int maxString = 0;
        string longestString = "";

        for( string &s : validWords){
            if(s.size() == 1) {
                values[s] = 1;
                maxString = 1;
                longestString = s;
            }
        }

        for( int i=0; i<validWords.size(); i++ ){
            string word = validWords[i];
            int currMax = 0;

            for( int c = 0; c < word.size(); c++ ){
                string substring = word.substr(0, c) + word.substr(c+1);
                if( values.count(substring)){
                    currMax = max(currMax, values[substring]);
                }
            }

            if( currMax > 0 ){
                values[word] = currMax + 1;
                if( values[word] > maxString){
                    longestString = word;
                    maxString = values[word];
                }
            }
        }

        return longestString;
        
    }

    void printSolution( vector<string> validWords){
        cout << longestStringChain_V2(validWords) << "\n";
    }
};

int main(){
    Solution sol;
    // 1. Caso base del enunciado (cadena más larga)
    sol.printSolution({"a", "at", "sat", "sin", "stat", "state", "sting", "string", "estate", "restate", "restated", "restarted", "resharpen", "staring", "starling"});
    // Salida: restarted

    // 2. Sin palabras de 1 letra (no se puede reducir por completo)
    sol.printSolution({"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"});
    // Salida: (cadena vacía)

    // 3. Ninguna palabra reducible (ejemplo clarificado en entrevista)
    sol.printSolution({"cat", "dog"});
    // Salida: (cadena vacía)

    // 4. Solo palabras válidas de 1 letra
    sol.printSolution({"a", "b", "c"});
    // Salida: a

    // 5. Palabras largas presentes pero solo una de 1 letra es reducible
    sol.printSolution({"a", "house", "computer"});
    // Salida: a

    // 6. Cadena lineal estricta
    sol.printSolution({"a", "ab", "abc", "abcd"});
    // Salida: abcd

    // 7. Lista vacía
    sol.printSolution({});
    // Salida: (cadena vacía)
    return 0;
}

/*
a ab ac abc

a = 1 

ab -> 2
a -> 1 + 1 
b -> 0

ac -> 2

abc -> 2 + 1
ab -> 2
bc -> 0
ac -> 2

*/