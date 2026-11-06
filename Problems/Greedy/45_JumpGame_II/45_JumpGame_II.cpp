/**
 * 45. Jump Game II
 * 
 * You are given a 0-indexed array of integers nums of lenght n. You are initially 
 * positioned at num[0].
 * 
 * Each element num[i] represents the maximum lenght of a forward jump from index i. 
 * In other words, if you are at nums[i], you can jump to any nums[i+j]
 * where:
 * 
 * 0 <= j <= nums[i] and
 * i+ j < n 
 * 
 * Return the minimum number of jumps to reach num[n-1]. The test cases are generated 
 * such that you reach num[n-1].
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/**
 * Version 1
 * Approach: BFS
 */
class Solution_V1 {
public:
    map<int, vector<int>> graph;

    /**
     * Complexity Time: O(n^2) 
     * Complexity Space: O(n)
     */

    void adjacencyList(vector<int>& maximumJumps ){

        for( int i=0; i<maximumJumps.size()-1; i++){

            for( int j=1 ; j <= maximumJumps[i] &&  i + j < maximumJumps.size() ; j++){

                graph[i].push_back(i+j);
                
            }
        }
    }

    int minimumJumps( vector<int>& maximumJumps ){
        int goal = maximumJumps.size() - 1;

        queue<pair<int, int>> Q;
        vector<bool> visited (maximumJumps.size(), false);

        Q.push( {0, 0});
        visited[0] = true;

        while( !Q.empty()){

            int currentNode = Q.front().first;
            int currentDistance = Q.front().second;

            Q.pop();

            for( auto neighbor : graph[currentNode]){
                
                if(!visited[neighbor]){
                    if( neighbor == goal ) return currentDistance + 1;
                    Q.push({neighbor, currentDistance + 1 });
                    visited[neighbor] = true;
                }
                
            }
        }

        return 0;

    }

    void printSolution(vector<int>& maximumJumps ){
        adjacencyList(maximumJumps);
        cout<<minimumJumps(maximumJumps)<<"\n";
        graph.clear();
    }

    void printGraph(){
        for( auto node : graph){
            cout<<node.first<<" :";
            for( auto edge : node.second){
                cout<<edge<<" ";
            }
            cout<<"\n";
        }
    }
};

/**
 * Version 2: 
 * Approach: DP
 */

class Solution_V2{
public: 

    /**
     * Complexity Time: O(n^2)
     * Complexity Space: O(n)
     */
    int minimumJumps( vector<int> & maximumJumps ){
        int size = maximumJumps.size();
        int goal = size - 1;
        vector<int> shortestPath (size, size);

        shortestPath[0] = 0;

        for( int i=0 ; i < size ; i++){
            for( int j=1; j<= maximumJumps[i] && i+j < size; j++){

                shortestPath[i+j] = min( shortestPath[i+j], shortestPath[i] + 1);

                if( i + j == goal) return shortestPath[i+j];

            }
        }

        return 0;
    }

    void printSolution(vector<int>& maximumJumps ){
        cout<<minimumJumps(maximumJumps)<<"\n";
    }
};

/**
 * Version 3
 * Approach: Greedy
 */

class Solution_V3 {
public:
    
    /**
     * Complexity Time: O(n)
     * Complexity Space: O(1)
     */
    int minimumJumps(vector<int> & maximumJumps ){

        int size = maximumJumps.size();
        int jump = 0;
        int current = 0;
        int maximumReach = 0;
        int indexMaximumReach = 0;

        for( int i= 0; i <size ; i++){

            if( i > current + maximumJumps[current]){
                current = indexMaximumReach;
                jump++;
            }

            int reach = i + maximumJumps[i];
            if( reach > maximumReach){
                maximumReach = reach;
                indexMaximumReach = i;
            }

            if( current + maximumJumps[current] >= size - 1){
                return jump + 1;
            }

        }

        return 0;
    }

    void printSolution(vector<int>& maximumJumps ){
        cout<<minimumJumps(maximumJumps)<<"\n";
    }
};

void testCases(){
    vector<vector<int>> testCases {
        {2,1,1,1,4}, //Expected 3
        {2,3,1,1,4}, //Expected 2
        {2,3,0,1,4}, //Expected 2
        {5,4,1,2,3,1,2,1}, //Expected 2
        {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5}
        //Expected 13
    };

    Solution_V3 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}