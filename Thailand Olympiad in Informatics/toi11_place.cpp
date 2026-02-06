#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,h[20000],ans;
tuple<int,int,int> t[1000005];

int dsu(int cur) {
    if(h[cur]==cur) return cur;
    return h[cur]=dsu(h[cur]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) h[i]=i;
    for(int i=0;i<m;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        t[i]={w,a,b};
    }
    sort(t,t+m,greater<tuple<int,int,int> >());
    for(auto [w,a,b]: t) {
        if(dsu(h[a])==dsu(h[b])) continue ;
        ans+=w-1;
        h[dsu(h[a])]=dsu(h[b]);
    }
    cout << ans;
}