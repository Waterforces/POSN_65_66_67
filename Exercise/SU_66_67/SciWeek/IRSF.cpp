#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,a;

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a;
        int vs=v.size();
        if(v.size()==0) v.push_back(a);
        else {
            int idx=lower_bound(v.begin(),v.end(),a)-v.begin();
            if(idx>=vs) v.push_back(a);
            else v[idx]=a;
        }
    }
    cout << v.size();
}