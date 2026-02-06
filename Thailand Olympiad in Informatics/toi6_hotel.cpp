#include<bits/stdc++.h>
using namespace std;
int n,sum;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while(n>0) {
        if(n>=10) {
            sum+=3000;
            n-=15;
        }
        else if(n>=4) {
            sum+=1500;
            n-=5;
        }
        else if(n>=2) {
            sum+=800;
            n-=2;
        }
        else {
            sum+=500;
            n--;
        }
    }
    cout << sum;
}