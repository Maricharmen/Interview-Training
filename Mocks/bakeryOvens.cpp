/*
A bakery has a fixed number of ovens, each capable of baking a loaf of bread in S seconds.
However, since the batches of dough arrive at random time, the baker has the options to 
choose which oven to use for each batch. Help the baker calculate the minimum time required
to bake all the loaves.

Test 1
2 ovens
5 seconds per bread
breads = [1, 3, 5]
output = 11

Test 2
5 ovens
7 seconds per bread
breads = [7,6,4,3,1]
output = 14

1e4 ovens, 10000, 10^{4}
1e1 breads, 10 10^{1}
20 secs 

Notes:
- Each batch represent 1 bread 
- The array represent the time you receive

- Sort the breads by arrival time
- Min heap of ovens: {available time, oven id}, always take the oven that frees up first
- Bread starts baking at max(available, bread): if the oven is free before the bread
  arrives, add up the waiting time (bread - available)
- nextAvailable = max(available, bread) + S
- Answer = max nextAvailable over all breads

[1, 3, 5], 2 ovens, S = 5
O1: 0 (1) A: (0 + 5 + (1-0) = 6) (5) A: (6 + 5 + 0 = 11) -> 11
O2: 0 (3) A: (0 + 5 + (3-0) = 8)
output: 11

[1, 3, 7], 2 ovens, S = 5
O1: 0 (1) A: (0 + 5 + (1-0) = 6) (7) A: (6 + 5 + (7-6) = 12) -> 12
O2: 0 (3) A: (0 + 5 + (3-0) = 8)
output: 12

n = number of ovens, m = number of breads
Time Complexity: O(n log n + m log m + m log n)
- Build the min heap of ovens: n pushes * O(log n) = O(n log n)
- Sort the breads: O(m log m)
- Loop: m times top + pop + push on a heap of size n = O(m log n)
  (the heap always has n ovens, not m breads)
Space Complexity: O(n + m)
- Heap: O(n)
- Copy of breads (passed by value): O(m)

Optimization: never use more than m ovens -> push only min(n, m) ovens
- Time: O(m log m), Space: O(m)

1e4 ovens, 10000, 10^{4}
1e1 breads, 10 10^{1}
20 secs

1s ~ 5x10^{8}

n <= 5 x10^{8}
nlogn <= 2x10^7

10^{4}log10^{4} ~10^4*14 ~ 1.4x10^{5}  -> fits easily


*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution{
public:
    int minimumTimeBaking(int ovens, int time, vector<int> breads){

        priority_queue< pair<int, int> , vector<pair<int, int>> , greater<pair<int,int>>> minOvens;
        for( int i=1; i<=ovens; i++ ) minOvens.push({0, i});

        sort(breads.begin(), breads.end());
        int minTime = 0;

        for( int bread : breads){
            int available = minOvens.top().first;
            int oven = minOvens.top().second;
            minOvens.pop();
            int nextAvailable = available + time;
            if( bread-available > 0 ) nextAvailable += bread-available;
            minOvens.push({nextAvailable, oven});
            minTime = max(minTime, nextAvailable);
        }

        return minTime;
    }

    void printSolution(int ovens, int time, vector<int> breads){
        cout << minimumTimeBaking(ovens, time, breads)<< "\n";
    }
};

int main(){
    
    Solution sol;
    sol.printSolution(2, 5, {1,3,5} ); // 11
    sol.printSolution(5, 7, {7,6,4,3,1} ); // 14
    sol.printSolution(2, 5, {1,3,7} ); // 12

    return 0;

}







