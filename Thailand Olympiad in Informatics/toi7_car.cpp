#include<bits/stdc++.h>
using namespace std;
int n,m,t;
char a[105][105];
int ans[105];

void dfs(int x,int y) {
    if(x==t) {
        for(int i=0;i<t;i++) cout << ans[i] << "\n";
        return ;
    }
    if(a[x+1][y-1]=='0') {
        ans[x]=1;
        dfs(x+1,y-1);
    }
    if(a[x+1][y]=='0') {
        ans[x]=3;
        dfs(x+1,y);
    }
    if(a[x+1][y+1]=='0') {
        ans[x]=2;
        dfs(x+1,y+1);
    }
    
    
}

int main() {
    cin >> m >> n >> t;
    for(int i=1;i<=t;i++) {
        for(int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    dfs(0,n);
    
}