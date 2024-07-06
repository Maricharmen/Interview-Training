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

class SolutionVersion_1{
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
       map<string, int> distances;

       Q.push({origin, "blue"});
       Q.push({origin, "red"});

       int level = 0;

       while( !Q.empty()){

            for( int size = Q.size(); size > 0 ; size--){

                string currentNode = Q.front().first;
                string currentColor = Q.front().second;
                Q.pop();

                if( distances[currentNode] == 0){
                    distances[currentNode] = level;
                }

                visited[currentNode][currentColor] = true;

                if( currentColor == "red") currentColor = "blue";
                else currentColor = "red";

                for( auto opossiteColor : graph[currentColor][currentNode]){
                    if( !visited[opossiteColor][currentColor]) Q.push({opossiteColor, currentColor});
                }

            }

            level++;
       }

       if( distances[destination] == 0) return -1;
       return distances[destination];
        
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

class SolutionVersion_2{

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
          { {"E" ,  "C"} , "red"  } 
    };

    vector<pair<pair<string, string>, string>>connections_2 {
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
        {"A", "F"}  // C1: -1  C2: 3
    };

    SolutionVersion_1 sol;

    for( auto test : testCases){
        sol.printSolution(connections_1, test.first, test.second);
    }
}

int main(){
    testCases();
}