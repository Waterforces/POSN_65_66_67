#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define F first
#define S second
using namespace std;
int n,w,_max,sz=INT_MAX;
vector<int> qs;
deque<pair<int,int> > dq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> w;
    qs.resize(n+5);
    for(int i=1;i<=n;i++) {
        int a;
        cin >> a;
        qs[i]=qs[i-1]+a;
    }
    for(int i=1;i<=n;i++) {
        while(!dq.empty() && qs[i]<=dq.back().F) dq.pop_back();
        while(!dq.empty() && dq.front().S<i-w) dq.pop_front();
        dq.push_back({qs[i],i});
        if(i==dq.front().S) continue ;
        else if(qs[i]-dq.front().F>_max) {
            _max=qs[i]-dq.front().F;
            sz=i-dq.front().S;
        }
        else if(qs[i]-dq.front().F==_max) sz=min(sz,i-dq.front().S); 
    } 
    if(_max==0) cout << "0\n0";
    else cout << _max << endl << sz;
}