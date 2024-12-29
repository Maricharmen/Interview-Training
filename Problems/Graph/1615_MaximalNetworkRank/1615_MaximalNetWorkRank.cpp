/**
 * 1615. Maximal Network Rank
 * 
 * There is an infrastructure of n cities with some number of roads 
 * connecting the cities. Each roads[i] = [a_i, b_i] indicates that 
 * there is a bidirectional road between cities a_i and b_i.
 * 
 * The network rank of two different cities is defined as the total
 * number of dictly connected roads to either city. If a road is directly
 * connected to both cities, it is only counted once. 
 * 
 * The maximal network rank of the infrastructure is the maximum
 * network rank of all pairs of different cities.
 * 
 * Given the integer n and the arrays roads, return the maximal 
 * network rank of the entire infrastructure.
 */

/**
 * INPUT: integer n represent all cities and vector of pair that represent roads.
 * OUTPUT: maximal network rank
 * 
 * BREAKDOWM:
 * - graph undirected -> build adjacencyList 
 * - to take two diferent cities and count the number of roads that are directly connected
 * - and the get the maximum
 * - to take to cities that been neighbot
 * - bfs is better 
 * - Into bdf currentNode , currentDirectlyRoad, 
 * - When traversing the neighbor(nextNode) of the currentNode, currentDirectlyNode + nextNode
 * - In the future or every step, get the maximum networkRank  
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

/**
 * Version 
 * Approach: BFS -> Nested Loop
 * Assumpitions: 
 */
class Solution_V1 {
private:
    map<int, set<int>>graph;
public:
    void adjacencyList( int numCities, vector<pair<int, int>>& roads){
        for( auto city : roads){
            graph[city.first].insert(city.second);
            graph[city.second].insert(city.first);
        }
    }
    /**
     * Complexity Time: ( E + V^2 )
     * Complexity Space: O( V )
     */
    int maximalNetWorkRank( int numCities ){

        vector<int> visited(numCities, false);
        queue<int> Q;
        Q.push(0);

        int maximalNetwork = 0; 

        while( !Q.empty()){

            int currentNode = Q.front();
            int currentNetWorkRank = graph[currentNode].size();
            Q.pop();
            
            visited[currentNode] = true;

            for( int i= 0 ; i < numCities; i++ ){
                    
                    if( !visited[i] ){

                        int totalNetWorkRank;

                        int nextNetWorkRank = graph[i].size();

                        if( graph[currentNode].count(i) ) totalNetWorkRank = currentNetWorkRank + nextNetWorkRank - 1;
                        else totalNetWorkRank = currentNetWorkRank + nextNetWorkRank;

                        maximalNetwork = max( totalNetWorkRank , maximalNetwork);
                   
                        Q.push(i);

                    }
                    
            }

        }

        return maximalNetwork;

    }

    void printSolution(int numCities, vector<pair<int, int>>& roads ){
        adjacencyList(numCities, roads);
        cout<<maximalNetWorkRank(numCities)<<"\n";
        graph.clear();
    }
};

void testCases(){
    vector< pair< int, vector<pair<int, int>> >>testCases {
        { 4 , { {0,1}, {0,3}, {1,2}, {1,3}}}, // Expected 4
        { 5, { {0,1}, {0,3}, {1,2}, {1,3}, {2,3}, {2,4} }}, //Expected 5
        { 8, { {0,1}, {1,2}, {2,3}, {2,4}, {5,6}, {5,7} } } //Expected 5
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}

