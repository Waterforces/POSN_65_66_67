#include<bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) {
            if((i & (1<<j))==(1<<j)) continue ;
            int next = (i | (1<<j));
            // cout << i << " " << next << " " << (1<<j) << '\n';
            for(int k=n-1;k>=0;k--) {
                if((i & (1<<k))==(1<<k)) cout << 1;
                else cout << 0;
            }
            cout << " ";
            for(int k=n-1;k>=0;k--) {
                if((next & (1<<k))==(1<<k)) cout << 1;
                else cout << 0;
            }
            cout << "\n";
        }
    }
}