#include <bits/stdc++.h>
using namespace std;

int main() {

  string s,t;
  cin>>s>>t;
  
  int n=s.length();
  int m=t.length();
  
  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(s[i]==t[j])
      {
        dp[i+1][j+1]=dp[i][j]+1;
      }
      else
      {
        dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
      }
    }
  }
  
  string ans="";
  
  int i=n-1,j=m-1;
  while(i>=0 && j>=0)
  {
    if(s[i]==t[j])
    {
      ans=ans+s[i];
      i--;
      j--;
    }
    else
    {
      if(dp[i+1][j+1]==dp[i+1][j])
      j--;
      else
      i--;
    }
  }
  reverse(ans.begin(),ans.end());
  cout<<ans;
  return 0;

}