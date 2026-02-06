#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,q,qs[100005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        ll a;
        cin >> a;
        qs[i]=qs[i-1]+a;
    }
    for(int i=n;i>=1;i--) {
        if(qs[i]<qs[i-1]) qs[i-1]=qs[i]; 
    }
    // for(int i=1;i<=n;i++) cout << qs[i] << " ";
    // cout << endl;
    while(m-->0) {
        cin >> q;
        ll l=1,r=n;
        while(l<r) {
            ll mid=(l+r+1)/2;
            if(qs[mid]<=q) l=mid;
            else r=mid-1;
        }
        // // cout << q << " " << qs[n] << "\n";
        if(qs[l]>q) cout << l-1 << "\n";
        else cout << l << "\n";
    }
}

/*
10 30 45 75 135 
10 20 20 50 110 
-46 -46 -46 -46 -46 -46 -46 -6 4 35 
*/