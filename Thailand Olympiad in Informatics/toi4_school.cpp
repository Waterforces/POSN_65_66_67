#include<bits/stdc++.h>
using namespace std;
int n,m,dp[100][100],p[100][100],area,cou=INT_MAX,c;
char s[100][100];
bool visited[1000];

void colour(int x,int y,int col) {
    if(x<=0 || y<=0 || x>n || y>m || s[x][y]!='P' || p[x][y]!=0) return ;
    p[x][y]=col;
    colour(x,y+1,col);
    colour(x,y-1,col);
    colour(x+1,y,col);
    colour(x-1,y,col);
}

void sol(int x,int y) {
    for(int i=1;i<=1000;i++) visited[i]=false ;
    for(int i=x-area+1;i<=x;i++) {
        for(int j=y-area+1;j<=y;j++) {
            if(p[i][j]>0 && !visited[p[i][j]]) {
                c++;
                visited[p[i][j]]=true ;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> s[i][j];
        }
    }
    for(int i=1,col=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s[i][j]=='P' && p[i][j]==0) colour(i,j,col++);
            if(s[i-1][j]=='T' || s[i][j-1]=='T' || s[i-1][j-1]=='T' || s[i][j]=='T' || i==1 || j==1) {
                dp[i][j]=1;
                continue ;
            }
            dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            area=max(area,dp[i][j]);
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(dp[i][j]!=area) continue ;
            c=0;
            sol(i,j);
            cou=min(cou,c);
        }
    }
    if(cou==INT_MAX) cou=0;
    cout << area*area << " " << cou;
}