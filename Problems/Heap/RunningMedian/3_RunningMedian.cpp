/**
 * Question 3: Running Median
 * 
 * You are given an array of numbers representing a stream received one
 * by one. Return an array representing the median after each new number 
 * is received.
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Version 1
 * Approach: Heap
 * Required Time: 32:47 minutes
 * Assumpitions:
 * - To find the mediam, the numbers must be in order
 */
class Solution_V1 {
public:

    /**
     * Find the median from a priority queue
     * 
     * Complexity Time: O(n) ->Linear
     * Complexity Space: O(1) ->Constant
     * 
     * @param inOrder Priority queue containing the elements in order.
     * @param median Index of the median element
     * @return Median value
     */

    double findMedian( priority_queue<int> inOrder, int median){
        
        // Iterate to find the median
        for( int i=0; i<inOrder.size() ; i++){
            if( i == median) return inOrder.top(); 
            inOrder.pop(); 
        }

        return inOrder.top();
    }

    /**
     * Calculates the running median of a list of elements
     * 
     * Complexity Time: O( (n^2) log n) -> Quasi-Quadratic
     * Complexity Space: O(n) -> Linear
     * 
     * @param elements List of elements
     * @return Vector of running medians
     */

    vector<double> runningMedian(vector<int>& elements){

        priority_queue<int> inOrder; // Max-Heap
        vector<double> medianElements; 

        for( int i=0; i < elements.size(); i++){

            inOrder.push(elements[i]); // Add element to heap

            // Add median
            if( i%2 == 0){ 
                medianElements.push_back(findMedian(inOrder, i/2));
            }else{
                medianElements.push_back( (findMedian(inOrder, i/2 + 1 ) + findMedian(inOrder, i/2))/ 2);
            }
        }

        return medianElements;

    }

    /**
     * Prints the running median of the list.
     * 
     * @param elements List of numbers.
     */

    void printSolution( vector<int>& elements){
        for( auto num : runningMedian(elements)){
            cout<<num<<" ";
        }
        cout<<"\n";
    }
};

/**
 * Version 2
 * Approach: Two Heaps
 * Required Time: 32:28 minutes
 */

class Solution_V2 {
private:

    priority_queue<int> low; // Max-Heap
    priority_queue<int, vector<int>, greater<int>> high; // Min-Heap

public:

    /**
     * Adds a number to heaps
     * 
     * Complexity Time: O(log n) ->Logarithmic
     * Complexity space: O(1) ->Constant
     * 
     * @param num Current number of the list
     */

    void addNum(int num){

        if( low.empty() || num <= low.top() ){
            low.push(num);
        }else{
            high.push(num);
        }

        //Balance the heaps

        if( low.size() > high.size() + 1){
            high.push(low.top());
            low.pop();
        }else if( high.size() > low.size()){
            low.push(high.top());
            high.pop();
        }
    }

    /**
     * Finds the median of the current numbers
     * 
     * Compexity Time: O(1) ->Constant
     * Complexity Space: O(1) ->Constant
     */

    double findMedian(){
        if( low.size() > high.size()){
            return low.top();
        }else{
            return (low.top() + high.top())/2.0;
        }
    }

    /**
     * Calculates the running median of a list of elements
     * 
     * Complexity Time: O(n log n) ->Quasi-linear
     * Complexity Space: O(n) ->Linear
     * 
     * @param elements List of elements
     * @return Vector of running medians
     */
    
    vector<double> runningMedian(vector<int>& elements){
        vector<double> medianElements;

        for( int num : elements){
            addNum(num);
            medianElements.push_back( findMedian() );
        }

        return medianElements;
    }

    /**
     * Prints the running median of the list.
     * 
     * @param elements List of numbers.
     */

    void printSolution( vector<int>& elements){
        for( auto num : runningMedian(elements)){
            cout<<num<<" ";
        }
        cout<<"\n";
    }

};

void testCases(){
    vector<vector<int>> testCases {
        {1,11,4,15,12}, // Expected: [1,6,4,7.5,11]
    };

    Solution_V2 sol;

    for(auto test : testCases){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}