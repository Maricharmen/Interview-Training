/**
 * Adventure to Count Maximum Moves
 * 
 * You are given a numRows x numColums board and the 1-based coordinates 
 * of several lasers. A laser destroys every cell in its row and every cell in 
 * its colum
 * 
 * The robot starts at (curRow, curColumn). Its starting cell is protected, even
 * if it lies in a laser beam. The robot must choose exactly one of the four cardinal
 * directions and then keep moving in a staight line.
 * 
 * Return the maximum number of safe cells the robot can enter before it reaches the 
 * board boundary or the next cell would be destroyed
 * 
 * Link: https://www.fastprep.io/problems/databricks-advanture-to-count-moves
 * Topic: Matrix
 */

 #include <bits/stdc++.h>
 using namespace std;

class Solution {
public:
  int solution(int numRows, int numColumns, int curRow, int curColumn, vector<vector<int>> laserCoordinates) {
      int count = 0, maximum = 0;
      vector<int> row(numRows+1, 0);
      vector<int> column(numColumns+1,0);
    
      for(auto coord : laserCoordinates ){
        row[coord[0]] = 1;
        column[coord[1]] = 1;
      }

      int a = curRow;
      int b = curColumn;

      while( curRow-1 > 0 && !(row[curRow-1] || column[curColumn]) ){
        
        count++;
        curRow--;
      }

      maximum = max(maximum, count);
      count = 0; curRow = a; curColumn = b;

      while( curRow+1 <= numRows && !(row[curRow+1] || column[curColumn]) ){
     
        count++;
        curRow++;
      }

      maximum = max(maximum, count);
      count = 0; curRow = a; curColumn = b;

      while( curColumn-1 > 0 && !(row[curRow] || column[curColumn-1])){

        count++;
        curColumn--;
      }

      maximum = max(maximum, count);
      count = 0; curRow = a; curColumn = b;

      while( curColumn+1 <= numColumns && !(row[curRow] || column[curColumn+1])){
      
        count++;
        curColumn++;
      }

      maximum = max(maximum, count);
      count = 0;


    return maximum;
  }
};

int main(){
    Solution sol;
    cout << sol.solution(8, 8,5,3,{{1,6},{2,8}})<<"\n";
}