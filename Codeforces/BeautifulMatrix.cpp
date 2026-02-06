#include<bits/stdc++.h>
using namespace std;
int a[10][10], x, y;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            cin >> a[i][j];
            if(a[i][j] % 2) {
                x = i, y =j;
            }
        }
    }
    cout << abs(x - 3) + abs(y - 3) << endl;
}