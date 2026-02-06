#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
ll val[505][505],items[505][505];

void _setup() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j) val[i][j]=2*i;
            else val[i][j]=val[i][0]+val[j][0];
            items[i][j]=2;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        int a;
        cin >> a;
        val[i][0]=a;
    }
    _setup();
    for(int i=1;i<=m;i++) {
        int a,b,cost;
        cin >> a >> b >> cost;
        val[a][b]=cost;
        val[b][a]=cost;
    }
    for(int l=1;l<=n;l++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(val[i][l]==INT_MAX || val[l][j]==INT_MAX) continue ;
                if(val[i][j]<val[i][l]+val[l][j]) continue ;
                val[i][j]=val[i][l]+val[l][j];
                items[i][j]=items[i][l]+items[l][j];
            }
        }
    }
    for(int i=1;i<=k;i++) {
        int a,b;
        cin >> a >> b;
        cout << val[a][b] << " " << items[a][b] << "\n";
    }
}