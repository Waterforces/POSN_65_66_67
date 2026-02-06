#include<bits/stdc++.h>
using namespace std;
int n,st=INT_MAX,en=INT_MIN,a[3005];

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int l,h,r;
        cin >> l >> h >> r;
        st=min(st,l); en=max(en,r);
        for(int j=l;j<r;j++) {
            a[j]=max(a[j],h);
        }
        a[r]=max(a[r],0);
    }
    int k=0;
    for(int i=st;i<=en;i++) {
        if(k!=a[i]) {
            cout << i << " " << a[i] << " ";
            k=a[i];
        }
    }
}