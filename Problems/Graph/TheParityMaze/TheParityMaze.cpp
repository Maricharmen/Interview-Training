/**
 * The Parity Maze
 * 
 * In the mystical land of Graphoria, a network of enchanted nodes and paths forms 
 * a sprawling maze. Each path has a magical property, but not all loops in this 
 * maze are harmonious. Your quest is to find the most perfectly balanced loop, a 
 * loop with an even number of paths.
 * In this enchanted maze, there are several cycles, but only one cycle will align 
 * perfectly with the magical balance of parity. Your goal is to identify whether 
 * such a cycle exists and reveal its hidden enchantment.
 * 
 * Input:
 * An integer n representing the number of enchanted nodes.
 * A list of paths where each path[i] = [u, v] represents a magical connection 
 * between nodes u and v.
 * 
 * Output:
 * Return true if you find a perfectly balanced loop with an even number of 
 * paths, otherwise return false.
 * 
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution_V1{
public:

    map<int, vector<int>> graph;

    void buildListAdjacency( vector<pair<int, int>>& connection){
        for( auto node : connection){
            graph[node.first].push_back(node.second);
            graph[node.second].push_back(node.first);
        }
    }

    bool evenPath(int n){

        vector<bool> visited(n, false);
        vector<pair<int, int>> parent(n, {-1,0});

        for( int i=0; i<n; i++){
            if( !visited[i] ){
                if( dfs(visited, parent, i) )return true;
            }
        }

        return false;
    }

    bool dfs(vector<bool>& visited, vector<pair<int, int>>&parent, int current ){

        visited[current] = true;

        for( auto next : graph[current]){
           
            if( !visited[next] ){

                int distance = parent[current].second;
                parent[next] = {current, distance + 1};
                if(dfs(visited, parent, next)) return true;

            }else if( parent[current].first != next ){
                
                int length = parent[current].second - parent[next].second  + 1;
                if( length%2 == 0)return true;

            }

        }

        return false;
    }

    void printSolution( vector<pair<int, int>>& connection, int n){
        buildListAdjacency(connection);

        if( evenPath(n) )cout<<"True";
        else cout<<"False";
        cout<<"\n";

        graph.clear();
    }
};

void testCases(){
    vector<pair< vector<pair<int, int>>, int>> testCases {
        { { {6,1}, {1,2}, {2,3}, {3,1}, {3,0}, {0,8}, {8,7}, {7,3}, {5,2}, {2,4}} , 9 }, // Expected: True
        { { {0,1}, {1,2}, {2,3}, {3,0}, {1,3}}, 4}, // Expected: True
        { { {0,1}, {1,2}, {2,3}, {1,3} }, 4}, // Expected: False
        { { {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}, {1, 3}, {2, 4}}, 5}, // Expected: True
    };

    Solution_V1 sol;

    for( auto test : testCases ){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}