#include<bits/stdc++.h>
using namespace std;
int n,maxp,a[50005][100];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        int p,q,r;
        cin >> p >> q >> r;
        maxp=max(maxp,p);
        for(int j=q;j<r+q;j++) a[p][j]=1;
    }
    for(int i=1;i<=maxp;i++) {
        for(int j=1;j<=70;j++) {
            if(a[i][j]) cout << "x";
            else cout << "o";
        }
        cout << "\n";
    }
}