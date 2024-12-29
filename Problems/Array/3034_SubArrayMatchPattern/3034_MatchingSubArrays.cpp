/**
 * 3034. Number of Subarrays That Match a Pattern I
 * 
 * You are given a 0-indexed integer array nums of size n, and a 0-indexed integer 
 * array pattern of size m consisting of integers -1, 0, and 1.
 * 
 * A subarray nums[i..j] of size m + 1 is said to match the pattern if the following 
 * conditions hold for each element pattern[k]:
 * 
 * nums[i + k + 1] > nums[i + k] if pattern[k] == 1.
 * nums[i + k + 1] == nums[i + k] if pattern[k] == 0.
 * nums[i + k + 1] < nums[i + k] if pattern[k] == -1.
 * 
 * Return the count of subarrays in nums that match the pattern.
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution_V1 {
public:

    bool isOne( int current, int next){
        if( next > current) return true;
        return false;
    }

    bool isZero( int current, int next){
        if( next == current) return true;
        return false;
    }

    bool isNegativeOne( int current, int next){
        if( next < current) return true;
        return false;
    }

    /**
     * Time Complexity: O(n*m)
     * Space Complexity: O(n)
     */

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        
        vector<vector<int>> subset;
        int sizeSubSet = pattern.size();

        for( int i=0; i<nums.size(); i++){
            
            vector<int> set;
           
            for( int j=i, k=0 ; k < sizeSubSet && j < nums.size() - 1  ; j++, k++){
               
                if( pattern[k] == 1 && isOne(nums[j], nums[j+1]) ){
                    set.push_back(nums[j]);
                    if( k == sizeSubSet - 1) set.push_back(nums[j + 1]);

                }else if( pattern[k] == 0 && isZero(nums[j], nums[j+1])){
                    set.push_back(nums[j]);
                    if( k == sizeSubSet - 1) set.push_back(nums[j + 1]);

                }else if( pattern[k] == -1 && isNegativeOne(nums[j], nums[j+1])){
                    set.push_back(nums[j]);
                    if( k == sizeSubSet - 1) set.push_back(nums[j + 1]);
                }

            }

            if( set.size() == sizeSubSet + 1){
                subset.push_back(set);
            }
        }

        return subset.size();
    }

    void printSolution(vector<int>& nums, vector<int>& pattern){
        cout<<countMatchingSubarrays(nums,pattern)<<"\n";
    }
};

class Solution_V2{
public:

    /**
     * Time Complexity: O(n*m)
     * Donde n es el numero de elementos y m es la longitud del patron
     * 
     * Space Complexity: = O(1)
     */

    int countMatchingSubarrays( vector<int>& nums, vector<int>& pattern){

        int sizeElements = nums.size();
        int sizePattern = pattern.size();

        int totalSubArrays = 0;

        for( int i = 0 ; i < sizeElements - sizePattern ; i++){

            int patternIndex = 0, numIndex = i + 1;
            bool isValid = true;

            while( patternIndex < sizePattern && numIndex < sizeElements ){

                int diference = nums[numIndex] - nums[numIndex - 1];

                if( pattern[patternIndex] == 1 && diference >= 1 || pattern[patternIndex] == 0 && diference == 0 || pattern[patternIndex] == -1 && diference <= -1 ){
                   patternIndex++;
                   numIndex++;
                }else{
                    isValid = false;
                    break;
                }
            }

            if( isValid && patternIndex == sizePattern){
                totalSubArrays++;
            }
        }

        return totalSubArrays;
    }
};  

void testCases(){
    vector<pair<vector<int>,vector<int>>> testCases {
        { {1,2,3,4,5,6}, {1,1}}, // Expected: 4
        { {872500231,872500231,872500231,872500231}, {0}} // Expected: 3
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}