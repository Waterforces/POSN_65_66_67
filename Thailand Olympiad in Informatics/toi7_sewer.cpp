#include<bits/stdc++.h>
using namespace std;
int n,m,ansx,ansy,ans=INT_MAX,dist[105][105];
bool visited[105][105];
char s[105][105];
queue<tuple<int,int,int> > q;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> s[i][j];
            dist[i][j]=INT_MAX;
        }
    }
    q.push({1,1,1});
    while(!q.empty()) {
        auto [x,y,d] = q.front(); q.pop();
        // cout << x << " " << y << " " << d << endl;
        if(visited[x][y] && dist[x][y]==d && ans>d) {
            ans=d;
            ansx=x;
            ansy=y;
        }
        dist[x][y]=min(dist[x][y],d);
        visited[x][y]=1;
        if(s[x][y]=='B' || s[x][y]=='R') q.push({x,y+1,d+1});
        if(s[x][y]=='B' || s[x][y]=='D') q.push({x+1,y,d+1});
        if(!visited[x][y-1] && (s[x][y-1]=='B' || s[x][y-1]=='R')) q.push({x,y-1,d+1});
        if(!visited[x-1][y] && (s[x-1][y]=='B' || s[x-1][y]=='D')) q.push({x-1,y,d+1});
    }
    cout << ans << "\n" << ansx << " " << ansy;
}