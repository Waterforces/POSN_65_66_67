#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N = 1e5+5;
int n,k,t,cnt,ans,tmp;
bool visited[N];
vector<int> v[N],lvl[10005];

void dfs(int cur) {
    if(visited[cur]) {
        if(tmp==cur) cnt+=t;
        return ;
    }
    visited[cur]=1;
    cnt++;
    for(auto prev: v[cur]) dfs(prev);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> t;
    for(int i=1;i<=n;i++) {
        int Q,L;
        cin >> L >> Q;
        lvl[L].push_back(i);
        while(Q--) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    for(int i=1;i<=k;i++) {
        ans=i;
        for(auto j: lvl[i]) {
            tmp=j;
            if(!visited[j]) dfs(j);
        }
        if(cnt>t) {
            if(i==1) cout << -1;
            else cout << ans-1;
            return 0;
        }
    }
    cout << k;
}   