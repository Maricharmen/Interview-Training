/**
 * Alien Dictionary
 * 
 * Given a sorted dictionary of an alien language having N words and l
 * starting alphabets of standard dictionary. find the order of characters
 * in the alien language. 
 * 
 */

/*
                [  7      10      11      10      9                  
Input words[] = {"baa", "abcd", "abca", "cab", "cad"}
Output 'b' 'd' 'a' 'c'


b -> d -> a -> c
 
-----------------------
caa aaa aab

c a b 

caa < aaa < aab

c -> a
a -> b

*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;


class Solution_V1{
public:
  
    map<int, set<int>> graph;
    set<pair<int, int>> edges;
    set<int> nodes;

    void listAdjaceny( set<pair<int, int>>& connection ){
        for( auto node : connection){
            graph[node.first].insert(node.second);
        }
    }

   void getEdges( vector<string>& dict, int N ){
        
        for( int i=0; i < N - 1; i++){

            string first = dict[i];
            string second = dict[i+1];

            int k=0, j=0;

            while( k < first.size() && j < second.size()){

                if( first[k] != second[j]){
                    edges.insert({first[k] - 'a', second[j] - 'a'});
                    nodes.insert(first[k] - 'a' ); nodes.insert(second[j] - 'a');
                    break;
                }

                k++;
                j++;
            }

        }

    }

    string findOrder(vector<string>& dict, int N, int k) {
        getEdges(dict, N);

        vector<int> inDegrees(26, 0);

        for( auto node : graph){
            for( auto edge : node.second){
                inDegrees[edge]++;
            }
        }

        queue<int> Q;

        for( auto node : nodes){
            if( inDegrees[node] == 0) Q.push(node);
        }

        vector<int> order;

        while( !Q.empty()){

            int current = Q.front();
            Q.pop();

            order.push_back(current);

            for( auto next : graph[current]){
                inDegrees[next]--;
                if( inDegrees[next] == 0) Q.push(next);
            }

        }

        if( order.size() != k) return "0";

        string result;
        for (int c : order) {
            result += (char)(c + 'a');
        }

        return result;

    }

    void printSolution( vector<string>& dict, int N, int k){
        
        listAdjaceny(edges);

        cout<<findOrder(dict, N, k)<<"\n";

        graph.clear();
        edges.clear();
        nodes.clear();
    }

    void printGraph(){
        for( auto node : graph){
            cout<<node.first<<" : ";
            for( auto edge : node.second){
                cout<<edge<<" ";
            }
            cout<<"\n";
        }
    }
};

void testCases(){
    vector< pair< vector<string>, pair<int, int>>> testCases {
        { {"baa", "abcd", "abca", "cab", "cad" }, {5,4} },
        { {"caa", "aaa", "aab"}, {3, 3} },
        { {"baa", "abcd", "abca", "cab", "cada"}, {5,4}},
    };

    Solution_V1 sol;

    for( auto test : testCases ){
        sol.printSolution(test.first, test.second.first, test.second.second);
    }
}

int main(){
    testCases();
}
