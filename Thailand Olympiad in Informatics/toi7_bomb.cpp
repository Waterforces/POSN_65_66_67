#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ch=-1;
vector<pair<ll,ll> > v;

bool cmp(pair<ll,ll> a,pair<ll,ll> b) {
    auto [x1,y1] =a;
    auto [x2,y2] =b;
    if(x1==x2) return y1<y2;
    return x1>x2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(ll i=0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto [x,y] : v) {
        if(ch<=y) {
            cout << x << " " << y << "\n";
            ch=y;
        }
    }
}