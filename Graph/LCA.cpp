#include <bits/stdc++.h>
using namespace std;
void dfs(int src,int par,int d,vector<int> adj[],vector<vector<int>> &kanc,vector<int> &depth)
{
    depth[src]=d;
    kanc[src][0]=par;
    for(auto child : adj[src])
    {
        if(child!=par)
        {
            dfs(child,src,d+1,adj,kanc,depth);
        }
    }
}
void sparsetable(int n,vector<vector<int>> &kanc)
{
    for(int j=1;j<20;j++)
    {
        for(int i=1;i<=n;i++)
        {
            kanc[i][j]=kanc[kanc[i][j-1]][j-1];
        }
    }
}
int kancesstor(int src,int k,vector<vector<int>> &kanc)
{
    int jump=19;
    while(k!=0)
    {
        int steps = (1<<jump);
        int newsrc = kanc[src][jump];
        jump--;

        if(steps>k)
        continue;

        k-=steps;
        src=newsrc;
    }
    return src;
}
int LCA(int a,int b,int n,vector<int> adj[],vector<int> &depth,vector<vector<int>> &kanc)
{
    int diff = abs(depth[a]-depth[b]);

    if(depth[a]>depth[b])
    a=kancesstor(a,diff,kanc);
    else
    b=kancesstor(b,diff,kanc);

    if(a==b)
    return a;
    
    int jump=19;
    while(jump)
    {
        int u = kanc[a][jump];
        int v = kanc[b][jump];

        jump--;

        if(u==v)
        continue;

        a=u;
        b=v;
    }

    return kanc[a][0];
}
int main() 
{
  int n;
  cin>>n;
  
  vector<int> adj[n+1];
  for(int i=2;i<=n;i++)
  {
    int u,v;
    cin>>u>>v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<int>> kanc(n+1,vector<int>(20,0));
  vector<int> depth(n+1,0);

  dfs(1,0,0,adj,kanc,depth);

  sparsetable(n,kanc);

  int a,b;
  cin>>a>>b;

  cout<<LCA(a,b,n,adj,depth,kanc);
  
  return 0;

}