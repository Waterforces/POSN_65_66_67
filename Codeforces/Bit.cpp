#include<bits/stdc++.h>
using namespace std;
int n, cnt;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s == "++X" || s == "X++") cnt++;
        else cnt--;
    }
    cout << cnt;
}