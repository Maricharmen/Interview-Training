/**
 * 3Sum
 * 
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution_V1{
public:
    vector<vector<int>> countUniqueTriplets( vector<int>& elements){
    
       vector<vector<int>> triplets;

       sort( elements.begin(), elements.end());

       for( int i=0; i<elements.size(); i++){

            if( i > 0 && elements[i] == elements[i-1]) continue;

            int left = i + 1;
            int right = elements.size() - 1;

            while( left < right ){

                int sum = elements[left] + elements[right] + elements[i];
                vector<int> set;

                if( sum == 0 ){

                    set = {elements[i], elements[left], elements[right]};

                    triplets.push_back(set);

                    while( left < right && elements[right] == elements[right-1]){
                        right--;
                    }

                    while( left < right && elements[left] == elements[left+1]){
                        left++;
                    }

                    left++;
                    right--;

                }else if( sum > -1*elements[i] ){
                    right--;
                }else{
                    left++;
                }

            }
           
       }

       return triplets;
    }

    void printSolution( vector<int>& elements){
        for( auto triplet : countUniqueTriplets(elements) ){
            cout<<"[";
            for( auto num : triplet){
                cout<<num<<" ";
            }
            cout<<"]\n";
        }
        cout<<"\n";
    }
};

void testCases(){
    vector<vector<int>> testCases {
        {-1,0,1,2,-1,-4}, //Expected: { [-1,-1,2], [-1,0,1]}
        {0,0,0}, // Expected: {[0,0,0]}
        {0,1,1}, //Expected: {}
        {-2,0,0,2,2}, // Expected: {[-2,0,2]}
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}