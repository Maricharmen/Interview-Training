/**
 * 3075. Maximize Happiness of Selected Children
 * 
 * You are given an array happiness of length n, and a positive integer k
 * 
 * There are n children standing in a queue, where the ith child has happiness value
 * hapiness[i]. You want to select k children from these n children in k turns. 
 * 
 * In each turn, when you select a child, the happiness value of all the children that
 * have not been selected till now decreases by 1. Note that the happiness value cannot
 * become negative and gets decremented only if it is positive. 
 * 
 * Return the maximum sum of the happiness values of the selected children you can 
 * achieve by selecting k children.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        int timesDecresing = 0;
        long long sum = 0;

        for(int i=0; i < k; i++ ){
            if( happiness[i] - timesDecresing < 0) break;
            sum += happiness[i] - timesDecresing;
            timesDecresing++;
        }

        return sum;
        
    }

    void printSolution(vector<int>& happiness, int k){
        cout << maximumHappinessSum(happiness, k)<<"\n";
    }
};

int main(){
    vector<pair<vector<int>, int>> testCases = {
        {{1,1,1,1}, 2}, // 1
        {{2,3,4,5}, 1}, // 5
        {{1, 0, 45, 2},3} // 46
    };

    Solution sol;
    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }
}