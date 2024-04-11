#include <bits/stdc++.h>
using namespace std;

int main() {

  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    
    int sum=0;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    sum+=a[i];
    }
    
    if(sum%2==1)
    {
      cout<<"NO\n";
      continue;
    }
    sum/=2;
    
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<=sum;j++)
      {
        if(j==0)
        dp[i][j]=1;
        else
        {
          dp[i][j]=dp[i-1][j];
          if(j>=a[i-1])
          dp[i][j]=(dp[i][j] | dp[i-1][j-a[i-1]]);
        }
      }
    }
    if(dp[n][sum])
    cout<<"YES\n";
    else
    cout<<"NO\n";
    
  }
  return 0;

}