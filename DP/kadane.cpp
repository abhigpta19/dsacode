#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
  cin>>a[i];
  
  int ans=INT_MIN;
  vector<int> dp(n,0);
  for(int i=0;i<n;i++)
  {
    if(i==0)
    {
      dp[0]=a[0];
      ans=max(ans,a[0]);
      continue;
    }
    
    dp[i]=max(0,dp[i-1])+a[i];
    ans=max(ans,dp[i]);
  }
  cout<<ans;
  return 0;
}