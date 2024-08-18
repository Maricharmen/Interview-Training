/**
 * Minesweeper
 * 
 * You are given an m x n char matrix board representing the game board where:
 * 
 * 'M' represents an unrevealed mine,
 * 'E' represents an unrevealed empty square,
 * 'B' represents a revealed blank square that has no adjacent mines 
 * (i.e., above, below, left, right, and all 4 diagonals), digit ('1' to '8') 
 * represents how many mines are adjacent to this revealed square, and
 * 'X' represents a revealed mine.
 * 
 * You are also given an integer array click where click = [clickr, clickc] 
 * represents the next click position among all the unrevealed squares ('M' or 'E').
 * 
 * Return the board after revealing this position according to the following rules:
 * 
 * If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
 * 
 * If an empty square 'E' with no adjacent mines is revealed, then change it 
 * to a revealed blank 'B' and all of its adjacent unrevealed squares should be
 * revealed recursively.
 * 
 * If an empty square 'E' with at least one adjacent mine is revealed, then change 
 * it to a digit ('1' to '8') representing the number of adjacent mines.
 * 
 * Return the board when no more squares will be revealed.
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution_V1{
public:

    vector<vector<char>> minesweeper( vector<vector<char>>& game, pair<int, int>& click){ 
        vector<vector<bool>> visited(game.size(), vector<bool>(game[0].size(), false));
        dfs( game, click.first, click.second, visited);
        return game;
    }

    void dfs(vector<vector<char>>& game, int x, int y, vector<vector<bool>>& visited ){

        if( x < 0 || y < 0 || x >= game.size() || y >= game[0].size() || visited[x][y]) return;

        char current = game[x][y];
        visited[x][y] = true;

        if( current == 'M'){
            game[x][y] = 'X';
            return;
        }

        int mineCount = countMineAdjacency( game, x, y, visited);

        if( mineCount > 0){
            game[x][y] = '0' + mineCount;
            return;
        }else{
            game[x][y] = 'B';
        }

        for( int i=-1; i <= 1; i++){
            for( int j=-1; j <= 1; j++){

                int dx = x + i;
                int dy = y + j;

                dfs(game, dx, dy, visited);

            }
        }

    }

    int countMineAdjacency(vector<vector<char>>& game, int x, int y, vector<vector<bool>>& visited ){
        int count = 0;

        for( int i=-1 ; i <= 1; i++){
            for( int j=-1; j <= 1; j++){
                int dx = x + i;
                int dy = y + j;
                if( dx >= 0 && dy >= 0 && dx < game.size() && dy < game[0].size() && game[dx][dy] == 'M'){
                    count++;
                }
            }
        }

        return count;
    }

    void printSolution( vector<vector<char>>& game, pair<int, int>& click){
        vector<vector<char>> newGame = minesweeper(game, click);

        for(int i=0; i<game.size(); i++){
            for( int j=0; j<game[0].size(); j++ ){
                cout<<newGame[i][j]<<" ";
            }
            cout<<"\n";
        }

    }
};

void testCases(){
    vector<vector<char>> testCases {
        { {'E', 'E', 'E', 'E', 'E'},  // B 1 E 1 B 
          {'E', 'E', 'M', 'E', 'E'},  // B 1 M 1 B
          {'E', 'E', 'E', 'E', 'E'},  // B 1 1 1 B
          {'E', 'E', 'E', 'E', 'E'} } // B B B B B
    };

    pair<int, int> click = {3,0};

    Solution_V1 sol;

    sol.printSolution(testCases, click);

}

int main(){
    testCases();
}

