#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6;
ll n,m,k,len,a[N+5];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k >> len;
    for(ll i=0;i<n;i++) cin >> a[i];
    while(k--) {
        ll q,ans=0,oldR=0;
        for(ll i=0;i<m;i++) {
            cin >> q;
            ll findL=q-len>0 ? q-len:0,findR=q+len;
            // cout << findL << " " << findR << endl;
            ll l = lower_bound(a,a+n,max(findL,oldR))-a;
            if(l>=n) continue ;
            ll r = upper_bound(a,a+n,findR)-a -1;
            if(r>=n) r=n-1;
            oldR=max(oldR,q+len+1);
            ans+=r-l+1;
            // cout << findL << " " << findR << endl;
            // cout << l << " " << r << endl;
        }
        cout << ans << "\n";
    }
}

/*
4 2 1 300 
300 500 600 900
200 1000

4 2 1 1000 
300 500 600 900
100 1000

6 2 1 4
1 2 3 4 5 6
1 6

4 1 1 300 
300 500 600 900
1500

*/