#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
const int N = 5e5;
ll n,a[N+5],ans=1,fac[N+5];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fac[0]=1;   for(int i=1;i<=N;i++) fac[i]=(fac[i-1]*i)%MOD;
    memset(a,-1,sizeof(a));
    cin >> n;
    for(int i=0;i<2*n-1;i++) {
        int q;
        cin >> q;
        a[q]++;
    }
    for(int i=1;i<=n;i++) {
        if(a[i]) ans=(ans*fac[a[i]])%MOD;
    }
    cout << ans;
}