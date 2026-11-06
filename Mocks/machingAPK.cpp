/*
In Android (the popular Google mobile operating system), the executable files storing apps on devices 
are called "APKs". And each APK contains something called a "Manifest" which stores which devices 
it is compatible with. So for example, it might say needs a specific Android version, or needs a GPS chip. 
In this question, we are only going to think about the Android version requirements in the Manifest.

There are two values minSDKVersion and maxSDKVersion. Each of these is optional, and inclusive. By this 
I mean APKs don't have to specify minSDKVersion, but if they specify minSDKVersion = 3, then Android 
versions 3,4,5,etc all match, but 1 and 2 don't.

An app developer can upload multiple APKs for their app to the Play Store, each with a different manifest. 
For example, they might have three APKs:
APK      Min SDK Version  Max SDK Version
APK A           4               -
APK B           -               16
APK C           7               10

Now, on Google Play you can have more than one APK per App, and we need to decide which one to deliver. 
So you could have A,B, and C. As part of this process we need to split up the space of all phones to which 
APKs they match.
We want to divide the integer list of SDK versions into intervals that match the same APKs. So for this set we want to produce:

	    B      A,B   A,B,C,   A,B,     A
output: (1,3), (4-6), (7-10), (11-16), (17,INT_MAX)

This is because <=3 matches only APK B, then (4-6) matches APK A & B, but not C, etc.
Use whatever sensible data structure you want to represent the input and the output.

 A 1 3
 B 3 5
 C 4 8

 m M m m M M
 1 3 3 4 5 8

  A
(1,3) (4, 4) (3, 5) (4, 5) (6, 8)
  A    A,B     B,C   C
(1,2) (3, 3) (4,5) (6,8)

 m m M m M M
 1 3 3 4 5 8

(1,2) (3, 3) (4, 3 ) (4, 5) (6, 8)

A 1 3
B 3 5
C 5 8
m m M m M M
1 3 3 5 5 8
 A       A,B    B      B,C      C
(1, 2) (3, 3) (4, 4) (5, 5) (6, 8)

1 1
3

*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:

     // Time Complexity: (nlog(n))
     vector<pair<int, int>> partitionSDKInterval(vector<pair<int, int>>& sdk){
        vector<pair<int, int>> intervals;
        set<int> starts;
        
        starts.insert(1); starts.insert(INT_MAX);

        for(auto& [m, M] : sdk){
            if( m == -1) m = 1;
            starts.insert(m);
            if( M == -1 ) M = INT_MAX-1;
            starts.insert(M+1);
        }

        for (auto it = starts.begin(); it != prev(starts.end()); it++) {
            int first = *it, second = *next(it);
            intervals.push_back({first, second-1});
        }

        return intervals;

    }
    // Follow up 1: Time Complexity: (n^{2})
    vector<pair<int, int>> partitionSDKInterval_F1(vector<pair<int, int>>& sdk){
        vector<pair<int, int>> intervals;
        set<int> starts;

        for(auto& [m, M] : sdk){
            if( m == -1) m = 1;
            starts.insert(m); 
            if( M == -1 ) M = INT_MAX-1;
            starts.insert(M+1);
        }

        for (auto it = starts.begin(); it != prev(starts.end()); it++) {
            int first = *it, second = *next(it);
            int numSets = 0;
            for(int i = 0; i < sdk.size(); i++){
                int firstSet = sdk[i].first, secondSet = sdk[i].second;
                if( firstSet <= first && secondSet >= second-1 ) numSets++;
            }
            if(numSets > 0 ) intervals.push_back({first, second-1});
        }

        return intervals;

    }

    // Follow up 2: Time Complexity: (nlog(n))
    vector<pair<int, int>> partitionSDKInterval_F1_Optimal(vector<pair<int, int>>& sdk){
        map<int, int> changes;
        vector<pair<int, int>> intervals;
        set<int> starts;

        for(auto& [m, M] : sdk){
            if( m == -1) m = 1;
            if( M == -1 ) M = INT_MAX-1;
            starts.insert(m); 
            starts.insert(M+1);

            changes[m]++; changes[M+1]--;
        }

        int activeCount = 0;

        for (auto it = changes.begin(); it != prev(changes.end()); it++) {
            int first = it->first, second = next(it)->first;
            
            activeCount += it->second;
            
            if (activeCount > 0 && first <= second - 1){
                intervals.push_back({first, second - 1});
            }
        }

        return intervals;

    }

    void printSolution(vector<pair<int, int>>& sdk){
        for( auto& [a,b] : partitionSDKInterval_F1_Optimal(sdk)){
            cout << "[" << a << ", " << b << "] ";  
        }
        cout << "\n";
    }
};

int main( ){
    vector<vector<pair<int, int>>> testCases = {
        {{4, -1}, {-1, 16}, {7, 10}}, // (1,3), (4,6), (7,10), (11,16), (17,INT_MAX)
        {{1,3}, {3,5}, {4,8}}, // (1,2) (3, 3) (4, 5) (6, 8) (9, INT_MAX) F1: (1,2) (3, 3) (4, 5) (6, 8) 
        {{1,3}, {5,8}, {10, 12}} // F1: (1,3) (5,8) (10,12)
    }; 

    Solution sol;
    for(auto test : testCases){
        sol.printSolution(test);
    }
}

/*
Follow-up 1
What if Google Play wants to display only the ranges of versions where the user 
can actually download at least one APK, completely ignoring unsupported versions?
*/

/*
Follow-up 2
Google Play cannot deliver three different APKs to the same device. If multiple APKs 
match a device's SDK version, we must deliver exactly one APK based on a priority rule 
(for example, higher versionCode or the most targeted build). How would you modify the 
output so each interval maps to exactly one APK?

*/
