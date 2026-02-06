#include<bits/stdc++.h>
using namespace std;
int n,m,ch[2];
vector<int> v,ans;

int main() {
    cin >> n >> m;
    if(n<0 || m<0 || n>m) {
        cout << "Error";
        return 0;
    }
    v.push_back(0);
    v.push_back(1);
    while(true) {
        int vs=v.size();
        int last=v[vs-1];
        if(last>m) break;
        v.push_back(v[vs-1]+v[vs-2]);
    }
    for(int i=0;i<v.size();i++) {
        if(v[i]>m) break ;
        if(v[i]>=n) ans.push_back(v[i]);
    }
    if(ans.size()==0) cout << "Not found";
    else {
        for(auto i: ans) cout << i << " ";
    }
}