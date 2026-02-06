#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1005][10005],dp[1005][1005],_max;

int main() {
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(i-k<=0 || j-k<=0) continue ;
            _max=max(_max,dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]);
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) cout << dp[i][j] << " "; cout << endl;
    }
    cout << _max;
}