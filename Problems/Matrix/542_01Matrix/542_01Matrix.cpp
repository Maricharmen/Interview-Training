/**
 * 542. 01 Matrix
 * 
 * Given an m x n binary matrix mat, return the distance of the nearest 
 * 0 for each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 0 0 0  0 0 0
 * 0 1 0  0 1 0
 * 1 1 1  1 2 1
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int row = mat.size();
        int column =  mat[0].size();

        queue<pair<pair<int, int>, int>> Q;

        vector<vector<bool>> visited( row, vector<bool>(column, false));

        for( int x = 0; x < row ; x++){
            for( int y = 0; y < column ; y++){
                if( mat[x][y] == 0){
                    Q.push({{x, y}, 0});
                    visited[x][y] = true;
                }
            }
        }

        int CX[4] = {-1, 1, 0, 0};
        int CY[4] = {0, 0, -1, 1};
        
        while( !Q.empty() ){

            int a = Q.front().first.first;
            int b = Q.front().first.second;
            int distance = Q.front().second;
            Q.pop();

            for( int i = 0; i < 4 ; i++){

                    int x_0 = a + CX[i];
                    int y_0 = b + CY[i];

                    if( x_0 < 0 || x_0 >= row || y_0 < 0 || y_0 >= column ) continue;
                    if( !visited[x_0][y_0]  ){
                        Q.push({{x_0, y_0}, distance + 1});
                        mat[x_0][y_0] = distance + 1;
                        visited[x_0][y_0] = true;
                    }

            }
        }

        return mat;
    }

    void printSolution( vector<vector<int>>& mat){
        for( auto row : updateMatrix(mat) ){
            for( auto colum : row ){
                cout<<colum<<" ";
            }
            cout<<"\n";
        }
    }

};

int main(){

    vector<vector<vector<int>>> testCases {
        { { {1,1,0,0,1,0,0,1,1,0},
            {1,0,0,1,0,1,1,1,1,1},
            {1,1,1,0,0,1,1,1,1,0},
            {0,1,1,1,0,1,1,1,1,1},
            {0,0,1,1,1,1,1,1,1,0},
            {1,1,1,1,1,1,0,1,1,1},
            {0,1,1,1,1,1,1,0,0,1},
            {1,1,1,1,1,0,0,1,1,1},
            {0,1,0,1,1,0,1,1,1,1},
            {1,1,1,0,1,0,1,1,1,1}  }, 

            {{0,0,0},{0,1,0},{1,1,1}}

            }
    };

    Solution sol;

    for( auto test : testCases ){
        sol.printSolution(test);
    }
}