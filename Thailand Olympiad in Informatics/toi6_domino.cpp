#include<bits/stdc++.h>
using namespace std;
int n,c;
string s[3]={"","--","||"};
vector<int> ans;

void sol(int sum,vector<int> v) {
    if(sum>n) return ;
    if(sum==n) {
        if(c>0) cout << "E\n";
        for(auto x: v) cout << s[x] << "\n";
        c++;
        return ;
    }
    v.push_back(1);
    sol(sum+1,v);
    v.pop_back();
    v.push_back(2);
    sol(sum+2,v);
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    sol(0,ans);
    if(c>1) cout << "E";
}