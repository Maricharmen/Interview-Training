/**
 * 287. Find the Duplicate Number
 * 
 * Given an array of integers nums containing n + 1 integers where 
 * each integer is in the range [1, n] inclusive.
 * 
 * There is only one repeated number in nums, return this repeated 
 * number.
 * 
 * You must solve the problem without modifying the array nums and 
 * uses only constant extra space.
 * 
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution_V1{
public: 

    int findDuplicate(vector<int>& nums) {

        for( auto num : nums){
            int index = abs(num);

            if( nums[index] < 0) return index;

            nums[index] = -nums[index];
        }

        return 1;
    }

    void printSolution( vector<int>& nums){
        cout<<findDuplicate( nums )<<"\n";
    }
};


/**
 * Algoritmo de Floyd's
 */

class Solution_V2{
public: 

    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while( slow != fast);

        slow = nums[0];

        while( slow != fast ){
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }

    void printSolution( vector<int>& nums){
        cout<<findDuplicate( nums )<<"\n";
    }
};

void testCases(){
    vector<vector<int>> testCases {
        {1,3,4,2,2}, // Expected: 2
        {3,1,3,4,2}, // Expected: 3
        {3,3,3,3,3}, // Expected: 3
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}