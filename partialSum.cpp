#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;//take array size and queries
    ll s[n]={};
    for(int i=0;i<n;i++) cin>>s[i];//take the input array delete it if not needed

  
    ll par[n+1]={};//partial sum array
    while(q--)
    {
        ll l,r,val;cin>>l>>r>>val;//l -> the start position, r-> end position, value
        --l,--r;
        par[l]+=val;
        par[r+1]-=val;
    }
  
    for(int i=1;i<n;i++) par[i]+=par[i-1]; //done the partial sum on the array
  
    for(int i=0;i<n;i++) cout<<s[i]+par[i]<<' '; //print the new values of the array s w/ the update after perform partail sum;

  return 0;
}
