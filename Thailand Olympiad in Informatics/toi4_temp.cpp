#include<bits/stdc++.h>
using namespace std;
int n,sx,sy,temp[30][30];

int dfs(int x,int y,int old) {
    if(x<=0 || y<=0 || x>n || y>n || temp[x][y]==100 || temp[x][y]<=old) return old;
    return max(dfs(x,y+1,temp[x][y]),max(dfs(x,y-1,temp[x][y]),max(dfs(x+1,y,temp[x][y]),dfs(x-1,y,temp[x][y]))));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cin >> sy >> sx;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> temp[i][j];
        }
    }
    cout << dfs(sx,sy,-10);
}