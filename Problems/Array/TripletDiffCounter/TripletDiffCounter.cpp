/**
 * TripletDiffCounter
 * 
 * Dado un conjunto de operaciones que modifican un conjunto de números, debes 
 * determinar el número de tripletas válidas que cumplen con una diferencia constante 
 * entre sus elementos. La secuencia de operaciones es dada como una lista de cadenas, 
 * donde cada cadena representa una operación y un número asociado.
 * 
 * Las operaciones se definen de la siguiente manera:
 * 
 * - Una operación de adición está representada por un signo '+' seguido de un número. 
 *   Esto indica que el número debe ser agregado al conjunto de números.
 * - Una operación de eliminación está representada por un signo '-' seguido de un número. 
 *   Esto indica que el número debe ser eliminado del conjunto de números, si está presente.
 * 
 * Una tripleta válida es aquella que cumple con la condición:
 * - Dado un número a, b, y c en el conjunto, la diferencia entre a y b debe ser igual a 
 *   la diferencia entre b y c. En otras palabras, a - b = b - c = diff, donde 'diff' es 
 *   un valor dado.
 * 
 * Ejemplo:
 * Entrada:
 * vector<string> operations = {"+1", "+2", "+3", "+4", "-1"};
 * int diff = -1;
 * 
 * Salida:
 * vector<int> result = {0,0,1,2,1};
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution_V1{
public:

    /**
     * Time Complexity: (n*m*m)
     * Space Complexity: O(n)
     */

    vector<int> tripleDiffCounter( vector<string>& operation, int diff){

        int size = operation.size();
        vector<int> solution;
        vector<int> elements;

        for( auto op : operation){

            char symbol = op[0];
            string number = op.substr(1, op.size()-1);
            int toNumber = stoi(number);
         
            if( symbol == '+'){
                
                elements.push_back(toNumber);

            }else if(symbol == '-'){

                elements = removeNumber(elements, toNumber);
            }

            if( elements.size() >= 3){
                solution.push_back(validTriple(elements, diff));
            }else{
                solution.push_back(0);
            }
        }

        return solution;
    }

    vector<int> removeNumber( vector<int>& elements, int number){
        vector<int> newElement;

        for( int i=0; i < elements.size(); i++){
            if( elements[i] != number){
                newElement.push_back(elements[i]);
            }
        }

        return newElement;
    }

    int validTriple(vector<int>& elements, int diff ){
        int valid = 0;

        for( int i=0; i<elements.size(); i++){
            if( i >= 2){
                int a = elements[i-2];
                int b = elements[i-1];
                int c = elements[i];
                if( a-b == diff && b-c == diff ) valid++;
            }
        }

        return valid;
    }

    void printSolution( vector<string>& elements, int diff){
        for( auto num : tripleDiffCounter(elements, diff)){
            cout<<num<<" ";
        }
        cout<<"\n";
    }

};

class Solution_V2{
public:

    /**
     * Time Complexity: (n*m)
     * Space Complexity: O(n)
     */

    vector<int> tripleDiffCounter( vector<string>& operation, int diff){

        vector<int> solution;
        vector<int> elements;

        int validTriples = 0;

        for( auto op : operation){

            char symbol = op[0];
            string number = op.substr(1, op.size()-1);
            int toNumber = stoi(number);

            int a, b, c;
            int size = elements.size();
         
            if( symbol == '+'){
                
                if( size >= 2){
                    a = elements[size - 2];
                    b = elements[size - 1];
                    c = toNumber;

                    if( a - b == diff && b - toNumber == diff) validTriples++;
                }

                elements.push_back(toNumber);               

            }else if(symbol == '-'){

                vector<int> newElements;

                for( int i=0; i < size; i++){
                    if( elements[i] == toNumber){
                    
                        if( size >= 3 ){

                            if( right(elements, i, diff) ) validTriples--;
                            if( half(elements,i, diff) ) validTriples--;
                            if( left(elements,i, diff) ) validTriples--;

                        }else{
                            newElements.push_back(elements[i]);
                        }
                    }
                }

                elements = newElements;
            }

            if(validTriples < 0) validTriples = 0;
            solution.push_back(validTriples);
        }

        return solution;
    }

    bool left( vector<int>& elements, int i, int diff){
        if( i-1 < 0 || i-2 < 0) return false;
        if( elements[i-2] - elements[i-1] == diff && elements[i-1] - elements[i] == diff) return true;
        return false;
    }

    bool half( vector<int>& elements, int i, int diff){
        if( i-1 < 0|| i+1 > elements.size()) return false;
        if( elements[i-1] - elements[i] == diff && elements[i] - elements[i+1] == diff ) return true;
        return false;
    }

    bool right( vector<int>& elements, int i, int diff){
        if( i+1 > elements.size() || i+2 > elements.size()) return false;
        if( elements[i] - elements[i+1] == diff && elements[i+1] - elements[i+2] == diff ) return true;
        return false;
    }


    void printSolution( vector<string>& elements, int diff){
        for( auto num : tripleDiffCounter(elements, diff)){
            cout<<num<<" ";
        }
        cout<<"\n";
    }

};

class Solution_V3{
public:

    /**
     * Time Complexity: (n*m)
     * Space Complexity: O(n)
     */

    vector<int> tripleDiffCounter( vector<string>& operation, int diff){

        vector<int> solution;
        vector<int> elements;
        map<int, int> freqValidTriples;

        int validTriples = 0;

        for( auto op : operation){

            char symbol = op[0];
            string number = op.substr(1, op.size()-1);
            int toNumber = stoi(number);

            int a, b, c;
            int size = elements.size();
         
            if( symbol == '+'){
                
                if( size >= 2){
                    a = elements[size - 2];
                    b = elements[size - 1];
                    c = toNumber;

                    if( a - b == diff && b - toNumber == diff){

                        validTriples++;

                        freqValidTriples[a]++;
                        freqValidTriples[b]++;
                        freqValidTriples[c]++;
                    }
                }

                elements.push_back(toNumber);               

            }else if(symbol == '-'){

                vector<int> newElements;

                for( int i=0; i < size; i++){
                    if( elements[i] != toNumber) newElements.push_back(elements[i]);  
                }

                validTriples -= freqValidTriples[toNumber];

                elements = newElements;
            }

            if(validTriples < 0) validTriples = 0;
            solution.push_back(validTriples);
        }

        return solution;
    }

    void printSolution( vector<string>& elements, int diff){
        for( auto num : tripleDiffCounter(elements, diff)){
            cout<<num<<" ";
        }
        cout<<"\n";
    }

};


void testCases(){
    vector<pair<vector<string>, int>> testCases {

        { {"+4","+7","+10","-7"}, -3}, // Expected: [0,0,1,0]
        { {"+1", "+2", "+4", "+6", "+8", "-4"}, -2}, // Expected: [0,0,0,1,2,0]
        { {"+6","+5","+4", "+7","+4", "-4"}, 1},// Expected: [0,0,1,1,1,0]
        { {"+4", "+4", "+4","-5"}, 0}, //Expected: [0,0,1,1]
        { {"+2", "+2", "+2", "+2", "-2", "-2", "-2", "-2"}, 0}, //Expected: [0,0,1,2,0,0,0,0]
        { {"+1", "+2", "+3", "+4", "-1"}, -1}, // Expected: [0,0,1,2,1]
        { {"+2", "+4", "+6", "+8", "+6", "+8"}, -2}, // Expected: [0,0,1,2,2,2]
        { {"+1", "+2", "+3", "-2", "+4"}, -1} // Expected: [0,0,1,0,0]

    };

    Solution_V3 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}


