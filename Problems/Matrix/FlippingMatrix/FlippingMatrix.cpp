/**
 * Flipping Matrix
 * 
 * Sean invented a game involving a 2n x 2n matrix where each cell of 
 * the matrix contains an integer. He can reverse any of its rows or 
 * columns any number of times. The goal of the game is to maximize 
 * the sum of the elements in the n x n submatrix located in the 
 * upper-left quadrant of the matrix.
 * 
 * Given the initial configurations for q  matrices, help Sean reverse 
 * the rows and columns of each matrix in the best possible way so that
 * the sum of the elements in the matrix's upper-left quadrant is 
 * maximal.
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution_V1{
public:

    int flippingMatrix( vector<vector<int>>& matrix, int row, int column ){
        int maxSum = 0;

        for( int i=0; i<row/2 ; i++){
            for( int j=0; j<column/2 ; j++){

                int maxValue = max( {
                    matrix[i][j],
                    matrix[i][column-1-j],
                    matrix[row-1-i][j],
                    matrix[row-1-i][column-1-j]
                } );

                maxSum += maxValue;
            }
        }

        return maxSum;
    }

    void printSolution( vector<vector<int>>& matrix, int row, int column ){
        cout<<flippingMatrix(matrix, row, column)<<"\n";
    }
};

void testCases(){

    vector<pair<pair<int, int>, vector<vector<int>> >> testCases {
        { {2,2}, {{1,2}, {3,4}}}, // Expected: 4
        { {4,4}, {{112,42,83,119}, {56,125,56,49}, {15,78,101,43}, {62,98,114,108}}} // Expected: 114
    };

    Solution_V1 sol;

    for( auto test : testCases ){
        sol.printSolution(test.second, test.first.first, test.first.second);
    }
    
}

int main(){
    testCases();
}