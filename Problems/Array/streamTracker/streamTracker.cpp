/*

In a real-time analytics platform at Google, a monitoring service receives
a continuous stream of metrics from various cluster nodes. Each metric update
is packaged as a pair: (timestamp, score), where timestamp is a positive integer
(seconds elapsed) and score is an integer representing the performance metric.

Due to network routing latencies and retries, updates can arrive completely out
of chronological order. For example, an update from timestamp = 10 might arrive after
an update from timestamp = 15. Additionally, if an update arrives with a timestamp
that we have already seen, it means the previous score for that timestamp was incorrect, 
and we must overwrite it with the new score.

Your task is to desing a high-performance data structure/class StreamTracker that 
supports the following operations in real-time:

void update( int timestamp, int score): Ingests or updates a metric snapshot
int getMaxScore(): Returns the maximum score currently present in the entire history
int getMinScore(): Returns the minimum score currently present in the entire history
int getLatestScore(): Return the score associated with the highest (most recent)
                        timestamp processed so far.


10 9 - 9

11 8 - 9
12 6 - 9
10 7 - 8


*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class StreamTracker{
public:

    map<int, int> scores;
    set<pair<int, int>> values; 
    pair<int, int> currentData;
    int maxTimestamp = -1;

    void update( int timestamp, int score){
        values.erase( {scores[timestamp], timestamp});
        scores[timestamp] = score;
        values.insert( {scores[timestamp], timestamp} );
    }

    int getMaxScore(){
        if( !values.empty()){
            auto it = values.rbegin();
            return it->first;
        }
        
        return -1;
    }

    int getMinScore(){
        if( !values.empty()){
            auto it = values.begin();
            return it->first;
        }
        
        return -1;
    }

    int getLatestScore(){
        
        if( maxTimestamp != -1){
            return scores[maxTimestamp];
        }
        return maxTimestamp; 
    }

    void printSolution( pair<int, int> pair){

        currentData = pair;

        if( scores.count(currentData.first) ){
            update(currentData.first, currentData.second);
        }else{
            scores[currentData.first] = currentData.second;
            values.insert({currentData.second, currentData.first});
            maxTimestamp = (maxTimestamp, currentData.first);
        }

        cout << "Max: " << getMaxScore() << " "
             << "Min: " << getMinScore() << " "
             << "LatestScore: " << getLatestScore() << "\n";
        
    }


};


int main(){

    vector<pair<int, int>> testCase {
        {10, 9},
        {11, 8},
        {12, 5},
        {10, 7}
    };

    StreamTracker sol;

    for( auto test : testCase ){
        sol.printSolution(test); 
    }
}

