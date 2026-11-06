/*
el segundo te decía tienes 1e5 maquinas en serie donde cada una tiene un output de hasta 1e7, y 
el input de una maquina es el output de la anterior. tienes un presupuesto de hasta 1e9 y puedes 
mejorar cada maquina cuantas veces quieras por un precio de hasta 2e2 de tal manera que si la mejoras 
k veces su producción va a ser su producción inicial por k+1

dada la producción inicial de cada máquina, el costo de mejorar 
cada máquina una vez y tu presupuesto inicial tienes que decir cual es la máxima producción posible

Similar: https://www.spoj.com/problems/EIUASSEMBLY/

Topic: Binary Seach on the Answer

*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    int isPossible( vector<pair<long long, int>>& robots, long long& mid, long long& budget){
        long long totalCost = 0;
        for( auto p : robots){
            long long p1 = p.first, p2 = p.second;
            if( p1 < mid){
                totalCost += (mid - p1)*p2; 
                if( totalCost > budget )return false;
            }
        }
        return true;
    }

    long long maximumProductsAfterInvest(long long& r, vector<pair<long long,int>>& robots, long long& m, long long& minimum){
        long long low = minimum, high = minimum + m;
        long long maximumInvest = minimum;

        while( low <= high){
            long long mid = (low+high)/2;
            int budget = isPossible(robots, mid, m);
            //cout << mid << " " << budget << " " << low << " " << high << "\n";

            if( budget ){
                low = mid+1;
                maximumInvest = mid;
            }else{
                high = mid-1;
            }
        }

        return maximumInvest;

    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    Solution sol;
     while(t--){
        long long r, m; cin>>r>>m;
        vector<pair<long long,int>> robots(r);
        long long minimum = -1; 
        for(int i=0; i<r; i++){
            cin>>robots[i].first>>robots[i].second;
            if( i == 0 || robots[i].first < minimum){
                minimum = robots[i].first;
            }
        }
        cout << sol.maximumProductsAfterInvest(r, robots,m, minimum)<<"\n";
     }  

}