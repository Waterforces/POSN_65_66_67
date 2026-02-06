#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9+7;
ll n,k,d,a[305],qs[305],dp[305][305][10];

ll solve(ll l,ll r,ll level) {
    if(level==1) return 1;
    ll sum=0;
    for(ll i=l;i<r;i++) {
        if(abs((qs[i]-qs[l-1])-(qs[r]-qs[i]))>d) continue ;
        if(dp[l][i][level-1]==-1) dp[l][i][level-1]=solve(l,i,level-1);
        if(dp[i+1][r][level-1]==-1) dp[i+1][r][level-1]=solve(i+1,r,level-1);
        sum+=dp[l][i][level-1]*dp[i+1][r][level-1];
        sum%=MOD;
    }
    return sum%MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> d;
    memset(dp,-1,sizeof(dp));
    for(ll i=1;i<=n;i++) {
        cin >> a[i];
        qs[i]=qs[i-1]+a[i];
    }
    cout << solve(1,n,k);
}