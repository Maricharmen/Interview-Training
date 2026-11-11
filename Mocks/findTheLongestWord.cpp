/*
Given a string S and a set of words D, find the longest 
word in D that is a subsequence of S.

Word W is a subsequence of S if some number of characters, 
possibly zero, can be deleted from S to form W, without 
reordering the remaining characters.

Note: D can appear in any format (list, hash table, prefix tree, etc.

For example, given the input of S = "abppplee" 
and D = {"able", "ale", "apple", "bale", "kangaroo"} 
the correct output would be "apple"

   able 
S: abppplee 
     4


Time Complexity: O(n*S)  10^{3}* 10^{3] = 10^{6} n: number of words S: size if the string 
1 ~ 5x10^{8}


BREAKDOWN:
- Build a preprocess of S, where I have letter and ther indexes
- For every word, and each letter of that word, I will look at my preprocess (keep track current max size)
    - If it is there, I'll find the minimum index greter than my current index 
        - return it is valid word and return size of the word
    - if it is not, stop dont return size = 0
- return a maximum size

Time Complexity: O( S + N*L*logS ) S: size of s, N: number of words L: size of a word

test:
S = aaaaaaaa
["aaa"]
out = 3

a: [0,1,2]

The words "able" and "ale" are both subsequences of S, but they are shorter than "apple".
The word "bale" is not a subsequence of S because even though S has all the right letters, they are not in the right order.
The word "kangaroo" is the longest word in D, but it isn't a subsequence of S.
Learning objectives: this question gives you the chance to practice with algorithms and data structures. 
It’s also a good example of why careful analysis for Big-O performance is often worthwhile, as is careful exploration of common and worst-case input conditions.

Similar: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/

If there are multiple words of the same maximum length that are subsequences, we want to choose the lexicographically smallest one.

Constraints:

1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s and dictionary[i] consist of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    string findTheLongestWord(string S, vector<string>& words) {
        map<char, vector<int>> letters;

        for( int i=0; i<S.size(); i++){
            letters[S[i]].push_back(i);
        }

        int maximumSize = 0;
        string longestWord = "";

        /*
        "abppplee", {"able", "ale", "apple", "bale", "kangaroo"}

        a: [0]
        b: [1]
        p: [2,3,4]
        l: [5]
        e: [6,7]
        
        */

        for( string word : words ){ 
            int sizeWord = word.size();
            int lastIndex = -1;
            int c = 0;
            while(  c < sizeWord ){ 

                if( letters.count(word[c]) ){

                    vector<int> indexes = letters[word[c]];
                    auto it = upper_bound(indexes.begin(), indexes.end(), lastIndex);
                    if( it == indexes.end()) break;
                    lastIndex = *it;
                    cout << lastIndex << " ";
                    
                }else break;

                c++;

            }
            
            if( c == sizeWord ){
                
                if( sizeWord > maximumSize || 
                    (sizeWord == maximumSize  && word < longestWord ) ){
                    cout << word << " ";
                    maximumSize = sizeWord;
                    longestWord = word;
                    
                }
            }

        }

        return longestWord;
    }

    void printSolution( string S, vector<string>  words ){
        cout << findTheLongestWord(S, words) << "\n";
    }
};

int main(){
    Solution sol;
    sol.printSolution( "abppplee", {"able", "ale", "apple", "bale", "kangaroo"});
    sol.printSolution( "aaaaaaaaa", {"aaa"});
}