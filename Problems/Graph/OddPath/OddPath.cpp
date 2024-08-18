/**
 * Odd Path
 * 
 * Given a graph, determine if there exists a path that starts from a vertex 
 * and ends in itself, such that the length of the path isn't even.
 * 
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution_V1{
public:
  
  	map<int, vector<int>> graph;
  
  	void buildListAdjacency( vector<pair<int, int>>& edges ){
      for( auto node : edges ){
        graph[node.first].push_back(node.second);
      }
    }
  
  	bool oddPath( int n){
      
      vector<int> visited( n + 1 , -1);
      
      for( int i= 1; i<= n; i++){
        if( visited[i] == -1){
          if( dfs(visited, 1, i) ) return true; 
        }
      }
      
      return false;
    }
  
  bool dfs( vector<int>& visited, int alternative, int currentNode){
    	
    	visited[currentNode] = alternative;

    	for( auto next : graph[currentNode]){
            
        if( visited[next] == -1){
          if( dfs(visited, 1 - visited[currentNode], next) ) return true;
        }else if( visited[next] == visited[currentNode]) return true;
    
      }
    
    return false;
    
  }
  
  void printSolution( vector<pair<int, int>>& edges, int n){
    buildListAdjacency(edges);
    if( oddPath(n)) cout<<"True"<<"\n";
    else cout<<"False"<<"\n";
    graph.clear();
  }

};

void testCases(){
    vector<pair<vector<pair<int, int>>, int>> testCases {
       { { {1,2}, {2,3}, {3,4}, {4,1}, {1,5}, {5,6}, {6,7}, {7,8}, {8,9}, {9,1} }, 9}, //Expected: False
       { { {1,2}, {2,3}, {3,1}}, 3}, //Expected: True
       { { {1,2}, {2,3}, {3,4}, {4,1}}, 4}, // Expected: False

    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}