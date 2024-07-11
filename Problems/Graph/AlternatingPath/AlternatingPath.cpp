/** 
 * AlternatingPath
 * 
 * Given an origin and a destination in a directed graph in which edges can be
 * blue or red, determine the length of the shortest path from the origin to the
 * destination in which the edges traversed alternate in color. Return -1 if no 
 * such path exists.
 *
 */

#include <iostream>
#include <map>
#include <vector>
#include <queue> 
using namespace std;

/**
* Version 1:
* Approach: Directed Graph - Iterative BFS
* Assumpitions:
*/

class Solution_V1{
private:
    map<string, map<string, vector<string> > > graph;
public:
    
    /**
     * Complexity Time: 
     * Complexity Space: 
     */
    void adjacentSet( vector<pair<pair<string, string>, string>>& routes){
        for( auto route : routes){
            string origin = route.first.first;
            string destination = route.first.second;
            string color = route.second;
            graph[color][origin].push_back(destination);
        }
    }

    /**
     * Complexity Time: 
     * Complexity Space: 
     */
    int shortestAlternatingPath( string origin, string destination){
       
       queue<pair<string,string>> Q;
       map<string, map<string, bool>> visited;
       int shortestPath = -1;

       Q.push({origin, "blue"});
       Q.push({origin, "red"});

       int level = 0;

       while( !Q.empty()){

            for( int size = Q.size(); size > 0 ; size--){

                string currentNode = Q.front().first;
                string currentColor = Q.front().second;
                Q.pop();

                if( currentNode == destination && shortestPath == -1) shortestPath = level;

                visited[currentNode][currentColor] = true;

                if( currentColor == "red") currentColor = "blue";
                else currentColor = "red";

                for( auto opossiteColor : graph[currentColor][currentNode]){
                    if( !visited[opossiteColor][currentColor]) Q.push({opossiteColor, currentColor});
                }

            }

            level++;
       }

       return shortestPath;
        
    }

    void printSolution(vector<pair<pair<string, string>, string>>& routes, string origin, string destination){
        adjacentSet(routes);
        cout<<shortestAlternatingPath(origin, destination)<<"\n";
    }  

};

/**
 * Version 2:
 * Approach: Iterative BFS
 * Assumpitions:
 */

class Solution_V2{
private:
    map<string, vector<pair<string, string>> > graph;
public:

    /**
     * Complexity Time: 
     * Complexity Space: 
     */
    void adjancencySet( vector<pair<pair<string,string>, string>>& connections){
        for( auto node : connections){
            string origin = node.first.first;
            string destination = node.first.second;
            string color = node.second;
            graph[origin].push_back({destination, color});
        }
    }

    /**
     * Complexity Time: 
     * Complexity Space: 
     */
    int shortestAlternatingPath( string origin, string destination){

        queue<pair<string, pair<string, int>>> Q; 
        map<string, map<string,bool>> visited; 

        int shortestPath = -1;
      
        Q.push({origin, {"",0}});

        visited[origin]["blue"] = true;
        visited[origin]["red"] = true;

        while( !Q.empty()){

            string currentNode = Q.front().first;
            string currentColor = Q.front().second.first;
            int currentDistance = Q.front().second.second;
            Q.pop();
            
            if( currentNode == destination && shortestPath == -1) shortestPath = currentDistance;

            for( auto next : graph[currentNode]){
                
                string nextNode = next.first;
                string nextColor = next.second;

                if( nextColor != currentColor && !visited[nextNode][nextColor]){
                    Q.push({nextNode, {nextColor, currentDistance + 1}});
                    visited[nextNode][nextColor] = true;
                }

            }
        }

        return shortestPath;

    }

    void printSolution( vector<pair<pair<string,string>, string>> & connections, string origin, string destination ){
        adjancencySet(connections);
        cout<<shortestAlternatingPath(origin, destination)<<"\n";
    }

};

void testCases(){
    vector<pair<pair<string, string>, string>> connections_1 {
          { {"A" ,  "B"} , "blue" }, 
          { {"A" ,  "C"} , "red"  },
          { {"B" ,  "D"} , "blue" },
          { {"B" ,  "E"} , "blue" },
          { {"C" ,  "B"} , "red"  },
          { {"D" ,  "C"} , "blue" },
          { {"A" ,  "D"} , "red"  },
          { {"D" ,  "E"} , "red"  },
          { {"E" ,  "C"} , "red"  },
          { {"B" ,  "A"} , "red" }, 
    };

    vector<pair<pair<string, string>, string>> connections_2 {
          { {"A" ,  "B"} , "blue" }, 
          { {"A" ,  "C"} , "red"  },
          { {"B" ,  "E"} , "red" },
          { {"C" ,  "E"} , "blue" },
          { {"C" ,  "D"} , "blue"  },
          { {"E" ,  "G"} , "blue" },
          { {"E" ,  "F"} , "red"  },
          { {"G" ,  "F"} , "red"  },
       
    };

    vector<pair<string, string>> testCases {
        {"A", "E"}, // C1: 4   C2: 2
        {"E", "D"}, // C1: -1  C2: -1
        {"A", "F"},  // C1: -1  C2: 3
        {"A", "A"} // C1: 0    C2: 0
    };

    Solution_V2 sol;

    for( auto test : testCases){
        sol.printSolution(connections_2, test.first, test.second);
    }
}

int main(){
    testCases();
}