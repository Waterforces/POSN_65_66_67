#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N = 1e6+5;
ll n,m,a[N],l,r=1e9;

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        r=min(r,a[i]);
    }
    r*=m;
    while(l<r) {
        ll mid = (l+r)/2,sum=0;
        for(int i=0;i<n;i++) sum+=(mid/a[i]);
        if(sum>=m) r=mid;
        else l=mid+1;
        // cout << mid << " " << sum << endl;
    }
    cout << l;
}