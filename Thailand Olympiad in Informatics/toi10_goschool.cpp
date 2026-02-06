#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,q,a[100][100],dp[100][100];

int main() {
    cin >> n >> m >> q;
    while(q-->0) {
        ll x,y;
        cin >> x >> y;
        a[x][y]=1;
    }
    dp[1][1]=1;
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            if(a[i][j]==1 || (i==1 && j==1)) continue ;
            dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
    }
    cout << dp[n][m];
}