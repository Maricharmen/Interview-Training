/**
 * Chessboard and Queens
 * 
 * Your task is to place eight queens on a chessboard so that no two 
 * queens are attacking each other. As an additional challenge, each 
 * square is either free or reserved, and you can only place queens 
 * on the free squares. However, the reserved squares do not prevent 
 * queens from attacking each other.
 * 
 * How many possible ways are there to place the queens?
 * 
 * Input
 * The input has eight lines, and each of them has eight characters. Each 
 * square is either free (.) or reserved (*).
 * 
 * Output
 * Print one integer: the number of ways you can place the queens.
 * 
 * Example
 * Input:
 * 
 * ........
 * ........
 * ..*.....
 * ........
 * ........
 * .....**.
 * ...*....
 * ........
 * 
 * Output:
 * 65
 * 
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution_V1 {
public: 

    int totalValid = 0;

    void countValidQueens( int position , int Q, int N,vector<bool>& row, vector<bool>& column, vector<bool>& positiveD, vector<bool>& negativeD, vector<string>& grid ){

        if( Q == 8){
            totalValid++;
            return;
        }

        for( int i = position; i < N ; i++){
            for( int j = 0 ; j < N ; j++ ){

                if( !row[i] && !column[j] && !positiveD[i+j] && !negativeD[i-j+N] && grid[i][j] != '*'){
                    row[i] = column[j] = positiveD[i+j] = negativeD[i-j+N] = true;
                    countValidQueens( i + 1 , Q + 1, N, row, column, positiveD, negativeD, grid);
                    row[i] = column[j] = positiveD[i+j] = negativeD[i-j+N] = false;
                }

            }
        }
        
    }

    void printSolution( vector<string>& grid ){

        int N = grid[0].size();

        vector<bool> row(N, false);
        vector<bool> column(N, false);
        vector<bool> positiveD(2 * N, false);
        vector<bool> negativeD(2 * N, false);

        countValidQueens(0, 0, N, row, column, positiveD, negativeD, grid);

        cout<<totalValid<<"\n";

    }
};

void testCases(){
    
    vector<vector<string>> testCases {
        { {"........"}, {"........"}, {"..*....."}, {"........"}, {"........"}, {".....**."}, {"...*...."}, {"........"}}
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }
 
}

int main(){
    testCases();
}