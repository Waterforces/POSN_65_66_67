#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
deque<int> l,r;
int ansr[200005],ansl[200005];

void display() {
    for(int i=0;i<l.size();i++) {
        cout << ansl[i] << " ";
    }
    cout << endl;
    for(int i=0;i<r.size();i++) {
        cout << ansr[i] << " ";
    }
    cout << endl;
}

void solve() {
    for(int i=0;i<n;i++) {
        int x=r.size();
        if(x==0) {
            r.push_back(a[i]);
            continue ;
        }
        int t=lower_bound(r.begin(),r.end(),a[i])-r.begin();
        if(t>=x) {
            r.push_back(a[i]);
        }
        else {
            r[t]=a[i];
        }
        ansr[i]=t;
        // display();
    }
    for(int i=n-1;i>=0;i--) {
        int x=l.size();
        if(x==0) {
            l.push_back(a[i]);
            continue ;
        }
        int t=lower_bound(l.begin(),l.end(),a[i])-l.begin();
        if(t>=x) {
            l.push_back(a[i]);
        }
        else {
            l[t]=a[i];
        }
        ansl[i]=t;
    }
}

int main() {
    cin >>  n >> m;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    solve();
    // display();
    for(int i=0;i<m;i++) {
        int q;
        cin >> q;
        int _min=min(ansr[q],ansl[q]);
        cout << _min << endl;
    }
