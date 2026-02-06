#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,q;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s;
    for(int i=1;i<m;i++) {
        int c=0;
        cin >> q;
        for(int j=0;j<n;j++) {
            if(s[j]!=q[j]) c++;
        }
        if(c>=3) {
            cout << s;
            return 0;
        }
        s=q;
    }
    cout << s;
}