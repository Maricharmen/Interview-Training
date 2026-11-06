/*
An array numbers consists of N two-digit numbers.

A group of numbers can be chosen from the array only if all of them share at least one digit.

For example, 52, 25, and 55 can be chosen together because they share digit 5, while 11, 52, and 34 cannot be chosen together.

Return the maximum number of array elements that can be chosen together.

Implement solution(numbers).

Link: https://www.fastprep.io/problems/google-maximum-elements-with-a-common-digit
Topic: Array Math

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int solution(vector<int> numbers) {

    int maximum = 0;
    vector<int> nums(10, 0);

    for(auto n : numbers){
        if( n/10 != n%10){
            nums[n/10]++;
            nums[n%10]++;
        }else{
            nums[n%10]++;
        }
    }

    for( int i=0; i < nums.size(); i++){
       maximum = max( maximum, nums[i]);
    }

    return maximum;

  }
};

int main(){

    Solution sol;
    cout << sol.solution({52, 25, 11, 52, 34, 55});
    cout << sol.solution({71, 23, 57, 15});
    cout << sol.solution({90, 90, 90});

}