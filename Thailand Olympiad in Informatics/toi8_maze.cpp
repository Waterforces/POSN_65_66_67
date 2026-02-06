#include<bits/stdc++.h>
using namespace std;
int n,m,rs,cs,re,ce,g[200][200],ds[200][200],de[200][200],ans=INT_MAX,cou;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool visited[2][200][200];
queue<tuple<int,int,int> > q; 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> rs >> cs >> re >> ce;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> g[i][j];
        }
    }
    q.push({rs,cs,1});
    visited[0][rs][cs]=1;
    
    while(!q.empty()) {
        auto [x,y,d] = q.front(); q.pop();
        // cout << x << " " << y << " " << d << endl;
        // if(x<=0 || y<=0 || x>n || y>m || visited[0][x][y]) continue ;
        // visited[0][x][y]=1;
        // if(g[x][y]==0) {
        //     ds[x][y]=d;
        //     continue ;
        // }
        // ds[x][y]=d;
        for(int i=0;i<4;i++) {
            if(!visited[0][x+dx[i]][y+dy[i]] && (x+dx[i]>0 && x+dx[i]<=n) && (y+dy[i]>0 && y+dy[i]<=m)) {
                if(g[x+dx[i]][y+dy[i]]==0) ds[x+dx[i]][y+dy[i]]=d+1;
                else q.push({x+dx[i],y+dy[i],d+1});
                visited[0][x+dx[i]][y+dy[i]]=1;
            } 
        }
    }
    q.push({re,ce,1});
    visited[1][re][ce]=1;
    while(!q.empty()) {
        auto [x,y,d] = q.front(); q.pop();
        // cout << x << " " << y << " " << d << endl;
        // if(x<=0 || y<=0 || x>n || y>m || visited[1][x][y]) continue ;
        // visited[1][x][y]=1;
        // if(g[x][y]==0) {
        //     de[x][y]=d;
        //     continue ;
        // }
        // de[x][y]=d;
        for(int i=0;i<4;i++) {
            if(!visited[1][x+dx[i]][y+dy[i]] && (x+dx[i]>0 && x+dx[i]<=n) && (y+dy[i]>0 && y+dy[i]<=m)) {
                if(g[x+dx[i]][y+dy[i]]==0) de[x+dx[i]][y+dy[i]]=d+1;
                else q.push({x+dx[i],y+dy[i],d+1});
                visited[1][x+dx[i]][y+dy[i]]=1;
            } 
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(g[i][j]==1 || ds[i][j]==0 || de[i][j]==0) continue ;
            ans=min(ans,ds[i][j]+de[i][j]);
            cou++;
        }
    }
    cout << cou << endl << ans-1;
}