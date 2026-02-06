#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2,k,ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s1 >> s2 >> k;
    for(int i=0;i<m;i++) {
        char t=k[i];
        for(int j=0;j<n;j++) {
            char ch[3]={t,s1[j],s2[j]};
            sort(ch,ch+3);
            t=ch[1];
        } 
        ans+=t;
    }
    cout << ans;
}