#include<bits/stdc++.h>
using namespace std;
int n,m,a[105][105],dp[105][105],ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i][j]==0) {
                dp[i][j]=0;
                continue ;
            }
            dp[i][j]=1;
            dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
            ans=max(ans,dp[i][j]);
        }
    }
    cout << ans*ans;
}