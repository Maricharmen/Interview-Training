/**
 * Minimum Team Size
 * 
 * Se te da un entero N que representa el numero total de talentos, 
 * identificados del 1 al N, y un arreglo de enteros talents de longitud
 * M, donde talents[i] representa el talento que posee la persona en 
 * la posicion i.
 * 
 * Debes formar grupos consecutivos de personas. Para cada posición inicial
 * i (0 <= i < M ), determina el tamaño minimo de un subarray consecutivo
 * que comience exactamente en el indice i y que contenga al menos una persona
 * con cada uno de los N talentos. 
 * 
 * Si desde la posicion i hasta el final del arreglo no es posible reunir los
 * N talentos, se debe devolver -1 para esa posicion
 * 
 * Entrada 
 * 3, [1,2,1,3,2,3]
 * Salida
 * [4,3,3,-1,-1,-1]
 */

/**
 * Version #
 * Approach: Data Structure / Algorihmic / Solution
 */

/**
 * Complexity Time: 
 * Complexity Space: 
 */

 #include <bits/stdc++.h>
 using namespace std;

 class Solution_v1{
    private:

    public:

    vector<int> minimumTeamSize(int n, vector<int>& talents){
        vector<int> teams;
        vector<int> count(n+1, 0);
        set<int> unique;
        
        int left = 0, right = 0;

        while( right < talents.size()){

            unique.insert(talents[right]);
            count[talents[right]]+=1;

            if( unique.size() == n){
                while( left <= right && unique.size() == n){
                    teams.push_back(right-left+1);
                    if(count[talents[left]] > 1){
                        count[talents[left]]-= 1;
                    }else{
                        unique.erase(talents[left]);
                        count[talents[left]]-= 1;
                    }

                    left++;
                }
            }

            right++;
        }

        for( int i=teams.size(); i < talents.size(); i++){
            teams.push_back(-1);
        }

        return teams;
    }

    void printSolution(int n, vector<int>& talents){
        vector<int> sol = minimumTeamSize(n, talents);
        for( int i=0; i<talents.size(); i++){
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
 };

 int main(){
    vector<pair<int, vector<int>>> tests {
        {3,  {1,2,1,3,2,3}}, // [4,3,3,-1,-1]
        {1, {1,1,1}}, // [1,1,1]
        {5, {1,2,3,4,1,2,3,4,5}}, // [9,8,7,6,5,-1,-1,-1]
        {5, {1,2,3,4,5,1,1,2,3,4,5, 1, 1, 1, 1}} //[5,5,6,6,6,6,5,-1,-1,-1]
    };

    for(auto test : tests){
        Solution_v1 sol;
        sol.printSolution(test.first, test.second);
    }
    return 0;
 }