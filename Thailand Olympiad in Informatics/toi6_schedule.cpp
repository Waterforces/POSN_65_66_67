#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,k,cou;
bool check[N];
vector<tuple<int,int,int> > v;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> m;
    for(int i=1;i<=n;i++) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,1,i});
        v.push_back({b+1,-1,i});
    }
    sort(v.begin(),v.end());
    for(auto [a,b,i]: v) {
        if(b==1 && cou<k) {
            check[i]=true ;
            cou++;
        }
        else if(check[i]) cou--;
    }
    for(int i=0;i<m;i++) {
        int a;
        cin >> a;
        if(check[a]) cout << "Y ";
        else cout << "N ";
    }
}