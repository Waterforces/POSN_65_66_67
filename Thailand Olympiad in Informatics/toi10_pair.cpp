#include<bits/stdc++.h>
using namespace std;
int n,dp[1005][1005];
char s[1005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int l=n-1;l>=0;l--) {
        for(int r=0;r<n;r++) {
            if(dp[l][r]>0 || l==r || l+1==r) continue ;
            if(s[l]==s[r]) dp[l][r]=dp[l+1][r-1]+1;
            for(int i=l;i<r;i++) dp[l][r]=max(dp[l][r],dp[l][i]+dp[i+1][r]);
            cout << l << " " << r << " " << dp[l][r] << endl;
        }
    }
    cout << dp[0][n-1];
}
/* 
5 0 1
5 1 0
5 2 0
5 3 0
5 4 0
4 0 0
4 1 0
4 2 0
4 3 0
3 0 0
3 1 1
3 2 0
3 5 0
2 0 0
2 1 0
2 4 0
2 5 0
1 0 0
1 3 1
1 4 1
1 5 1
0 2 0
0 3 1
0 4 1
0 5 2
2
*/