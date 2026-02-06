#include<bits/stdc++.h>     //MST-Kruskal
using namespace std;
typedef struct edge {
    int a,b,w;
    bool operator<(const edge &b) const {
        return w>b.w;
    }
} edge;
edge x[1000005];
int n,m,h[2505],start,stop,people;

int dsu(int cur) {
    if(h[cur]==cur) return cur;
    return h[cur]=dsu(h[cur]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<=2500;i++) h[i]=i;
    for(int i=0;i<m;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        x[i]={a,b,w};
    }
    cin >> start >> stop >> people;
    sort(x,x+m);
    for(int i=0;i<m;i++) {
        auto [a,b,w] = x[i];
        if(h[a]==h[b]) continue ;
        h[dsu(h[a])]=dsu(h[b]);
        if(dsu(h[start])==dsu(h[stop])) {
            cout << (people+w-1)/(w-1);
            return 0;
        }
    }
}

// #include<bits/stdc++.h>      //MST-Prim
// using namespace std;
// vector<pair<int,int> > v[2505];
// int n,m,dist[2505],start,stop,people;
// priority_queue<pair<int,int> > pq;

// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     cin >> n >> m;
//     for(int i=0;i<m;i++) {
//         int a,b,w;
//         cin >> a >> b >> w;
//         v[a].push_back({b,w});
//         v[b].push_back({a,w});
//     }
//     cin >> start >> stop >> people;
//     dist[start]=1e6+5;
//     pq.push({dist[start],start});
//     while(!pq.empty()) {
//         auto [dis,cur] = pq.top();
//         pq.pop();
//         for(auto [next,ndis] : v[cur]) {
//             if(dist[next]>=min(ndis,dis)) continue ;
//             dist[next]=min(ndis,dis);
//             pq.push({min(ndis,dis),next});
//         }
//     }
//     cout << (people+dist[stop]-2)/(dist[stop]-1);
// }