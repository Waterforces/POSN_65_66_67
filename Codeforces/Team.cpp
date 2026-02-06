#include<bits/stdc++.h>
using namespace std;
int n, cnt;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while(n--) {
        int x = 0, a;
        for(int i = 0; i < 3; i++) {
            cin >> a;
            if(a % 2) x++;
        }
        if(x >= 2) cnt++;
    }
    cout << cnt;
}