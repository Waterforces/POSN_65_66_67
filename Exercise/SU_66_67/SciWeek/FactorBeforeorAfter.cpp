#include<bits/stdc++.h>
using namespace std;
int n,sum1,sum2,sump;
bool b[50005];

void run() {
    for(int i=2;i<50005;i++) {
        if(b[i]) continue ; 
        for(int j=i+i;j<50005;j+=i) {
            b[j]=true;
        }
    }
}

int main() {
    cin >> n;
    run();
    for(int i=0;i<n;i++) {
        int a,k,ch=0;
        cin >> a >> k;
        // cout << a << " " << k << endl;
        if(k==1) {
            for(int i=2;i<a;i++) {
                if(a%i==0) {
                    sum1+=i; ch=1;
                    cout << i << endl ;
                    break ;
                }
            }
        }
        else if(k==2) {
            for(int i=2;i<a;i++) {
                if(a%i==0) {
                    sum2+=(a/i); ch=1;
                    cout << a/i << endl ;
                    break ;
                }
            }
        }
        if(!ch) {
            sump+=a;
            cout << 0 << endl;
        }

    }
    cout << "total_1 = " << sum1 << endl;
    cout << "total_2 = " << sum2 << endl;
    cout << "total_3 = " << sump << endl; 
}