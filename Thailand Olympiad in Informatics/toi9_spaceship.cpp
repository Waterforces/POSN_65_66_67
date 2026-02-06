#include<bits/stdc++.h>
using namespace std;
int n,sx,sy,sz,M,_min=INT_MAX;
int x[11],y[11],z[11],m[11],k[11],c[11];
bool visited[500];

void dfs(int idx,int X,int Y,int Z,int sm,int sk,int sc,int sum) {
    
    if(sm>=n && sk>=n && sc>=n) {
        _min=min(_min,sum);
        return ;
    }
    for(int i=1;i<=M;i++) {
        if(visited[i]) continue ;
        visited[i]=true ;
        int dist=(x[i]-X)*(x[i]-X)+(y[i]-Y)*(y[i]-Y)+(z[i]-Z)*(z[i]-Z);
        dfs(i,x[i],y[i],z[i],sm+m[i],sk+k[i],sc+c[i],sum+dist);
        visited[i]=false;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> sx >> sy >> sz >> M;
    for(int i=1;i<=M;i++) {
        cin >> x[i] >> y[i] >> z[i] >> m[i] >> k[i] >> c[i];
    }
    dfs(0,sx,sy,sz,0,0,0,0);
    cout << _min;
}