#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N =1e5+5;
int n;
double ans;
pair<int,int> a[N],b[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i].F >> a[i].S;
        b[i]=make_pair(a[i].S,a[i].F);
    }
    sort(a,a+n,greater<pair<int,int> >());
    sort(b,b+n,greater<pair<int,int> >());
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(a[i].F<=b[j].S || b[i].F<=a[j].S) break ;
            ans+=a[i].F+b[j].S;
        }
    }
    cout << ans;
}