/*
You are given a connected undirected graph

Asign a direction to each edge so that there won't be any paths of length equal or greater than two

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool bipartite(int node, unordered_map<int, unordered_set<int>>& adjList, unordered_map<int,int>& color, unordered_map<int,bool>& visited){
  
  visited[node] = true;
  
  for(auto neighbor: adjList[node]){
    if(visited[neighbor]){
      if(color[neighbor] == color[node])return false;
    }else{
      color[neighbor] = !color[node];
      bipartite(neighbor, graph, color,visited);
    }
  }
  
  return true;
}

vector<pair<int,int>> asingDirections(vector<pair<int,int>> graph){
  unordered_map<int, unordered_set<int>> adjList;
  
  vector<pair<int,int>> directedEdges;

  for(auto edge: graph){
    adjList[edge.first].insert(edge.second);
    adjList[edge.second].insert(edge.first); 
  }
  
  unordered_map<int,int> color;
  unordered_map<int,bool> visited;
  
  //Check if graph is bipartite or not
	if(bipartite(1, graph, color,visited)){
    //Asing the directions
    //Node with color 0 -> node with color 1
    for(auto list: adjList){
      int currNode = list.first;
      if(color[currNode] == 0){
        for(auto neighbor: list.second){
        	directedEdges.push_back({currNode, neighbor});
      	}
      }
      
    }
  }
  
  return directedEdges;
}