#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define F first
#define S second
using namespace std;
int n,k,a;
priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > pq;

int main() {
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        cin >> a;
        while(!pq.empty() && i-pq.top().S>k) pq.pop();
        if(!pq.empty()) a+=pq.top().F;
        pq.push({a,i});
    }
    cout << a;
}