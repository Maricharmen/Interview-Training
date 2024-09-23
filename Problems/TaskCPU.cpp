/**
 * Task CPU
 * 
 * Given a char array representing task CPU needs to do. It contains
 * capital letters A to Z where different letters represent different
 * task. Tasks need to be done with original order. Each task can be 
 * done in one interval. For each interval, CPU could finish one task
 * or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means
 * between two same tasks, there must be at least n intervals that CPU
 * are doing different task or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take
 * to finish all the given tasks.
 * 
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution_V1{
public:

    int intervalRequired( vector<char>& elements, int interval){

        int size = elements.size();
        int addSpace = 0; 

        for( int low = 0; low < size ; low++){

            cout<<elements[low]<<"\n";

            for( int high = low + 1; high < size ; high++){

                cout<<elements[high]<<" ";

                if( elements[low] == elements[high]){
                    int diff = high - low + addSpace;

                    if( diff <= interval){
                        addSpace += (interval - diff) + 1; 
                    }

                    break;
                }


            }

            cout<<"\n";
        }
        
        return size + addSpace;
    }

    void printSolution( vector<char>& elements, int interval){
        cout<<intervalRequired(elements, interval)<<"\n";
    }
};


void testCases(){
    vector<pair<vector<char>, int>> testCases {
        {{'A', 'B', 'C', 'A', 'B', 'C'}, 3}, // Expected: 7
        {{'A', 'B', 'C', 'B', 'C'}, 3}, // Expected: 7
        {{'A', 'A', 'A', 'B', 'B', 'B'}, 3} // Expected: 9?
    };

    Solution_V1 sol;

    for( auto test : testCases ){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}

/*

A:2 1 A _ _ _ A -> 4
B:2 2 B _ _ _ B -> 4
C:2 3 C _ _ _ C -> 4

maxi = 2 :maxima frecuencia, numero de bloques A _ A _ A dos bloques
1 2 3 4 5 6 7
A _ _ _ A
  B _ _ _ B
    C _ _ _ C

A B C _ A B C

count = 3;
intervalo = 3 espacios que tiene

val = (2-1)(3 + 1) + 3 = 7

A B C _ A B C D
      D

      val = 1*4 + 4 = 8
B:2
C:2
A:1

maxi: 2

count: 2

val = 1*4 + 2 = 6


*/