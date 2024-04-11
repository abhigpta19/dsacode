#include <bits/stdc++.h>
using namespace std;
 
vector<long long> tree;
vector<long long> a;
 
void build(long long idx,long long l,long long r)
{
    if(l==r)
    {
        tree[idx]=a[l];
        return;
    }
 
    long long mid=(l+r)/2;
    build(2*idx+1,l,mid);
    build(2*idx+2,mid+1,r);
 
    tree[idx]=(tree[2*idx+1]+tree[2*idx+2]);
}
long long find(long long idx,long long x,long long y,long long l,long long r)
{
    if(x<=l && r<=y)
    return tree[idx];
 
    if(y<l || r<x)
    return 0;
 
    long long mid=(l+r)/2;
    return (find(2*idx+1,x,y,l,mid)+find(2*idx+2,x,y,mid+1,r));
}
int main() 
{
    long long n,q;
    cin>>n>>q;
 
    tree.resize(4*n,0);
    a.resize(n);
 
    for(long long i=0;i<n;i++)
    cin>>a[i];
 
    build(0,0,n-1);
 
 
    while(q--)
    {
        long long x,y;
        cin>>x>>y;
 
        cout<<find(0,x-1,y-1,0,n-1)<<endl;
    }
  return 0;
}