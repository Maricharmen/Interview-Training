/*
vector<strings> children = {"Viserys", "Alicent", "Corlys", "Aemond", "Daemon", "Crispin"};
vector<pair<string, string>> relations = {{"Daemon", "Aemond"}, {"Crispin", "Viserys"}, {"Daemon", "Alicent"}};
map<string, bool> visited;
map<string, set<string>> adjlist;

void build_adjlist(){
  for(auto relation: relations){
    adjlist[relation.first].insert(relation.second);
    adjlist[relation.second].insert(relation.first);
  }
}


bool bfs(string source){
  
  queue<string> traversal;
  queue.push(source);
  visited[source] = true;
  
  while(!traversal.empty()){
    auto curr = traversal.top();
    traversal.pop();
    for(auto adj: relations[curr]){
      if(visited.count(adj)){
        if(visited[adj] == visited[curr]){
          return false;
        }
      } else {
        visited[adj] = !visited[curr];
      }
      
    }
  }
  
  return true;
}
*/