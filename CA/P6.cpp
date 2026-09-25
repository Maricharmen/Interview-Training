/**
 * 
 * Tienes 2 vectores a y b con elementos y tienes una series querys, unos son la forma
 * [0, i, x] donde actualizas el valor a[i] a x
 * 
 * La otra es
 * [1, x] donde calculas el número de parejas a[i] +b[j] = x
 * La longitud de a es 5e4, la de B es 1e3 y el número de querys total es 1e3
 * Devuelve todos los resultados de las querys de la forma
 * [1, x]
 * 
 * Similar: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/
 */

 
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class FindSumPairs {
public:
    
    vector<int> vec1;
    vector<int> vec2;
    map<int, int> num1;
    map<int, int> num2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;

        for( auto i : nums1) num1[i]++;
        for( auto i : nums2) num2[i]++;

    }
    
    void add(int index, int val) {
        num2[vec2[index]]--;
        vec2[index] += val;
        num2[vec2[index]]++;
    }
    
    int count(int tot) {
        int countpair = 0;
        for( auto [a,b] : num1){
        
            int find = tot - a;
            if( num2.count(find) ){

                countpair+= b*num2[find];
            }
        }

        return countpair;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
 