#include<bits/stdc++.h>
#define t tuple<int,int,int,int>
using namespace std;
int n,m,start,stop,fuel,dp[105][105][3],fuelStation[105],ans=INT_MAX;
vector<pair<int,int> > v[105];
priority_queue<t,vector<t>,greater<t> > pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n ;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=100;j++) dp[i][j][0]=dp[i][j][1]=INT_MAX;
    }
    for(int i=1;i<=n;i++) cin >> fuelStation[i];
    cin >> start >> stop >> fuel;
    cin >> m;
    for(int i=0;i<m;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    pq.push({0,start,0,0});
    while(!pq.empty()) {
        auto [cost,cur,fue,use] = pq.top(); pq.pop();
        if(dp[cur][fue][use]<=cost) continue ;
        // cout << cost << " " << cur << " " << fue << " " << use << "\n";
        dp[cur][fue][use]=cost;
        for(int i=1,k;(i+fue)<=fuel;i++) {
            k=i*fuelStation[cur];
            pq.push({k+cost,cur,i+fue,use});
            if(use!=1) pq.push({cost,cur,i+fue,1});
        }
        for(auto [next,fee]: v[cur]) {
            if(dp[next][fue-fee][use]<=cost || fee>fue) continue ;
            pq.push({cost,next,fue-fee,use});
        }
    }
    // for(int i=1;i<=n;i++) cout << i << " " << dp[i][fuel][0] << " " << dp[i][fuel][1] << "\n";
    if(dp[stop][fuel][0]!=INT_MAX) ans=min(ans,dp[stop][fuel][0]);
    if(dp[stop][fuel][1]!=INT_MAX) ans=min(ans,dp[stop][fuel][1]);
    cout << ans;
}