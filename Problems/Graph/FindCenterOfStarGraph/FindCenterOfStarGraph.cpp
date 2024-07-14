/**
 * There is an undirected star graph consisting of n nodes labeled 
from 1 to n. A star is a graph where there is one center node and
exactly n-1 edges that connect the center node with every other
node.
You are given a 2D integer array edges where each edges[i] = [u_i, v_i] indicates that there is an edge between the nodes
u_i and v_i. Return the center of the given star graph.
 */

/**
 * INPUT: array of pair/tuple of integers 
 * OUTPUT: Value integeer of the center node
 * BREAKDOWN:
 * - Center node is the node with more edges
 * - Not is necesary buil a graph as adjaency list, i can to do 
 *  a map with the key represent a node and the value represent 
 *  total edges
 * - At the moment when tranversion all connection if the frequency
 *  is greter than 1, save this value of node.
 * - Because I know all nodes have one edge and only the center node 
 *  have more edges.
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Version 1
 * Approach: The node with more edge is the center node.
 * Assumpitions: 
 */
class Solution_V1{
public:

    /**
     * Complexity Time: O(E) -> Linear
     * Complexity Space: O(V) -> Linear
     */
    int centerNode( vector<pair<int, int>>& edges){
        map<int, int> frequencies;  
        int valueCenterNode;

        for( auto edge : edges){
            frequencies[edge.first]++;
            frequencies[edge.second]++;
            if( frequencies[edge.second] > 1) valueCenterNode = edge.second;
            if( frequencies[edge.first] > 1) valueCenterNode = edge.first;
        }

        return valueCenterNode;
    }

    void printSolution( vector<pair<int,int>>& edges){
        cout<<centerNode(edges)<<"\n";
    }
};

/**
 * Version 2
 * Approach: If has been visited more of one, is the center node
 * Assumpitions: 
 */

class Solution_V2{
public:

    /**
     * Complexity Time: O(E)
     * Complexity Space: O(V)
     */
    int centerNode( vector<pair<int,int>>& edges){
        map<int, bool> visited;

        for( auto edge : edges){
            if( visited[edge.first]) return edge.first;
            if( visited[edge.second]) return edge.second;
            visited[edge.first] = true;
            visited[edge.second] = true;
            
        }

        return -1;
    }

    void printSolution( vector<pair<int,int>>& edges){
        cout<<centerNode(edges)<<"\n";
    }
};

/**
 * Version 3
 * Approach: Seek repeated number
 * Assumpitions: All edges are conected with the center node
 */
class Solution_V3{
public:
    /**
     * Complexity Time: O(1)
     * Complexity Space: O(1)
     */
    int centerNode( vector<vector<int>>& edges){
        if( edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])return edges[0][0];
        return edges[0][1];
    }
};

void testCases(){

    vector<vector<pair<int,int>>> testCases {
        {{1,2},{2,3},{4,2}} // Expected 2
    };

    Solution_V2 sol;

    for( auto test : testCases ){
        sol.printSolution(test);
    }
};

int main(){
    testCases();
}