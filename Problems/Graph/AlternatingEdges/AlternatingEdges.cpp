/**
 * You are given a connected undirected graph
 * 
 * Asign a direction to each edge so that there won't be any paths of length equal or greater than two
 */

/**
 * INPUT:
 * OUTPUT:
 * BREAKDOWN:
 */
/**
 * Input: vector of pair represent connection bidirectional
 * Output: vector of pair with new directed edges
 * 
 * BREAKDOWN:
 * - Arrows alternated
 * - When exits cycle, no is posible if the cicly is odd, return empty array
 * - Check if is bipartite graph
 * - I could colored every node (1-0) and  node(1) -> node(0)
 * 
 * 1:1->2:0<-3:1->4:0 <-5:1 
 *      ^               ^
 *      |               |
 *                 
 *      6:1    ->      7:0  
 *  
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Version 1:
 * Approach: DFS
 */

class Solution_V1{
public:

    map<int, vector<int>> graph;

    void adjacencyList(  vector<pair<int, int>>& edges){
        for( auto edge : edges ){
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
    }

    vector<pair<int, int>> alternatingEdges( int numNodes ){

        vector<int> visited( numNodes, -1);

        vector<pair<int,int>> directedEdges;

        for( int i=0; i<numNodes ; i++){
            if( visited[i] == -1 ){
                if( !isBipartite(visited, i, 1) ) {
                    cout<<"Bipartite \n";
                    return {};
                }
            }
        }

        for( auto node : graph){
            for( auto directed : node.second){
                if(visited[directed] == 0){
                    directedEdges.push_back({node.first, directed});
                }
            }
        }

        return directedEdges;
    }

    bool isBipartite( vector<int>& visited, int currentNode, int color){

        visited[currentNode] = color;

        for( auto neighbor : graph[currentNode]){
            if( visited[neighbor] == -1){
                if( !isBipartite(visited, neighbor, 1 - visited[currentNode])) return false;
            }else if( visited[neighbor] == visited[currentNode]){
                return false;
            }
        }

        return true;
    }

    void printSolution(int numNodes, vector<pair<int, int>>& edges ){
        adjacencyList(edges);
        for( auto directed : alternatingEdges(numNodes)){
            cout<<directed.first<<" "<<directed.second<<"\n";
        }
    }
};

void testCases(){
    vector<pair<int, vector<pair<int, int>>> > testCases {
        { 8, { {0,1}, {1,2}, {2,3}, {1,6}, {3,4}, {6,7}, {4,5}, {4,7} } }, // [{0,1}, {2,1}, {2,3}, {4,3}, {4,5}, {4,7}, {6,1}, {6,7}]
        { 8, { {0,1}, {1,2}, {2,3}, {1,6}, {3,4}, {6,7}, {4,5}, {3,7} }  } //Bipartite
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}