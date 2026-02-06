#include<bits/stdc++.h>
using namespace std;
string s;
int n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    int spin[]={(n/100)-1,(n/10)%10-1,n%10-1};
    for(int i=0;i<s.size();i++) {
        int tmp=int(s[i]-'0')-1;
        for(int j=0;j<3;j++) {
            tmp=((tmp+spin[j])%9);
            if(j==0) spin[j]=(spin[j]+(n/100))%9;
            else if(j==2) spin[j]=(spin[j]+(n%10))%9;
            else if(--spin[j]<0) spin[j]=8;
        }
        cout << tmp+1;
    }
}
