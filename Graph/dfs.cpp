#include <bits/stdc++.h>
using namespace std;
int ans;
int dfs(int src,int par,vector<int> adj[],vector<int> &profit)
{
  int temp = profit[src];
  for(auto x: adj[src])
  {
    if(x!=par)
    temp += dfs(x,src,adj,profit);
  }
  ans=max(ans,temp);
  return temp;
}
int main() {

  int n;
  cin>>n;
  
  vector<int> adj[n+1];
  for(int i=2;i<=n;i++)
  {
    int x;
    cin>>x;
    
    adj[x].push_back(i);
    adj[i].push_back(x);
  }
  
  vector<int> profit(n+1);
  for(int i=1;i<=n;i++)
  cin>>profit[i];
  
  ans=INT_MIN;
  dfs(1,0,adj,profit);
  cout<<ans;
  
  return 0;

}