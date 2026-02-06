#include<bits/stdc++.h>
using namespace std;
int n,a[2005],b[2005],ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n ;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++) ans+=abs(a[i]-b[i]);
    cout << ans;
}