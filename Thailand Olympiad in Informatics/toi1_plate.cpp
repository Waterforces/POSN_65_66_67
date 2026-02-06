#include<bits/stdc++.h>
using namespace std;
int n,m,mp[10005];
deque<int> dq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int cl,id;
        cin >> cl >> id;
        mp[id]=cl;
    }
    while(true) {
        char s;
        cin >> s;
        if(s=='X') {
            cout << 0;
            return 0;
        }
        else if(s=='E') {
            int q,ch=-1;
            cin >> q;
            for(int i=0;i<dq.size();i++) {
                if(mp[q]!=mp[dq[i]]) continue ;
                ch=i+1;
            }
            if(ch==-1) dq.push_back(q);
            else dq.insert(dq.begin()+ch,q);
        }
        else {
            cout << dq[0] << "\n";
            dq.pop_front();
        }
    }
}