#include<bits/stdc++.h>
using namespace std;
int n,a[6];
float cake;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
        cake+=a[1]+(a[2]*0.75)+(a[3]*0.5)+(a[4]*0.25)+(a[5]*0.125);
    }
    cout << ceil(cake);
}