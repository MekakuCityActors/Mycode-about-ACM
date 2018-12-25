/**************************************************************
    Problem: 1026
    User: MekakuCityActors
    Language: C++
    Result: Accepted
    Time:68 ms
    Memory:1292 kb
****************************************************************/
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;
ll dp[20][12][2];
int nums[20];
int tots=0;
int orz[22];
int top=0;
ll DP(int pos,int limit,int num,int m){
    if(pos==0){
            return 1;
    }
    if(num>=0&&dp[pos][num][m]&&!limit){
        return dp[pos][num][m];
    }
    int maxx=(limit)?nums[pos]:9;
    ll sum=0;
    for(int i=0;i<=maxx;i++){
        if(abs(i-num)>=2||m==0){
            orz[tots++]=i;
            sum+=DP(pos-1,limit&&(i==maxx),i,m||i!=0);
            tots--;
        }
    }
    if(!limit){
        dp[pos][num][m]=sum;
    }
    return sum;
}
ll sol(ll x){
    int tot=0;
    top=0;
    memset(dp,0,sizeof(dp));
    while(x){
        nums[++tot]=x%10;
        x/=10;
    }
    return DP(tot,1,-2,0);
}
int main() {
    ll a,b;
    cin>>a>>b;
    printf("%lld\n",sol(b)-sol(a-1));
    return 0;
}
