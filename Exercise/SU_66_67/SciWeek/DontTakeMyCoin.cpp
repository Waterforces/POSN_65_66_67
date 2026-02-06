#include<bits/stdc++.h>
using namespace std;
double coin[3],box[6],cou[6],ans[3],_max;
int a[3];

int main() {
    for(int i=0;i<3;i++) cin >> coin[i];
    for(int i=0;i<3;i++) {
        cin >> a[i];
        cou[a[i]]++;
    }
    box[1]=box[2]=coin[0]/2;
    box[3]=box[4]=coin[1]/2;
    box[5]=coin[2];
    for(int i=0;i<3;i++) {
        if(cou[a[i]]!=1) continue ;
        ans[i]=box[a[i]];
        _max=max(_max,ans[i]);
    }
    for(int i=0;i<3;i++) {
        if(ans[i]==_max) cout << "Winner is " << char(i+65) << endl;
    }
}