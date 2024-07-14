/*
A snowflake graph is generated from two integers x and y, both greater than 1, as follows:

    1. Start with one central vertex.
    2. Connect x new vertices to this central vertex.
    3. Connect y new vertices to each of these x vertices. 
    
    Given a snowflake graph, determine the values of x and y.

    
map<int, int> cubeta;
map<int, int> grados;
vector<pair<int, int>> edges;
int centro;


for(auto it: edges){
  cubeta[it.first]++;
  cubeta[it.second]++;
}

for(auto it: cubeta){
  grados[it.second]++;
}

for(auto it: grados){
  if(it.second) == 1;
  centro = it.first;
}


// grados[1] = xy
// grados[centro] = x
// grados[1]/grados[centro] = y
*/