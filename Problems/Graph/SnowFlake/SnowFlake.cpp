/**
 * Snowflake
 * 
 * A snowflake graph is generated from two integers x and y, both greater than 1, as follows:
 * 
 *  1. Start with one central vertex.
 *  2. Connect x new vertices to this central vertex.
 *  3. Connect y new vertices to each of these x vertices. 
 * 
 * Given a snowflake graph, determine the values of x and y.
 */

/**
 * Input: list of edge bi-directional
 * Ouput: Integer x- y  
 * 
 * BREAKDOWN:
 * - One central vertex -> it have x edge
 * - x's vertex -> it have y-1 edge
 * - y -> it have 1 edge
 * - I can calcule the number of edge a each vertex
 * - Count the vextex with one edges, this represent -> y
 * - Caculate x= y-1
 * - Create a map of frequencies.
 * - To do the operation
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

/**
 * Version 1
 * Approach: Mathematic Logic
 */
class Solution_V1{
public:
    /**
     * Complexity Time: O(E) -> linear
     * Complexity Space: O(N) -> linear
     */
    pair<int, int> snowflake( vector<pair<int, int>>& edges){
        map<int, int> frecuenciesEdges;
        set<int> xNodes;

        for( auto edge : edges){
            frecuenciesEdges[edge.first]++;
            frecuenciesEdges[edge.second]++;
        }

        int y = 0;
        int x = 0;

        for( auto edge : edges){
            if( frecuenciesEdges[edge.first] == 1 ){
                xNodes.insert(edge.second);
                y++;
            }
            if( frecuenciesEdges[edge.second] == 1 ){
                xNodes.insert(edge.first);
                y++;
            }
        }

        x = xNodes.size();
        y = y/x;
        

        return {x,y};
    }

    void printSolution( vector<pair<int, int>>& edges){
        auto value = snowflake(edges);
        cout<<value.first<<" "<<value.second<<"\n";
    }

    
};

/**
 * Version 1: Idea Sergio
 * No works in the case the center and x's have the same numbers of edges
 */
class Solution_V2{
public:

    pair<int, int> snowflake( vector<pair<int, int>>& edges){
        map<int, int> freqEdges;

        for( auto edge : edges){
            freqEdges[edge.first]++;
            freqEdges[edge.second]++;
        }

        map<int, int> Degrees; // K: Number of edges to each nodes V: number of nodes

        for( auto node : freqEdges){
            Degrees[node.second]++;
        }
        
        int center; 

        for( auto nodes : Degrees){
            if( nodes.second == 1 ){
                center = nodes.first; //Num edges of the center = Num of X's
            }
        }

        int totalY = Degrees[1];
        int numX = center; 
        int numY = totalY/ numX;
        
        return {numX,numY};

    }

    void printSolution( vector<pair<int, int>>& edges){
        auto value = snowflake(edges);
        cout<<value.first<<" "<<value.second<<"\n";
    }
};

void testCases(){
    vector<vector<pair<int, int>>> testCases {
        { {1,2}, {2,3}, {3,4}, {4,5}}, //Expected: 2:1
        { {1,2}, {2,3}, {3,4}, {4,5}, {2,8}, {2,9}, {4,6}, {4,7}} // Expected 2:3
    };

    Solution_V2 sol;

    for( auto test :testCases ){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}