/**
 * 125. Valid Palindrome
 * 
 * A phrase is a palindrome if, after converting all uppercase letters 
 * into lowercase letters and removing all non-alphanumeric characters, 
 * it reads the same forward and backward. Alphanumeric characters 
 * include letters and numbers.
 * 
 * Given a string s, return true if it is a palindrome, or false otherwise.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution_V1{
public:

    bool isPalindrome( string phrase){
        
        int length = phrase.size();
        int low = 0, high = length-1;

        while( low < high ){

            while( !isalnum(phrase[low]) && low < high ){
                low++;
            }

            while( !isalnum(phrase[high]) && low < high ){
                high--; 
            }

            if( isalpha(phrase[low]) && isalpha(phrase[high]) ){
                if(tolower(phrase[low]) != tolower(phrase[high])) return false;
            }else if( phrase[low] != phrase[high]) return false;

            low++; high--;
        }

        return true;
    }

    void printSolution( string phrase ){
        if( isPalindrome(phrase)) cout<<"True";
        else cout<<"False";

        cout<<"\n";
    }
};

void testCases(){
    vector<string> testCases{
        {"HolaaloH"}, // Expected: true
        {"Maricarmen"}, // Expected: false
        {"123321"}, // Expected: true
        {" 1 2 3 3 2 1"}, // Expected: true
        { " a b c C B A"}, // Expected: true
        {".,"}
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}