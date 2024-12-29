/**
 * 1129. Shortest Path with Alternating Colors
 * 
 * You are given an integer n, the number of nodes in a directed graph
 * where the nodes are labeled from o to n-1. Each edge is read o blue 
 * in this graph, and there could be self-edges and parallel edges.
 * 
 * You are given two arrays redEdges and blueEdges where:
 * redEdges[i] = {a_i, b_i} indicates that there is a directed red edge
 * from node a_i to node b_i in the graph, and
 * 
 * blueEdges[j] = [u_j, v_j] indicates that there is a directed blue edge
 * from node u_j to node v_j in the graph.
 * 
 * Return an array answer of lenght n, where each answer[x] is the length 
 * of the shortest path grom node 0 to node x such that the edge colors 
 * alternate aling the path, or -1 if such a path does not exist.
 * 
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/**
 * Version
 * Approach: BFS
 */
class Solution{
private:
    map<string, map<int, vector<int>>> graph;
public:
    void adjacencyList(vector<pair<int, int>>& blueEdges,vector<pair<int, int>>& redEdges  ){

        for( auto node : blueEdges){
            graph["blue"][node.first].push_back(node.second);
        }

        for( auto node : redEdges){
            graph["red"][node.first].push_back(node.second);
        }
    }

    vector<int> shortestPathAlternatingColor( int n ){
        
        map<int, map<string, bool>> visited;
        vector<int> distance(n, -1);
        queue<pair<int, string>> Q;

        Q.push({0,"red"});
        Q.push({0,"blue"});

        int level = 0;
        
        while( !Q.empty()){
            
            int size = Q.size();

            for( int i = size ; i > 0 ; i-- ){

                int currentNode = Q.front().first;
                string currentColor = Q.front().second;
                Q.pop();

                if( !visited[currentNode][currentColor]  && distance[currentNode] == -1 ){
                    distance[currentNode] = level;
                    
                }

                visited[currentNode][currentColor]  = true;

                if( currentColor == "red") currentColor = "blue";
                else currentColor = "red";

                for( auto neighbor : graph[currentColor][currentNode]){
                    if(!visited[neighbor][currentColor] ) Q.push({neighbor, currentColor});
                }

            }

            level++;
            

        }

        return distance;
    }

    void printSolution(int n, vector<pair<int, int>>& blueEdges,vector<pair<int, int>>& redEdges  ){
        adjacencyList(blueEdges, redEdges);
        vector<int> result =  shortestPathAlternatingColor(n);
        for( int i=0; i < result.size(); i++ ){
            cout<<i<<" : "<<result[i]<<"\n";
        }
        cout<<"\n";
     
        graph.clear();
    }

    void printGraph(){
        cout<<"RED: ";
        for( auto node : graph["red"]){
            cout<<node.first<<": ";
            for( auto edge : node.second){
                cout<<edge<<" ";
            }
        }

        cout<<"BLUE: ";
        for( auto node : graph["blue"]){
            cout<<node.first<<": ";
            for( auto edge : node.second){
                cout<<edge<<" ";
            }
        }
    }

};

void testCases(){

    vector<pair<int, pair<vector<pair<int, int>>, vector<pair<int, int>> >>> testCases{
        { 3, { { {0,1}, {1,2} } , {}     }}, // Expected [0, 1, -1]
        { 3, { { {0,1}        }, {{2,1}} }} // Expected [0, 1, -1]
    };

    Solution sol;

    for( auto test : testCases){
        sol.printSolution( test.first, test.second.second, test.second.first);
    }
}

int main(){
    testCases();
}

