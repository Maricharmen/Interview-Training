/*

You are given an unsorted array of rental records. Each record is 
[recordId, pickupTime, returnTime], where recordId uniquely identifies the rental

A car can serve only non-overlapping rentals. Treat every rental as the half-open
interval [pickupTime, returnTime], so a car returned at time t may be reused by a rental 
picked up at time t. A zero-duration interval [t, t) is empty: assign it to car 0 (creating 
car 0 if necessary) without changing that car's availability

Assign every rental to a car while using the minimum possible numbers of cars. Car
IDs are consecutive integers beginning at 0

Use the deterministic rules when several minimum-car assignments are possible

1. Process records by increasing pickupTime, then increasing return Time, then
incresing recordId
2. Assign a zero-duration record to car 0 without changing any busy or vailable state
3. Before assigning a positive-duration record, make every car whose current rental has
returned available -- 
4. Reuse the available car with the smallest car ID. If no car is available, create the
next car ID

Return a String[] in increasing car-Id order. Each string has the form 
carID: recordID, recordId and lists that car´s rental IDs in assigment order. The arrray
length is the minimum car count, and the line also define the record-ID-to-car assignment

Example 1
requests = [[101, 1, 3], [102, 2, 4], [103, 4, 6]]
return = ["0: 101 103", "1: 102"]

Example 2
requests = [[203, 5, 7], [201, 1, 5], [202, 2, 3]]
return = ["0: 201 203", "1: 202"]

Example 3
requests = [[11, 3, 3], [10, 3, 3], [12, 3, 4]]
return = ["0: 10 11 12"]

Example 4
request = []
return = []

OBSERVATION
- it is important that the request list be sorted by request time, then time finish and id
- if a request has a zero duration assing to car 0, and dont change the availabity
- Q: is there a maximum numer of Id cars? No upper cap
- Q: is valid input? Yes no null elements are unique positive integers
    0 <= pickupTime <= returnTime
- Q: is there any constrait values? 
    timestap up to 10^{9}
    N up to  10^^{5}

Simulation

Example 1
requests = [[101, 1, 3], [102, 2, 4], [103, 4, 6]] - sorted 
return = ["0: 101 103", "1: 102"]

Car IDs: 

0: 101 103 - 3
1: 101 - 4

request:
[101, 1, 3]
[102, 2, 4]
[103, 4, 6]

Example 3
requests = [[11, 3, 3], [10, 3, 3], [12, 3, 4]]
return = ["0: 10 11 12"]

[ 3, 3, 10] [ 3, 3, 11] [ 3, 4, 12]

Car Ids
0: 10 11 12 - 3

request 

[ 3, 3, 10] 
[ 3, 3, 11]  if is zero duration add to id 0
[ 3, 4, 12]

Optimal: 
Example 1
requests = [[101, 1, 3], [102, 2, 4], [103, 4, 6], [104, 5, 8]] - sorted 
return = ["0: 101 103", "1: 102"]

busyCar = { id, tobefree} { {0, 6} {1, 8} }
freeCar = { id } {   }
carId = {0, 1 }

request
[ 1, 3, 101] -> 0 

[2, 4, 102] -> +1

[ 4, 6, 103] -> 0

[ 5, 8, 104] -> 1

0: 101 103 1: 102 104

N: number of request 
C: number of idcars
Time complexty: O(N log N + N * C log C)   (en cada renta se sacan y re-meten todos los libres)
Space Completity: O(N + C)

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution{
private:
    vector<vector<int>> requestSorted;

public:

    void sortedbyTimeRequest(vector<vector<int>>& request){
        for( vector<int>& r : request ){
            requestSorted.push_back({r[1], r[2], r[0]});
        }
        sort(requestSorted.begin(), requestSorted.end());
    }

    // N: número de rentas, C: número de carros (C <= N)
    // Tiempo: O(N log N + N * C log C), peor caso O(N^2 log N)   Espacio: O(N)
    vector<vector<int>> minimumCarsforRentalRequest(vector<vector<int>>& request){
        if( request.empty() ) return {};

        sortedbyTimeRequest(request);   // O(N log N)

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> carFree;
        vector<vector<int>> minimumCarId(1);
        carFree.push({0,0});

        for( vector<int>& request : requestSorted){   // N iteraciones
            int pickupTime = request[0];
            int returnTime = request[1];
            int requestId = request[2];

            auto [timeFree, carId] = carFree.top();

            if( pickupTime == returnTime ){             // O(1)
                minimumCarId[0].push_back(requestId);
            } else if(pickupTime < timeFree ){          // O(log C) push del carro nuevo
                int newCarID = minimumCarId.size();    
                minimumCarId.push_back({requestId});
                carFree.push({returnTime, newCarID});
            }else{

                int minId = carId;
                vector<pair<int, int>> memoCardId;

                // O(C log C): saca todos los carros libres (hasta C pops)
                while( !carFree.empty() && pickupTime >= timeFree  ){

                    memoCardId.push_back({timeFree, carId});

                    if( carId < minId ){
                        minId = carId;
                    }

                    carFree.pop();
                    if( carFree.empty() ) break;    

                    timeFree = carFree.top().first;  
                    carId = carFree.top().second;
                }

                // O(C log C): los vuelve a meter (hasta C pushes)
                for( auto [time, id] : memoCardId){
                    if( minId != id ){
                        carFree.push({time, id});
                    }
                }

                carFree.push({returnTime, minId});
                minimumCarId[minId].push_back(requestId);
            }

        }

        return minimumCarId;

    }

    // N: número de rentas, C: número de carros (C <= N)
    // Tiempo: O(N log N)   Espacio: O(N)
    vector<vector<int>> minimumCarsforRentalRequest_V2(vector<vector<int>>& request){
        if( request.empty() ) return {};

        sortedbyTimeRequest(request);   // O(N log N)

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyCars;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeCars;
        vector<vector<int>> minimumCarId(1);
        freeCars.push({0,0});

        for( vector<int>& request : requestSorted){   // N iteraciones
            int pickupTime = request[0];
            int returnTime = request[1];
            int requestId = request[2];

            if( pickupTime == returnTime ){             // O(1)
                minimumCarId[0].push_back(requestId);
                continue;
            }

            // O(log C) amortizado: cada renta entra y sale de busyCars a lo más una vez
            while( !busyCars.empty() && pickupTime >= busyCars.top().first){
                auto [timeFree, carId] = busyCars.top();
                freeCars.push({carId, timeFree});
                busyCars.pop();
            }
            
            int carId ;                                 // O(log C) pop/push en heaps
            if( !freeCars.empty() ){
                carId = freeCars.top().first;
                freeCars.pop();
            }else{
                carId = minimumCarId.size();
                minimumCarId.push_back({});
            }

            minimumCarId[carId].push_back(requestId);
            busyCars.push({returnTime, carId});

        }

        return minimumCarId;

    }

    void printSolution( vector<vector<int>> request){
        requestSorted.clear();
            vector<vector<int>> minimumCarId = minimumCarsforRentalRequest_V2(request);
            for( int car = 0; car < minimumCarId.size() ; car++){
                cout << car << ":";    
                for( int id : minimumCarId[car] ){
                    cout << " " << id;
                }
                cout << "\n";
            }
            cout << "\n";
        }
};

int main( ){
    Solution sol;
    sol.printSolution( { {101, 1, 3}, {102, 2, 4}, {103, 4, 6}}); // ["0: 101 103", "1: 102"]
    sol.printSolution( { {101, 1, 3}, {102, 2, 4}, {103, 4, 6}, {104, 5, 8}}); // ["0: 101 103", "1: 102 104"]
    sol.printSolution( { {203, 5, 7}, {201, 1, 5}, {202, 2, 3}}); // ["0: 201 203", "1: 202"]
    sol.printSolution( { {11, 3, 3}, {10, 3, 3}, {12, 3, 4}}); // ["0: 10 11 12"]
    sol.printSolution( { {11, 3, 3} }); // ["0: 11"]
    sol.printSolution( {  }); // []
    sol.printSolution({ {1, 0, 9}, {2, 1, 2}, {3, 5, 6} }); // esperado: ["0: 1", "1: 2 3"]

    
}