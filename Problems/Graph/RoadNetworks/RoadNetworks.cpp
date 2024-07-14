/*
RoadNetworks

In some states, it it not possible to drive between any two towns because
the are not connected to the same road network. Given a list of town and 
list of pairs representing roads between towns, return the number of road
networks. (For example, a state in which all towns are connected by roads
has 1 road network, and state in which none of the towns are connected by 
roads has 0 road networks).

*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

/**
 * Version 1: 
 * Approach: Undirected Graph - Recursive DFS
 * Assumpitions: 
 */

class Solution_V1{
private:
    map<string, vector<string>> graph;

public:
    
    /**
     * Complexity Time: O(E) 
     * Complexity Space: O( V + E)
     */
    void buildGraphAdjacencyList(vector<pair<string, string>>& roads){
        for( auto road : roads){
            string origin = road.first;
            string destination = road.second;
            graph[origin].push_back(destination);
            graph[destination].push_back(origin);
        }
    }

    /**
     * Complexity Time: O( V + E ) 
     * Complexity Space: O( V )
     */
    int countRoadNetworks(vector<string>& towns){

        map<string, bool> visited;

        int totalRoads = 0;

        for( auto town : graph){
            if( !visited[town.first] ){
                dfs(town.first, visited);
                totalRoads++;
            }
        }

        return totalRoads;
    }

    /**
     * Complexity Time: O( V + E ) 
     * Complexity Space: O( V ) Stack Space
     */
    void dfs(string currentTown,map<string, bool>& visited){
        visited[currentTown] = true;

        for( auto nextTown : graph[currentTown]){
            
            if(!visited[nextTown]) dfs(nextTown, visited);
        }

        return;
    }

    void printSolution(vector<pair<string, string>>& roads, vector<string>& towns ){
        buildGraphAdjacencyList(roads);
        cout<<countRoadNetworks(towns)<<"\n";
        graph.clear();
    }

    void printGraph(){
        for( auto node : graph){
            cout<<node.first<<": ";
            for(auto edge : node.second){
                cout<<edge<<" ";
            }

            cout<<"\n\n";
        }
    }

};

void testCases(){
    vector< pair< vector<pair<string, string>> , vector<string>  >>  testCases {
         { { {"Anchorage", "Homer"}, {"Glacier Bay", "Gustavus"}, {"Copper Center", "McCarthy"}, {"Anchorage", "Copper Center"}, {"Copper Center", "Fairbanks"}, {"Healy", "Fairbanks"}, {"Healy", "Anchorage"} },
           {"Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy", "Anchorage"} } ,
        
         { { {"Kona", "Volcano"}, {"Volcano", "Hilo"}, {"Lahaina", "Hana"}, {"Kahului", "Haiku"}, {"Hana", "Haiku"}, {"Kahului", "Lahaina"}, {"Princeville", "Lihue"}, {"Lihue", "Waimea"} } ,
           {"Kona", "Hilo", "Volcano", "Lahaina", "Hana", "Haiku", "Kahului", "Princeville", "Lihue", "Waimea"} }  
    };

    Solution_V1 SOL;

    for( auto test : testCases ){
        SOL.printSolution(test.first, test.second);
        
    }
}


int main(){
    testCases();
}