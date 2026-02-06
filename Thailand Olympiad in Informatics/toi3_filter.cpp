#include<bits/stdc++.h>
using namespace std;
int n,h,w,a,x,qs[3005],sum1,sum0;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> w >> h >> n;
    for(int i=0;i<n;i++) {
        cin >> x >> a;
        qs[x+1]++;
        qs[x+a+1]--;
    }
    for(int i=1;i<=w;i++) qs[i]+=qs[i-1]; 
    for(int i=1;i<=w;i++) {
        if(qs[i]==0) sum0++;
        else if(qs[i]==1) sum1++;
    }
    cout << sum0*h << " " << sum1*h;
}