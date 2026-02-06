#include<bits/stdc++.h>
using namespace std;
int n,k[6]; // i v x l c

void sol(int x) {
    if(x<=0) return ;
    if(x>=100) {
        k[4]++;
        x-=100;
    }
    else if(x>=90) {
        k[4]++; k[2]++;
        x-=90;
    }    
    else if(x>=50) {
        k[3]++;
        x-=50;
    }
    else if(x>=40) {
        k[3]++; k[2]++;
        x-=40;
    }    
    else if(x>=10) {
        k[2]++;
        x-=10;
    }
    else if(x==9) {
        k[2]++; k[0]++;
        x-=9;
    }
    else if(x>=5) {
        k[1]++;
        x-=5;
    }
    else if(x==4) {
        k[1]++; k[0]++;
        x-=4;
    }
    else {
        k[0]+=x;
        x=0;
    }
    sol(x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        sol(i);
    }
    cout << k[0] << " " << k[1] << " " << k[2] << " " << k[3] << " " << k[4];
}
