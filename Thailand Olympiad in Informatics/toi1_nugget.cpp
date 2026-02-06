#include<bits/stdc++.h>
using namespace std;
int n;
set<int> s;

void sol(int x) {
    if(x>n) return ;
    s.insert(x);
    sol(x+6);
    sol(x+9);
    sol(x+20);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    if(n<6) {
        cout << "no";
        return 0;
    } 
    sol(0);
    s.erase(0);
    for(auto x:s) cout << x << "\n";
}