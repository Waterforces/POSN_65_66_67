#include<bits/stdc++.h>
using namespace std;

int main() {
    for(int I=0;I<5;I++) {
        int n;
        vector<pair<int,int>> v,u; 
        cin >> n;
        int _size=2*(n-1)/2;
        for(int i=0;i<_size;i++) {
            int a,b;
            cin >> a >> b;
            v.push_back({min(a,b),max(a,b)});
        }
        for(int i=0;i<_size;i++) {
            int a,b;
            cin >> a >> b;
            u.push_back({min(a,b),max(a,b)});
        }
        sort(v.begin(),v.end());
        sort(u.begin(),u.end());
        if(v==u) cout << "Y";
        else cout << "N";
    }   
}