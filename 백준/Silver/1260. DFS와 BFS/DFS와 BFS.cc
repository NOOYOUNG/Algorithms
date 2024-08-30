#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v){
  visited[v]=true;
  cout<<v<<" ";
  for(int i=0; i<adj[v].size(); i++){
    if(!visited[adj[v][i]]){
      dfs(adj[v][i]);
    }
  }
}

void bfs(int start){
  queue<int> q;
  visited[start]=true;
  q.push(start);

  while(!q.empty()){
    int v=q.front();
    q.pop();
    cout<<v<<" ";
    for(int i=0; i<adj[v].size(); i++){
      if(!visited[adj[v][i]]){
        visited[adj[v][i]]=true;
        q.push(adj[v][i]);
      }
    }
  }
}

int main()
{
  int N, M, V;
  cin>>N>>M>>V;
  
  adj.resize(N+1);
  
  for(int i=0; i<M; i++){
    int v, w;
    cin>>v>>w;
    adj[v].push_back(w);
    adj[w].push_back(v); //양방향 그래프
  }

  for(int i=1; i<=N; i++){
    sort(adj[i].begin(), adj[i].end()); //작은것부터 정렬
  }

  visited.assign(N+1, false);
  dfs(V);
  cout<<endl;

  visited.assign(N+1, false);
  bfs(V);

  return 0;
}