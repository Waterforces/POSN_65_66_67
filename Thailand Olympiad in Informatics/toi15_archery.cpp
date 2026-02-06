#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 5e5+5;
ll n,qs[N][2],MIN=2e18,_min=2e18,po=2e18;
pair<ll,ll> p[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> p[i].S;
        MIN=min(MIN,p[i].S);
    }
    for(int i=1;i<=n;i++) cin >> p[i].F;
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++) qs[i][0]=qs[i-1][0]+p[i].F;
    for(int i=1;i<=n;i++) qs[i][1]=qs[i-1][1]+p[i].S;
    for(int i=1;i<=n;i++) {
        if(MIN<p[i].F) continue ;
        ll up=qs[n][0]-qs[i][0]-((n-i)*p[i].F),down=qs[i-1][1]-((i-1)*p[i].F)+qs[i-1][0];
        if(_min>=up+down) {
            if(_min==up+down) po=min(po,p[i].F);
            else {
                _min=up+down;
                po=p[i].F;
            } 
        }
    }
    cout << po << " " << _min;
}
