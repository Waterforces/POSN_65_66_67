#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int n,m,cou;
char s[N][N];
queue<pair<int,int> > q;

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> s[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(s[i][j]=='0') continue ;
            cou++;
            q.push({i,j});
            while(!q.empty()) {
                auto [x,y] = q.front(); q.pop();
                if(x<0 || y<0 || x>=n || y>=m || s[x][y]=='0') continue ;
                s[x][y]='0';
                q.push({x,y+1});
                q.push({x,y-1});
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x+1,y+1});
                q.push({x+1,y-1});
                q.push({x-1,y+1});
                q.push({x-1,y-1});
            }
        }
    }
    cout << cou;
}