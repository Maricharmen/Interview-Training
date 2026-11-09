/*
Compression and decompression

In this exercise, you're going to decompress a compressed string.

Your input is a compressed string of the format number[string] and the decompressed output form 
should be the string written number times. For example:

The input

3[abc]4[ab]c


Would be output as

abcabcabcababababc

2[3[a]b] 

2[aaab]
aaabaab

[2, 3]
[[a]
a[
aaab]
[aaab
aaabaaabaaab
[[a]b]

O(n*m) where n is the size of the string, m is the max valuo of a digit


Other rules

Numbers can have more than one digit. For example, 10[a] is allowed, and just means aaaaaaaaaa

One repetition can occur inside another. For example, 2[3[a]b] decompresses into aaabaaab

Characters allowed as input include digits, small English letters and brackets [ ].

Digits are only to represent the amount of repetitions.

Letters are just letters.

Brackets are only part of the syntax of writing repeated substring.

Input is always valid, so no need to check its validity.

Learning objectives: This question gives you the chance to practice with strings, recursion, 
algorithm, compilers, automata, and loops. It’s also an opportunity to work on coding with better efficiency.

N = length of the input compressed string s.
L = total length of the decompressed output string.
D = maximum nesting depth of brackets

Time Complexity O(N + L) -> O(L)
Space Complexity P(D + L) -> O(L)

If we measure strictly against the input length N, the time isn't bounded purely by N because nesting can 
cause exponential expansion relative to the input characters. Therefore, the time complexity is O(L), 
where L is the length of the fully decompressed string, since we must construct and copy every character into 
memory, plus O(N) to scan the input tokens. The auxiliary space is O(D) for the recursion 
stack where D is the maximum bracket depth, and O(L) to store the resulting decompressed string.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:

    
    string makeDescompressString(int &i, string &compresion){
        string substring = "";
        int times = 0;

        while( i < compresion.size()){
            if( isdigit(compresion[i])){
                times = times*10 + (compresion[i] - '0');
                i++;
            }else if( compresion[i] == '['){
                i++;
                string inner = makeDescompressString(i, compresion );
                cout << inner << " " << times << "\n"; 
                while(times > 0 ){ 
                    substring += inner;
                    times--;
                }
            }else if(compresion[i] == ']'){
                i++; 
                return substring;
            }else{
                substring += compresion[i];
                i++;
            }
        }
        
        return substring;
        
    }

    string descompressString( string compresion ){
        int i=0;
        return makeDescompressString(i, compresion);
    }
};

int main(){
    vector<string> testCases = {
        {"3[abc]4[ab]c"}, // abc abc abc ab ab ab ab c
        {"2[3[a]b] "} // aaabaab
    };
    Solution sol;

    for( auto test : testCases){
        cout << sol.descompressString(test) << "\n";
    }
}


