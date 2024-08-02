/**
 * Round Trip
 * 
 * Byteland has n cities and m roads between them. Your task is to desing
 * a round trip that begins in a city, goes through two or more other cities,
 * and finally return to the starting city. Every intermediate city on the 
 * route has to be distinct.
 * 
 * Input
 * The first input line has two integers n and m: the number of cities and 
 * roads. The cities are numbered 1,2,\dots,n.
 * 
 * Then, there are m lines describing the roads. Each line has two integers 
 * a and b: there is a road between those cities.
 * 
 * Every road is between two different cities, and there is at most one road 
 * between any two cities.
 * 
 * Output
 * First print an integer k: the number of cities on the route. Then print k 
 * cities in the order they will be visited. You can print any valid solution.
 * If there are no solutions, print "IMPOSSIBLE".
 * 
 */

#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <map>
using namespace std;

/**
 * Version 1 
 * Approach: Disconected Undirected Graph - DFS
 * Assumpitions: 
 */
class Solution_V1 {
public:
 
    map<int, set<int>> graph;
 
    void buildAdjacencyList( vector<pair<int,int>>& roads){
        for( auto road : roads){
            graph[road.first].insert(road.second);
            graph[road.second].insert(road.first);
        }
    }
 
    vector<int> roundTrip( int cities ){
 
        vector<bool> visited(cities + 1 , false);
        vector<int> parent(cities + 1, -1);
        stack<int> path;
        vector<int> cycle;
        
        for( auto city : graph){
            if(!visited[city.first]){
                if(dfs(visited,parent,path,city.first)) break;
            }
        }
        
        if( path.empty()){
            cout<<"IMPOSSIBLE"<<"\n";
            return {};
        } 
        
        int start = path.top();

        while( !path.empty()){
            cycle.push_back(path.top());
            path.pop();
            if( cycle.size() > 1 && start == cycle.back()) break;
            else{
                
            }
        }
        
        return cycle;
    }

    /**
     * Complexity Time: O(V + E) -> Overhead por el uso extra de la pila
     * Complexity Space: O(V + E)
     */
 
    bool dfs( vector<bool>& visited, vector<int>& parent, stack<int>& path, int city){
 
        visited[city] = true;
        path.push(city);
 
        for( auto next : graph[city]){
 
            if( !visited[next] ){
                parent[next] = city;
                if(dfs(visited, parent, path, next)) return true;
            } else if( next != parent[city]){
                path.push(next);
                return true;
            }
        }

        path.pop();
        visited[city] = false;
 
        return false;
 
    }
 
    void printSolution( int cities, vector<pair<int,int>>& roads){
        buildAdjacencyList(roads);
 
        vector<int> cycle = roundTrip(cities);
 
        if(!cycle.empty())cout<<cycle.size()<<"\n";
 
        for(int city : cycle){
            cout<<city<<" ";
        }
        cout<<"\n";
 
        //printGraph();
 
        graph.clear();
    }
 
    void printGraph( ){
        for( auto node : graph){
            cout<<node.first<<" :";
            for( auto edge : node.second){
                cout<<edge<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
 
   
};

/**
 * Version 2
 * Approach: Disconected Undirected Graph - DFS
 * Assumpitions: 
 */
class Solution_V2 {
public:

    map<int, set<int>> graph;

    void buildAdjacencyList( vector<pair<int,int>>& roads){
        for( auto road : roads){
            graph[road.first].insert(road.second);
            graph[road.second].insert(road.first);
        }
    }

    vector<int> roundTrip( int cities ){

        vector<bool> visited(cities + 1 , false);
        vector<int> parent(cities + 1, -1);
        vector<int> cycle;
        int start = -1, end = -1;
 
        for( auto city : graph){
            if(!visited[city.first]){
                if(dfs(visited, parent, city.first, start, end)) break;
            }
        }
        
        if( start == -1){
            cout<<"IMPOSSIBLE"<<"\n";
            return {};
        }

        cycle.push_back(start);
        for( int city = end; city != start ; city = parent[city]){
            cycle.push_back(city);
        }
        cycle.push_back(start);
        
        return cycle;
    }

    /**
     * Complexity Time: O(V + E)
     * Complexity Space: O(V + E)
     */

    bool dfs( vector<bool>& visited, vector<int>& parent, int city, int& start, int& end){

        visited[city] = true;

        for( auto next : graph[city]){

            if( !visited[next] ){
                parent[next] = city;
                if(dfs(visited, parent, next, start, end)) return true;
            } else if(next != parent[city]){
                start = next;
                end = city;
                return true;
            }
        }

        return false;
    }

    void printSolution( int cities, vector<pair<int,int>>& roads){
        buildAdjacencyList(roads);

        vector<int> cycle = roundTrip(cities);

        if(!cycle.empty())cout<<cycle.size()<<"\n";

        for(int city : cycle){
            cout<<city<<" ";
        }
        cout<<"\n";

        //printGraph();

        graph.clear();
    }

    void printGraph( ){
        for( auto node : graph){
            cout<<node.first<<" :";
            for( auto edge : node.second){
                cout<<edge<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

   
};

void testCases(){
    vector<pair<int, vector<pair<int, int>>>> testCases{
        {5, {{1,3},{1,2},{5,3},{1,5},{2,4},{4,5}}},
        {5, {{1,3},{1,2},{1,5},{2,4},{4,5}}},
        {5, {{1,3},{1,2},{2,5},{2,4},{4,5}}}
    };

    Solution_V1 sol;
    
    for( auto test :testCases){
        sol.printSolution(test.first, test.second);
    }
}

void input(){

    int m, n;
    cin>>m>>n;

    vector<pair<int,int>> roads;

    while( n--){
        int a,b;
        cin>>a>>b;
        roads.push_back({a,b});
    }

    Solution_V2 sol;
    sol.printSolution(m,roads);
}

int main(){
    testCases();
    //input();
}