/**************************************************************
    Problem: 1010
    User: MekakuCityActors
    Language: C++
    Result: Accepted
    Time:164 ms
    Memory:2856 kb
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
ll slope(int x,int y){//注意要把斜率写成这个形式（把分母写在函数外面与式子右端的式子相乘）来防止分母为0
    return (dp[y]-dp[x]+sum[y]*sum[y]-sum[x]*sum[x]+2*(L+1)*(sum[y]-sum[x]));
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
        while(l<r&&slope(s[l],s[l+1])<=sum[i]*(2.0*(sum[s[l+1]]-sum[s[l]]))){//把分母写在右端相乘的形式以防止分母为0
            l++;
        }
        dp[i]=dp[s[l]]+(sum[i]-sum[s[l]]-(L+1))*(sum[i]-sum[s[l]]-(L+1));
        while(r>l&&slope(s[r],i)*(2.0*(sum[s[r]]-sum[s[r-1]]))<=slope(s[r-1],s[r])*(2.0*(sum[i]-sum[s[r]]))){//注意弹出的时候要使用<=而不能使用<
            r--;
        }
        s[++r]=i;
    }
    cout << dp[n] << endl;
    return 0;
}
