#include<bits/stdc++.h>
using namespace std;
int n,m,s;
string ans,but[11]={"*","-","CAB","FDE","IGH","LJK","OMN","SPQR","VTU","ZWXY"};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s >> m;
    if((s==7 || s==9) && m>0) ans+=but[s][m%4];
    else if(s!=1 && m>0) ans+=but[s][m%3];
    for(int I=1;I<n;I++) {
        int h,v;
        cin >> h >> v >> m;
        if(m<=0) continue ;
        s+=(h+(3*v));
        if(s==1 && m>0) {
            while(!ans.empty() && m>0) {
                ans.pop_back(); m--;
            }
        }
        else if((s==7 || s==9) && m>0) ans+=but[s][m%4];
        else if(s!=1 && m>0) ans+=but[s][m%3];
    }
    if(ans.size()==0) cout << "null";
    else cout << ans;
}