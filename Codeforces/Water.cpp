#include<bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    if(n % 2 == 0 && n != 2) cout << "YES";
    else cout << "NO";
}