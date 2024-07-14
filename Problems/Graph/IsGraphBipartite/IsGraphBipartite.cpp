/**
 * 785. Is Graph Bipartite?
 * 
 * There is an undirected graph with n nodes, where each node is numbered between
 * 0 and n-1. You are given a 2D array graph, where graph[u] is an array of nodes that
 * node u is adjacent to. More formally, for each v in graph[u], there is an undirected
 * edge between node u and node v. The graph has the following properties.
 * 
 * - There are no self-edges (graph[u] does not contain u)
 * - There are no parallel edges (graph[u] does not contain duplicates values)
 * - If v is in graph[u], then u is a graph[v] (the graph is undirected)
 * - The graph may not be connected, meaning there may be two nodes u and v such that 
 * there is no path beteween them.
 * 
 * A graph is bipartite if the nodes can be partitioned into two independent sets A and B
 * such that every edge in the graph connects a node in set A and a node in set B.
 * 
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution_V1 {
private:
    map<int, vector<int>> graph;
public: 

    void adjacencySet( vector<vector<int>>& connections ){

        for( int i=0; i<connections.size(); i++){
            for( int j=0; j < connections[i].size() ; j++){
                graph[i].push_back(connections[i][j]);
            }

        }
    }

    bool isBipartite( vector<vector<int>>& connections ){

        int size =  connections.size();
        vector<int> visited (size, -1);

        for( int currentNode=0; currentNode<size; currentNode++){
            if( visited[currentNode] == -1){
                if( !dfs(visited, currentNode, 0) ) return false;
            }
        }

        return true;
    }

    bool dfs(vector<int>&visited, int currentNode, int value ){

        visited[currentNode] = value;

        for( auto neighbor : graph[currentNode]){
            if( visited[neighbor] == -1){
                if( !dfs(visited, neighbor, 1-value) ) return false;
            }else if( visited[neighbor] == visited[currentNode]){
                return false;
            }
        }

        return true;
    }

    void printSolution(vector<vector<int>>& connections){
        adjacencySet(connections);
        cout<<isBipartite(connections)<<"\n";
        graph.clear();
    }

    void printGraph( ){
        for( auto node : graph){
            cout<<node.first<<": ";
            for( auto edge : node.second){
                cout<<edge<<" ";
            }
            cout<<"\n";
        }
    }
};


void testCases(){
    vector<vector<vector<int>>> testCases {
        { {1,2,3}, {0,2}, {0,1,3}, {0,2}}, //Expected: 0
        { {1,3}, {0,2}, {1,3}, {0,2}}, //Expected: 1
    };

    Solution_V1 sol;

    for( auto test : testCases ){
        sol.printSolution(test);
    }

}

int main(){
    testCases();
}