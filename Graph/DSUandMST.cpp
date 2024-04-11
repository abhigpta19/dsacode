#include <bits/stdc++.h>
using namespace std;
int find(int n,vector<int> &parent)
{
  if(parent[n]==n)
  return n;
  
  return parent[n]=find(parent[n],parent);
}
 bool unions(int n1,int n2,vector<int> &size,vector<int> &parent)
 {
   int p1=find(n1,parent);
   int p2=find(n2,parent);
   
   if(p1==p2)
   return 0;
   
   if(size[p1]>size[p2])
   {
     parent[p2]=p1;
     size[p1]+=size[p2];
   }
   else
   {
     parent[p1]=p2;
     size[p2]+=size[p1];
   }
   return 1;
 }
int main() 
{
  int n,m;
  cin>>n>>m;
  
  vector<vector<int>> v(n,vector<int>(3));
  for(int i=0;i<n;i++)
  {
    cin>>v[i][0]>>v[i][1]>>v[i][2];
  }
  vector<vector<int>> vec;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      int cost=abs(v[i][0]-v[j][0])+abs(v[i][1]-v[j][1])+abs(v[i][2]-v[j][2]);
      vec.push_back({cost,i,j});
    }
  }
  
  sort(vec.begin(),vec.end());
  
  vector<int> parent(n+1);
  vector<int> size(n+1);
  
  for(int i=1;i<=n;i++)
  {
    parent[i]=i;
    size[i]=1;
  }
  long long ans=0;
  for(auto x: vec)
  {
    int u=x[1];
    int v=x[2];
    int w=x[0];
    
    if(unions(u,v,size,parent))
    ans+=w*1LL;
  }
  cout<<ans*m;
  return 0;

}