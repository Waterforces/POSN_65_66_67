#include<bits/stdc++.h>
using namespace std;
int n,k=1;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int I=0;I<n;I++) {
        int x=0;
        string s;
        cin >> s;
        if(s.size()<16) break ;
        for(int i=0;i<s.size();i+=2) {
            if(k==1) {
                if(s[i]=='1' && s[i+1]=='1') {
                    x=x | 1 << 8-((i+1)/2+(i+1)%2);
                    k=2;
                }
            }
            else if(k==2) {
                if(s[i]=='1' && s[i+1]=='0') k=3;
                else {
                    x=x | 1 << 8-((i+1)/2+(i+1)%2);
                    k=4;
                }
            }
            else if(k==3) {
                if(s[i]=='0' && s[i+1]=='0') {
                    x=x | 1 << 8-((i+1)/2+(i+1)%2);
                    k=2;
                }
                else k=1;
            }
            else {
                if(s[i]=='1' && s[i+1]=='0') x=x | 1 << 8-((i+1)/2+(i+1)%2);
                else k=3;
            }
        }
        cout << char(x);
    }
}
