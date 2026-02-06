#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 4e4+5;
int n,m,h[N];
vector<pair<int,int> > v(n);

int dsu(int cur) {
    if(h[cur]==cur) return cur;
    return h[cur]=dsu(h[cur]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n*m;i++) h[i]=i; 
    for(int i=0;i<n*m;i++) {
        int a,b;
        char s;
        cin >> a >> s >> b;
        if(s=='L') v[a].S=b;
        else v[a].F=b;
    }

}