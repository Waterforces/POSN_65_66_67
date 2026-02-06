#include<bits/stdc++.h>
using namespace std;
int n, k, cnt, a[105];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    int cmp = a[k - 1];
    for(int i = 0; i < n; i++) {
        if(a[i] > 0 && a[i] >= cmp) cnt++;
    }
    cout << cnt;
}