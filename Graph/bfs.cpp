#include <bits/stdc++.h>
using namespace std;
int bfs(int src,int dest,int n,vector<int> adj[])
{
  queue<int> q;
  vector<int> dist(n+1,0);
  vector<int> vis(n+1,0);
  
  q.push(src);
  vis[src]=1;
  
  while(!q.empty())
  {
    int fn = q.front();
    q.pop();
    
    for(auto x : adj[fn])
    {
      if(!vis[x])
      {
        q.push(x);
        vis[x]=1;
        dist[x]=dist[fn]+1;
      }
    }
  }
  return dist[dest];
}
int main() 
{
  int n,m;
  cin>>n>>m;
  
  vector<int> adj[n+1];
  
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  int src,dest;
  cin>>src>>dest;
  
  cout<<bfs(src,dest,n,adj);
  return 0;

}