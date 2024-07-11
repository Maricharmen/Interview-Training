/**
 * Best Time to Buy and Sell Stock
 * 
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i th day.
 * 
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stack.
 * 
 * Return the maximum profit you can achieve from this transaction. If you cannot
 * achieve any profit, return 0.
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Version 1
 * Approach: All Cases
 * Assumptions: 
 */
class Solution_V1{
public:

    /**
     * Complexity Time: O(n^2)
     * Complexity Space: O(1) 
     */

    int maximumProfit( vector<int>& prices){
        int maximumProfit = 0;

        for( int i=0; i<prices.size(); i++){
            for( int j= i+1; j<prices.size(); j++){
                maximumProfit = max( prices[j] - prices[i], maximumProfit);
            }
        }

        return maximumProfit;
    }


    void printSolution( vector<int>& prices){
        cout<<maximumProfit(prices)<<"\n";
    }

};

/**
 * Version 2
 * Approach: Search Best Buy
 * Assumption:
 */

class Solution_V2{
public:

    /**
     * Complexity Time: O(n)
     * Complexity Space: O(1) 
     */

    int maximumProfit( vector<int>& prices ){

        int minBuy = -prices[0], maximumProfit = 0 ;

        for( int i=1; i<prices.size(); i++){
            minBuy = max(-prices[i], minBuy);
            maximumProfit = max( prices[i] + minBuy, maximumProfit);
        }

        return maximumProfit;
    }

    void printSolution(vector<int>& prices){
        cout<<maximumProfit(prices)<<"\n";
    }
};

void testCases(){
    vector<vector<int>> testCases {
        { 7,1,5,3,6,4}, //Expected 5
        { 7,6,4,3,1}  //Expected 0
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }

}

int main(){
    testCases();
}