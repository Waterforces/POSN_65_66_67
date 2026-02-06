#include<bits/stdc++.h>
using namespace std;
int n,m,a[10],idx[9]={0,1,2,3,4,5,6,7,8};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int ban;
        cin >> ban;
        a[ban]=1;
    }
    do {
        if(a[idx[1]]==1) continue ;
        for(int i=1;i<=n;i++) cout << idx[i] << " ";
        cout << endl;
    }
    while(next_permutation(idx+1,idx+(n+1)));
}