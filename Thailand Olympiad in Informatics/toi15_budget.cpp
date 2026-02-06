#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 5e5+5;
int B,E,Q,sum,h[3005];
vector<pair<int,int> > pack;
vector<tuple<int,int,int> > v;

int dsu(int cur) {
    if(h[cur]==cur) return cur;
    return h[cur]=dsu(h[cur]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> B >> E;
    for(int i=0;i<B;i++) h[i]=i;
    for(int i=0;i<E;i++) {
        int a,b,w,T;
        cin >> a >> b >> w >> T;
        if(T==1) h[dsu(a)]=dsu(b);
        else v.push_back({w,a,b});
    }
    cin >> Q;
    while(Q--) {
        int w,p;
        cin >> w >> p;
        pack.push_back(make_pair(w,p));
    } 
    sort(pack.begin(),pack.end());
    for(int i=pack.size()-2;i>=0;i--) pack[i].second=min(pack[i].second,pack[i+1].second);
    for(auto& [w,a,b]: v) {
        int idx = lower_bound(pack.begin(),pack.end(),make_pair(w,0)) -pack.begin();
        w=pack[idx].second;
    } 
    sort(v.begin(),v.end());
    for(auto [w,a,b]: v) {
        if(dsu(a)==dsu(b)) continue ;
        h[dsu(a)]=dsu(b);
        sum+=w;
    } 
    cout << sum;
}