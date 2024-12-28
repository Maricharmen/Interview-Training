/*



La segunda fue de pasar un número decimal a maya

Y la tercera fue de que tienes un patrón que inicia con 0 y luego para seguir generando 
duplicas tu cadena pero inviertes cada 0 por un 1 y cada 1 por un 0 osea de 0 pasas a 01 
y luego 0110 y luego 01101001 y así continuamente, y dado un índice debes retornar si es 
0 o 1 en esa posición

1: 0  2^(0) 0
2: 01  2^(1) 1
3: 0110 2^(2)  1
4: 01101001  0
5: 0110100110010110 1
6: 01101001100101101001011001101001 0
.
.
n

Input:  n - interger -> 3
Process:

1: 0
2: 01
3: 0110

Output: 1

 */

#include <iostream>
#include <string>
using namespace std;

/**
 * 
 * Time Complexity:  O(n*m)
 * Space Complexity: O(n)
 * 
 */
class Solution_V1{
public:

    char binaryPattern( int n){

        string currentNum = "0";
        int i = 0;

        while( i < n){ 
            
            string currentStr = currentNum;

            for( char &digit : currentStr){
                digit ^= 1;
            }

            currentNum +=  currentStr;

            i++;
        }

        return currentNum[n];

    }
};


int main(){

    int n=3;
    Solution_V1 sol;

    cout<< sol.binaryPattern(n-1);
}



