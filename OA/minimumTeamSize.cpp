/**
 * Minimum Team Size
 * 
 * Students stand in a fixed order. The integer talent[i] is the talent of the student
 * at index i, and every talent is between 1 and talentCount
 * 
 * A valid team is a contiguous group that contains at least one student each 
 * talent from 1 through talentsCount
 * 
 * For every starting index i, find the minimum length of a valid team whose first student
 * is at index i. Return an array answer of the same length as talent, where answer[i] is
 * that minimum length. If no valid team can start at i, set answer[i] to -1.
 * 
 * Entrada 
 * 3, [1,2,1,3,2,3]
 * Salida
 * [4,3,3,-1,-1,-1]
 * 
 * Entrada 
 * 3, [1,2,3,2,1]
 * Salida
 * [3,4,3,-1,-1]
 * 
 * Link: https://www.fastprep.io/problems/microsoft-minimum-team-size-from-every-start
 * Topic: Two pointers 
 */

 #include <bits/stdc++.h>
 using namespace std;

class Solution {
public:
  vector<int> minimumTeamSizes(vector<int> talent, int talentsCount) {

    int size = talent.size();
    vector<int> result(size, 0);
    map<int, int> groupTalents;

    int l = 0, r = 0;
    while( r < size){

      groupTalents[talent[r]]++;

      while(groupTalents.size() == talentsCount && r < size){
         int distance = r-l+1;
         result[l] = distance;
         groupTalents[talent[l]]--;
         if( groupTalents[talent[l]] == 0){
           groupTalents.erase(talent[l]);
         }
         l++;
      }

      r++;

    }

    for(int i=l; i < size; i++){
      result[i] = -1;
    }

    return result;

  }

  void printSolution(vector<int> talent, int talentsCount){
      for(auto i : minimumTeamSizes(talent, talentsCount)){
        cout << i << " ";
      }
      cout << "\n";
  }
};

int main(){
  Solution sol;
  sol.printSolution({1,2,3,2,1}, 3); // 3, 4,3, -1,-1
  sol.printSolution({1,2,2,1,2,3,3},3); //  6 5 4 3 -1 -1 -1
}