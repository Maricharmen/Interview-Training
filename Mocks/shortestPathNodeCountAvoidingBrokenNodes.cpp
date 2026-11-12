/*

graph = [[1,2],[3],[4],[4],[]]
broken = [1]
start = 0
destination = 4
return = 3

graph = [[1],[],[3],[]]
broken = []
start = 0
destination = 3
return = -1

Similar: https://www.fastprep.io/problems/google-shortest-path-node-count-avoiding-broken-nodes

Input: edge list, broken nodes, start, destination 
Output: Integer shortest path between a start and end with no broken nodes

- Build adcency list
- BFS from start to destination, every level is 1-length
- I will moving from start to destination
  - Before moving to a node, I will check if current node is broken
  - It is, I wont add their child
  - It is, I will add ther child to continue that path

N: number of nodes E: number of edges 

Times Complexity: (N + E) 
Space Complexity: (N) 

*/

#include <iostream>
#include <vector>
#include <map>
#include  <queue>
using namespace std;

class Solution {
private:
  map<int, vector<int>> adjList;
public:
  
  int minimumPathNodeCount(vector<vector<int>> graph, vector<int> broken, int start, int destination) {

    int N = graph.size();
    vector<int> brokenNodes(N, 0);
    for(int node : broken) brokenNodes[node] = 1;

    if(brokenNodes[start] || brokenNodes[destination]){
      return -1;
    }

    queue<pair<int, int>> q;
    vector<int> visited(N, 0);
    
    q.push({start, 1});
    visited[start] = 1;    

    while( !q.empty()){
      
        int currentNode = q.front().first;
        int currentLength = q.front().second;
        q.pop();

        if( currentNode == destination && !brokenNodes[destination]){
              return currentLength ;
        }
        
        for( int nextNode : graph[currentNode]){
            
            if( !visited[nextNode] && !brokenNodes[nextNode]){
              q.push( {nextNode, currentLength + 1});
              visited[nextNode] = 1;
            }
        }

     
    }

    return -1;
    
  }


};

int main(){

  vector<vector<int>> graph = {{1,2}, {3}, {4}, {4}, {}};
  vector<int> broken = {1};
  int start = 0, destination = 4;
  Solution sol;
  cout << sol.minimumPathNodeCount(graph, broken, start, destination); // 3

  graph = {{1}, {}, {3}, {}};
  broken = {};
  start = 0, destination = 3;
  cout << sol.minimumPathNodeCount(graph, broken, start, destination); // -1


}