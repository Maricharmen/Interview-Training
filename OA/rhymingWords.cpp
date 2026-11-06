/*
 *
 * Two words rhyme if their three-letter suffixes are identical. 
 * For example, "football" and "basketball" rhyme, but "cat" and "pet" do not rhyme. 
 * If at least one of the words is shorter than three letters, then the words do not rhyme.
 *
 * You are given a string S consisting of two words separated by a dash '-'.
 * Do they rhyme?
 *
 * Examples:
 * 1. Given S = "news-views", the function should return true.
 *    The three-letter suffixes of both words ("ews") are identical.
 *
 * 2. Given S = "at-cat", the function should return false.
 *    The first word is shorter than three letters.
 *
 * 3. Given S = "football-allal", the function should return false.
 *    Suffixes "all" and "lal" are different.
 *
 * 4. Given S = "-pet", the function should return false.
 *    The first word is empty.
 *
 * Constraints:
 * - N is an integer within the range [1..100].
 * - String S consists of lowercase letters (a-z) and exactly one dash '-'.
 * 
 * Topic: strings
 */


#include <bits/stdc++.h>
using namespace std;


class Solution{
public:

    bool isRhyming( string S){

        size_t dash_pos = S.find('-');

        int n = S.size();
        int len_w1 = dash_pos;
        int len_w2 = n - 1 - dash_pos;

        if (len_w1 < 3 || len_w2 < 3) {
            return false;
        }

        return (S[dash_pos - 3] == S[n - 3] &&
                S[dash_pos - 2] == S[n - 2] &&
                S[dash_pos - 1] == S[n - 1]);

    }

};

int main() {

    vector<string> testCases = {
        "news-views",
        "at-cat",
        "football-allal",
        "-a",
        "-pet"
    };

    Solution sol;
    for(auto test : testCases ){
        cout << sol.isRhyming(test) << '\n';
    }

    return 0;
}