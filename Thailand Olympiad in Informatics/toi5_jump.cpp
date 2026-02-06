#include<bits/stdc++.h>
using namespace std;
int n,k,tmp,_max;
long long a[30005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) {
        tmp=a[i]+k+1;
        int idx=lower_bound(a,a+n,tmp)-a;
        _max=max(_max,idx-i-1);
    }
    cout << _max;
}