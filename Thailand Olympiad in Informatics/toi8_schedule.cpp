#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
const int N = 1005;
int n,m,a[N],b[N];
pair<int,int> dp[N][N];

pair<int,int> _sum(pair<int,int> p,int x) {
    if(x+p.S>m) return make_pair(p.F+1,x);
    return make_pair(p.F,x+p.S);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if(i==0 && j==0) dp[i][j]=make_pair(1,0);
            else if(i==0) dp[i][j]=_sum(dp[i][j-1],b[j]);
            else if(j==0) dp[i][j]=_sum(dp[i-1][j],a[i]);
            else {
                pair<int,int> t1=_sum(dp[i-1][j],a[i]),t2=_sum(dp[i][j-1],b[j]);
                dp[i][j]=min(t1,t2);
            }
        }
    }
    cout << dp[n][n].F << endl << dp[n][n].S;
}