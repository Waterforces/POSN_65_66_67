#include<bits/stdc++.h>
using namespace std;
int n,m,rt;
double mland[11],ans=1e12+5;

void solve(double land[],double cost) {
    for(int i=0;i<n*m;i++) {
        if(land[i]!=-1) {
            double tmp[11]; 
            copy(land,land+(n*m),tmp);
            int x=i/m,y=i%m;
            if(x+1<n && tmp[(x+1)*m+(y)]!=-1) tmp[(x+1)*m+(y)]+=tmp[i]/10;
            if(y+1<m && tmp[(x)*m+(y+1)]!=-1) tmp[(x)*m+(y+1)]+=tmp[i]/10;
            if(x-1>=0 && tmp[(x-1)*m+(y)]!=-1) tmp[(x-1)*m+(y)]+=tmp[i]/10;
            if(y-1>=0 && tmp[(x)*m+(y-1)]!=-1) tmp[(x)*m+(y-1)]+=tmp[i]/10;
            if((x+1<n && y+1<m) && tmp[(x+1)*m+(y+1)]!=-1) tmp[(x+1)*m+(y+1)]+=tmp[i]/10;
            if((x+1<n && y-1>=0) && tmp[(x+1)*m+(y-1)]!=-1) tmp[(x+1)*m+(y-1)]+=tmp[i]/10;
            if((x-1>=0 && y+1<m) && tmp[(x-1)*m+(y+1)]!=-1) tmp[(x-1)*m+(y+1)]+=tmp[i]/10;
            if((x-1>=0 && y-1>=0) && tmp[(x-1)*m+(y-1)]!=-1) tmp[(x-1)*m+(y-1)]+=tmp[i]/10;
            tmp[i]=-1;
            solve(tmp,cost+land[i]);
        }
    }
    bool done=true;
    for(int i=0;i<n*m;i++) {
        if(land[i]!=-1) done=false;
    }
    if(done) ans=min(cost,ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n*m;i++) cin >> mland[i];
    solve(mland,0);
    cout << fixed << setprecision(2) << ans;
}