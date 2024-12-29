/**
 * 207. Course Schedule 
 * 
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
 * You are given an array prerequisites where prerequisites[i] = [a_i, b_i] indicates that you must take course b_i first if you want to take course a_i.
 * 
 * - For example, the pair [0,1], indicates that to take course 0 you have to first take course 1.
 * 
 * Return true if you can finish all courses. Otherwise, return false.
 */


#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Version 1
 * Approach: Directed Graph - Topological Sort Recursive DFS
 * Assumpitions: 
 */

class Solution_V1{
private:
    map<int, vector<int> > graph;

public:
    void adjacencySet( vector<pair<int, int>>& prerequisites ){
        for( auto prereq : prerequisites){
            graph[prereq.second].push_back(prereq.first);
        }
    }

    /**
     * Complexity Time: O( V + E )
     * Complexity Space: O( V )
     */

    bool canFinish(int numCourses){

        vector<bool> visited(numCourses, false);
        vector<bool> toVisit(numCourses, false);

        for( int i=0; i<numCourses ; i++){
            if( !visited[i] ){
                if( !dfsCheckCycle(visited, toVisit, i)) return false;
            }
        }

        return true;
    }

    bool dfsCheckCycle( vector<bool>& visited, vector<bool>&toVisit, int currentNode){
        
        visited[currentNode] = true;
        toVisit[currentNode] = true;

        for( auto nextNode : graph[currentNode] ){
            if( !visited[nextNode]){
                if( !dfsCheckCycle(visited, toVisit, nextNode) ) return false;
            }else if( toVisit[nextNode] ) return false;
        }

        toVisit[currentNode] = false;

        return true;
    }

    void printSolution( int numCourses, vector<pair<int,int>>& prerequisites){
        adjacencySet(prerequisites);
        cout<<canFinish(numCourses)<<"\n";
        graph.clear();
    }
};

void testCases(){
    vector<pair<int, vector<pair<int, int>>>> testCases {
        { 2, { {1,0} }}, // Expected 1
        { 2, { {1,0}, {0,1}}}, // Expected 0
        { 1, {}} // Expected 1
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }

}

int main( ){
    testCases();
}
