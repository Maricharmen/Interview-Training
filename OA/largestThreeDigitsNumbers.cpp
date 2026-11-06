/*
You are given an integer N. Your task is to return the largest three-digit integer that can be created using the digits of N.

You may rearrange the digits in any order, but you cannot use a digit more times than it appears in N.

For example, if N = 30919, you can form 993 because N contains two 9s and one 3. You cannot form 999 because there are only two 9s, or 219 because there is no 2.

Constraints
- N is an integer within the range specified in the original problem. The upper bound shown in your description is \(10^8\).

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestThreeDigit(int N){
        vector<int> digits(10,0);
        
        while(N>0){
            digits[N%10]++;
            N/=10;
        }

        int result = 0;

        for(int d = 9, count = 0 ; d >= 0 && count < 3; d--){
            while(digits[d]>0 && count < 3){
                result = result*10 + d;
                digits[d]--;
                count++;
            }
        }

        return result;

    }
};

int main(){
    vector<int> testCases = {
      93215,
      123
    };

    Solution sol;
    for( auto test : testCases){
        cout << sol.largestThreeDigit(test)<< '\n';
    }
}