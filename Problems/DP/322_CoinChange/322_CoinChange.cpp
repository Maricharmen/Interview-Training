/**
 * 322. Coin Change
 * 
 * You are given an integer array coins representing coins of different denominations 
 * and an integer amount representing a total amount of money.
 * Return the fewest number of coins that you need to make up that amount. If that
 * amount of money cannot be made up by any combination of the coins, return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution_V1{
public:

    int coinChange( vector<int>& coins, int amount){

        vector<int> numberCoins( amount + 1, amount+1);

        numberCoins[0] = 0;

        for( auto coin : coins){
          
            for( int i=coin; i<=amount; i++){
                numberCoins[i] = min ( numberCoins[i], numberCoins[i - coin] + 1);
                
            }
           
        }

       if( numberCoins[amount] == amount + 1) return -1;

        return numberCoins[amount ];

    }

    void printSolution( vector<int>& coins, int amount){
        cout<<coinChange(coins, amount)<<"\n";
    }
};

void testCases(){
    vector<pair<vector<int>, int>> testCases {
        { {1,3,5}, 11}, // Expected: 3 [ 1 5 5 ]
        { {1,2,5}, 11}, // Expected: 3
        { {2}, 3 }, // Expected: -1
        { {5,2}, {9}}, //Expected: 3
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}