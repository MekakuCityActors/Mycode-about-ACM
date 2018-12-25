/**************************************************************
    Problem: 1010
    User: MekakuCityActors
    Language: C++
    Result: Accepted
    Time:180 ms
    Memory:2852 kb
****************************************************************/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<map>
#include<string>
#include<bitset>
#include<cmath>
using namespace std;
typedef long long ll;
ll dp[50005],qwq[50005];
ll sum[50005],s[50005];
ll n,L;
ll slope(int x,int y){
    return (dp[y]-dp[x]+sum[y]*sum[y]-sum[x]*sum[x]+2*(L+1)*(sum[y]-sum[x]))/(2.0*(sum[y]-sum[x]));
}
int main(){
  //freopen("in.txt","r",stdin);
    scanf("%lld%lld",&n,&L);
    for(int i=1;i<=n;i++){
        scanf("%lld",&qwq[i]);
        sum[i]=sum[i-1]+qwq[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i]+i;
    }
    int l=1;
    int r=1;
    s[1]=0;
    for(int i=1;i<=n;i++){
        while(l<r&&slope(s[l],s[l+1])<=sum[i]){
            l++;
        }
        dp[i]=dp[s[l]]+(sum[i]-sum[s[l]]-(L+1))*(sum[i]-sum[s[l]]-(L+1));
        while(r>l&&slope(s[r],i)<slope(s[r-1],s[r])){
            r--;
        }
        s[++r]=i;
    }
    cout << dp[n] << endl;
    return 0;
}
﻿
