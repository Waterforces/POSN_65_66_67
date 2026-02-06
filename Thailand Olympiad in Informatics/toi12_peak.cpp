#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N = 5e6+5;
int n,k,a[N];
vector<int> ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) {
        if(a[i]>a[i-1] && a[i]>a[i+1]) ans.push_back(a[i]);
    }
    sort(ans.begin(),ans.end());
    // for(auto x: ans) cout << x << " "; cout << endl;
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    // for(auto x: ans) cout << x << " "; cout << endl;
    if(ans.size()==0) cout << -1;
    else if(ans.size()>=k) {
        for(int i=ans.size()-1;i>=0 && k--;i--) cout << ans[i] << endl;
    }
    else {
        for(auto x: ans) cout << x << endl;
    }
}