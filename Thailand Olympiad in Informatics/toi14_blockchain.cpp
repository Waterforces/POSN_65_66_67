#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int T,Q;
map<vector<pair<int,int> >, int> mp;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T >> Q;
    while(T--) {
        int n;
        cin >> n;
        vector<pair<int,int> > v;
        for(int i=1;i<n;i++) {
            int a,b;
            cin >> a >> b;
            if(a<b) swap(a,b);
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(),v.end());
        mp[v]++;        
    }
    while(Q--) {
        int n;
        cin >> n;
        vector<pair<int,int> > v;
        for(int i=1;i<n;i++) {
            int a,b;
            cin >> a >> b;
            if(a<b) swap(a,b);
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(),v.end());
        cout << mp[v] << endl;
    }
}