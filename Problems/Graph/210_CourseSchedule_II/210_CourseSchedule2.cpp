/**
 * 210. Course Schedule II
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
 * You are given an array prerequisites where prerequisites[i] = [a_i, b_i] indicates that you must take course b_i first if you want to take course a_i.
 * 
 * - For example, the pair [0,1], indicates that to take course 0 you have to first take course 1.
 * 
 * Return the ordering of courses you should take to finish all courses. If there are many
 * valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
 */

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;

/**
 * Version 1
 * Approach: Directed Graph - Topological Sort Recursive DFS
 * Assumpitions: 
 */

class Solution_V1{
private:
    map<int, vector<int>> graph;

public:
    void adjacencySet( vector<vector<int>>& prerequisites){
        for( auto course : prerequisites){
            graph[course[1]].push_back(course[0]);
        }
    }

    vector<int> findOrder(int numCourses){

        vector<bool> visited(numCourses, false);
        vector<bool> toVisit(numCourses, false);

        stack<int> S;

        for( int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(!dfs(visited, toVisit, i, S)) return {};
            }
        }

        vector<int> order;

        while( !S.empty()){
            order.push_back(S.top());
            S.pop();
        }

        return order;
        
    }

    bool dfs(vector<bool>& visited, vector<bool>& toVisit, int course, stack<int>& S){

        visited[course] = true;
        toVisit[course] = true;

        for( auto nextCourse : graph[course]){
            if(!visited[nextCourse]){
                if(!dfs(visited, toVisit, nextCourse, S)) return false;
            }else if( toVisit[nextCourse]) return false;
        }

        toVisit[course] = false;

        S.push(course);

        return true;
    }

    void printSolution(int numCourses, vector<vector<int>>& prerequisites){
        adjacencySet(prerequisites);
        for( auto course : findOrder(numCourses)){
            cout<<course<<" ";
        }
        cout<<"\n";
        graph.clear();
    }

};

/**
 * Version 2
 * Approach: Directed Graph - Topological Sort BFS
 * Assumpitions: 
 */

class Solution_V2{
private:
    map<int, vector<int>> graph;
public:
    void adjacencySet( vector<vector<int>>& prerequisites){
        for( auto course : prerequisites){
            graph[course[1]].push_back(course[0]);
        }
    }

    vector<int> findOrder( int numCourses ){
        
        vector<int> inDegrees(numCourses, 0);

        for( auto node : graph){
            for( auto edge : node.second){
                inDegrees[edge]++;
            }
        }

        queue<int> Q;

        for( int i=0;i<numCourses; i++){
            if( inDegrees[i] == 0) Q.push(i);
        }

        vector<int> order;

        while( !Q.empty()){

            int currentNode = Q.front();
            Q.pop();

            order.push_back(currentNode);

            for( auto nextCourse : graph[currentNode]){
                inDegrees[nextCourse]--;
                if( inDegrees[nextCourse] == 0) Q.push(nextCourse);
            }

        }

        if( order.size() != numCourses) return {};

        return order;
    }

    void printSolution( int numCourses, vector<vector<int>>& prerequisites){
        adjacencySet(prerequisites);
        for( auto course : findOrder(numCourses)){
            cout<<course<<" ";
        }
        cout<<"\n";
        graph.clear();
    }

};

void testCases(){

    vector<pair<int, vector<vector<int>>>> testCases {
        { 2, { {1,0}}}, // Expected [0,1]
        { 4, { {1,0}, {2,0}, {3,1}, {3,2}}} // Expected [0,1,2,3]
    };

    Solution_V2 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }

}

int main(){
    testCases();
}