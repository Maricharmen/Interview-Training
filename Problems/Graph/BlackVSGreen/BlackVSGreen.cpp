/**
 * BlackVSGreen
 * 
 * Considera un grafo no dirigido representado por N nodos, donde cada nodo representa a una persona y 
 * cada arista (o edge) entre dos nodos representa la rivalidad entre esas dos personas. Tu tarea es 
 * determinar si es posible separar a las personas en dos bandos de manera que no haya rivalidades 
 * dentro de un mismo bando.
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution{
private:
    map<string, vector<string>> graph;
public:

    /**
     * Complexity Time: O( E )
     * Complexity Space: O( V + E )
     */

    void adjacencySet( vector<pair<string, string>> & rivalidad){
        for( auto node : rivalidad){
            graph[node.first].push_back(node.second);
            graph[node.second].push_back(node.first);
        }
    }

    /**
     * Complexity Time: O( V )
     * Complexity Space: O( V )
     */

    bool checkTeam( vector<string>& personajes , map<string, vector<string>>& graph){

        map<string, int> valueTeam;

        for( auto node : personajes) valueTeam[node] = -1;

        for( auto node : personajes){
            if( valueTeam[node] == -1){
                if( !bfs(valueTeam, node, graph) ) return false;
            }
        }

        return true;
    }

    /**
     * Complexity Time: O( V + E)
     * Complexity Space: O( V )
     */

    bool bfs( map<string,int>& valueTeam, string node, map<string, vector<string>>& graph){

        valueTeam[node] = 0;

        queue<string> Q; Q.push(node);

        while( !Q.empty()){

            string currentNode = Q.front();
            Q.pop();

            for( auto neighbor : graph[currentNode]){

                if( valueTeam[neighbor] == -1){
                    valueTeam[neighbor] = 1 - valueTeam[currentNode];
                    Q.push(neighbor);
                } else if ( valueTeam[neighbor] == valueTeam[currentNode]){
                    return false;
                }
            }
        }

        return true;
    }

    void printSolution(vector<string>& personajes, vector<pair<string, string>> & rivalidad ){
        adjacencySet( rivalidad);
        cout<<checkTeam(personajes, graph)<<"\n";
        graph.clear();
    }

    void printGraph( vector<string>& personajes, vector<pair<string, string>> & rivalidad){
          adjacencySet( rivalidad);
        for( auto node : graph){
            cout<<node.first<<": ";
            for( auto edge : node.second){
                cout<<edge<<" ";
            }
            cout<<"\n";
        }

    }

};

void testCases(){

    vector< pair< vector<string>, vector<pair<string,string>> > > testCases{
        { {"Rhaenyra", "Alicent", "Daemon","Corlys", "Otto", "Viserys", "Mysaria" }, 
          { {"Rhaenyra", "Alicent"},
            {"Daemon", "Otto"},
            {"Rhaenyra", "Otto"},
            {"Alicent", "Daemon"},
            {"Corlys", "Otto"},
            {"Corlys", "Alicent"},
            {"Mysaria", "Otto"} } }, //Expect 1

        { {"Rhaenyra", "Alicent", "Daemon","Corlys", "Otto", "Viserys", "Mysaria" }, 
          { {"Rhaenyra", "Alicent"},
            {"Daemon", "Otto"},
            {"Rhaenyra", "Otto"},
            {"Alicent", "Daemon"},
            {"Corlys", "Otto"},
            {"Corlys", "Alicent"},
            {"Mysaria", "Otto"},
            {"Rhaenyra", "Daemon"} } } //Expect 0
    };

    Solution sol;

    for( auto test : testCases ){
        sol.printSolution( test.first, test.second);
    }
}

int main(){
    testCases();
}