/**
 * Maximal Network Rank
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
using namespace std;

/**
 * TLE!!
 * Version 
 * Approach: BFS -> Nested Loop
 * Assumpitions: 
 */
class Solution_V1 {
private:
    map<int, vector<int>>graph;
public:
    void adjacencyList( int numCities, vector<pair<int, int>>& roads){
        for( auto city : roads){
            graph[city.first].push_back(city.second);
            graph[city.second].push_back(city.first);
        }
    }
    /**
     * Complexity Time: ( E + V^2*E )
     * Complexity Space: O( V + E )
     */
    int maximalNetWorkRank( int numCities ){

        queue<int> Q;
        Q.push(0);

        int maximalNetwork = 0; 

        while( !Q.empty()){

            int currentNode = Q.front();
            int currentNetWorkRank = graph[currentNode].size();
            Q.pop();

            for( int i= currentNode + 1 ; i < numCities; i++ ){
                    
                    int totalNetWorkRank;

                    int nextNetWorkRank = graph[i].size();

                    if( isNeighbor(currentNode, i) ) totalNetWorkRank = currentNetWorkRank+nextNetWorkRank-1;
                    else totalNetWorkRank = currentNetWorkRank+nextNetWorkRank;

                    maximalNetwork = max( totalNetWorkRank , maximalNetwork);
                   
                    Q.push(i);
            }

        }

        return maximalNetwork;

    }

    /**
     * Complexity Time: O(E)
     * Complexity Space: O(1)
     */
    bool isNeighbor( int currentNode , int nextNode ){
        for( auto node : graph[currentNode]){
            if( node == nextNode) return true;
        }

        return false;
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

