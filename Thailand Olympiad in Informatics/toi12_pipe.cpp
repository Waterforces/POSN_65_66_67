#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 15e3+5;
ll n,k,sum,dist[N];
bool visited[N];
pair<ll,ll> p[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(ll i=1;i<=n;i++) {
        cin >> p[i].F >> p[i].S;
        dist[i]=LLONG_MAX;
    }
    dist[1]=0;
    ll tmp=1;
    for(int i=1;i<n;i++) {
        visited[tmp]=1;
        ll _min=LLONG_MAX,idx;
        for(int j=1;j<=n;j++) {
            if(visited[j]) continue ;
            dist[j]=min(dist[j],abs(p[tmp].F-p[j].F)+abs(p[tmp].S-p[j].S));
            // cout << j << " " << dist[j] << endl;
            if(_min>dist[j]) {
                _min=dist[j];
                idx=j;
            }
        }
        tmp=idx;
    }
    sort(dist+1,dist+n+1);
    for(ll i=1;i<=n-k+1;i++) sum+=dist[i];
    // for(ll i=1;i<=n;i++) cout << i << " " << dist[i] << endl;
    cout << sum;
}