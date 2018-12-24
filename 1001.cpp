/**************************************************************
    Problem: 1001
    User: MekakuCityActors
    Language: C++
    Result: Accepted
    Time:940 ms
    Memory:143480 kb
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
struct edge{
    int x;
    int y;
    int val;
    int nex;
}e[6000005];
int cnt,head[6200005],dist[6200005],n,m;
void adde(int X,int Y,int Z){
    e[cnt].x=X;
    e[cnt].y=Y;
    e[cnt].val=Z;
    e[cnt].nex=head[X];
    head[X]=cnt++;
}
struct pot{
    int x;
    int val;
    bool operator<(const struct pot &aa)const{
        return val>aa.val;
    }
};
void dij(){
    memset(dist,0x3f3f3f3f,sizeof(dist));
    dist[1]=0;
    priority_queue<struct pot>pq;
    struct pot p0;
    p0.x=1;
    p0.val=0;
    pq.push(p0);
    while(!pq.empty()){
        struct pot b0=pq.top();pq.pop();
        if(b0.x==2*(n-1)*(m-1)+2)break;
        if(dist[b0.x]<b0.val)continue;
        for(int i=head[b0.x];i!=-1;i=e[i].nex){
            int v=e[i].y;
            if(dist[v]>dist[b0.x]+e[i].val){
                dist[v]=dist[b0.x]+e[i].val;
                struct pot c0;
                c0.x=v;
                c0.val=dist[v];
                pq.push(c0);
            }
        }
    }
}
int main(){
   //freopen("in.txt","r",stdin);
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            int a;
            scanf("%d",&a);
            int x=2*(n-1)*(m-1)+2-2*(m-1)*i+j*2;
            if(i==0)x=2*(n-1)*(m-1)+2;
            int y=2*(n-1)*(m-1)+2-2*(m-1)*i+j*2-2*m+3;
            if(i==n-1)y=1;
            adde(x,y,a);
            adde(y,x,a);
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<m;j++){
            int a;
            scanf("%d",&a);
            int x=2*(n-1)*(m-1)+2-2*(m-1)*i+j*2;
            if(j==m-1)x=2*(n-1)*(m-1)+2;
            int y=2*(n-1)*(m-1)+2-2*(m-1)*i+j*2-1;
            if(j==0)y=1;
            adde(x,y,a);
            adde(y,x,a);
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<m-1;j++){
            int a;
            scanf("%d",&a);
            int x=2*(n-1)*(m-1)+2-2*(m-1)*i+j*2;
            int y=x+1;
            adde(x,y,a);
            adde(y,x,a);
        }
    }
    if(n==1&&m==1){
        printf("0\n");
    }
    else{
        dij();
        printf("%d\n",dist[2*(n-1)*(m-1)+2]);
    }
    return 0;
}
