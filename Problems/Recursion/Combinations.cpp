
/*

Site: LeetCode 
Topic: Recursion

77. Combinations

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.

Approach:  


Required Time: 
Complexity Time: 
Complexity Space: 

Assumpitions: 

*/

#include <iostream>
#include <vector>
using namespace std;

void combine(vector<vector<int>>& output, vector<int>&subset, int range, int sizeSubSet, int element ){

    if( subset.size( ) == sizeSubSet ){
        output.push_back( subset ); 
        return; 
    }

    for( int j=element ; j <= range ; j++){
        subset.push_back(j);
        combine(output, subset, range, sizeSubSet, j+1 );
        subset.pop_back(); 

    }

}

vector<vector<int>> combination( int range, int sizeSubSet){
    vector<vector<int>> output;
    vector<int> subset;
    combine(output, subset, range, sizeSubSet, 1 );
    return output; 
}

int main(){

    //Test Cases 

    vector<pair<int, int>> testCases {
        {4, 2},
        {4, 3},
        {1,1}
    };

    for( auto test :  testCases ){

        cout<<"Case: "; 
        
        for( auto subset : combination(test.first, test.second ) ){
            cout<<"[ "; 
            for( auto element : subset ){
                cout<<element<<" ";
            }
            cout<<"]"; 
            
        }

        cout<<"\n"; 
    }


}


