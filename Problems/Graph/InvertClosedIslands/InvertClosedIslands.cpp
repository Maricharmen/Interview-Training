/*
Dada una matriz de NxM llena de 1s (tierra) y 0s (agua). Se garantiza que todo el borde 
exterior de la matriz es agua (0), por lo que ninguna isla toca las orillas.

Tu tarea:
Invierte los valores únicamente en el interior de la isla. 
Es decir:
Los 0s (lagos atrapados) cambian a 1.
Los 1s (tierra interna) cambian a 0.
Los 1s que forman el contorno o muro exterior de la isla no deben cambiar.

Entrada
0 0 0 0 0 0 0 
0 1 1 1 1 1 0
0 1 1 0 1 1 0
0 1 1 1 1 1 0
0 0 0 0 0 0 0

Salida
0 0 0 0 0 0 0 
0 1 1 1 1 1 0
0 1 0 1 0 1 0
0 1 1 1 1 1 0
0 0 0 0 0 0 0

Entrada
0 0 0 0 0 0 0 
0 1 1 1 0 0 0
0 1 1 0 1 0 0
0 1 1 1 1 1 0
0 0 0 0 0 0 0

Salida
0 0 0 0 0 0 0 
0 1 1 1 0 0 0
0 1 0 1 1 0 0
0 1 1 1 1 1 0
0 0 0 0 0 0 0

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool detectEdge( int x, int y, int row, int column){
        if( x < 0 || x >= row || y < 0 || y >= column ) return false;
        return true;
    }

    void coloringCellsDFS( int x, int y, vector<vector<int>>& map, 
                        vector<vector<int>>& colored, vector<vector<int>>& visited, 
                        int row, int column ){

        if( !detectEdge(x, y, row, column) || visited[x][y] ){
            return; 
        }

        colored[x][y] = 1;
        visited[x][y] = 1;

        if( map[x][y] == 1 ){
            return;
        }

        coloringCellsDFS(x + 1, y, map, colored, visited, row, column);
        coloringCellsDFS(x , y + 1, map, colored, visited, row, column);
        coloringCellsDFS(x - 1, y, map, colored, visited, row, column);
        coloringCellsDFS(x , y - 1, map, colored, visited, row, column);

    }


    void flipCells( vector<vector<int>> &map ){
        int row = map.size(), column = map[0].size();
        vector<vector<int>> visited(row, vector<int>(column, 0));
        vector<vector<int>> colored(row, vector<int>(column, 0));

        coloringCellsDFS(0, 0, map, colored, visited, row, column);

        for(int i=0; i < row ; i++){
            for(int j=0; j < column; j++){
                if( colored[i][j] == 0 ){
                    map[i][j] = !map[i][j];
                }
            }
        }

    }

    void printMatrix(vector<vector<int>>& map){
        int row = map.size(), column = map[0].size();
        for( int i=0; i < row; i++){
            for(int j=0; j < column; j++){
                cout << map[i][j] << " ";
            }
            cout << "\n"; 
        }
        cout << "\n";
    }

    void printSolution( vector<vector<int>>& map){
        printMatrix(map);
        flipCells(map);
        printMatrix(map);
    }

};

int main(){

    // Test cases 

    vector<vector<vector<int>>> testCases = {
        
        {
            {0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 0, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0}
        },

        {
            {0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0},
            {0, 1, 1, 1, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0}
        },

        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },

        {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0, 1, 1, 0},
            {0, 1, 1, 1, 0, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}
        }
    };

    for (auto& test : testCases) {
        Solution sol;
        sol.printSolution(test);
        cout << "-----------------------\n";
    }

}

