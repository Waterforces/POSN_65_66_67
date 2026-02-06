#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;  
    cin >> n;
    for(int i=0;i<n;i++) {
        int dice[7]={0,1,2,3,5,4,6};
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++) {
            if(s[j]=='F') {
                swap(dice[1],dice[2]);
                swap(dice[1],dice[6]);
                swap(dice[1],dice[4]);
            }
            else if(s[j]=='B') {
                swap(dice[1],dice[4]);
                swap(dice[1],dice[6]);
                swap(dice[1],dice[2]);
            }
            else if(s[j]=='L') {
                swap(dice[1],dice[3]);
                swap(dice[1],dice[6]);
                swap(dice[1],dice[5]);
            }
            else if(s[j]=='R') {
                swap(dice[1],dice[5]);
                swap(dice[1],dice[6]);
                swap(dice[1],dice[3]);
            }
            else if(s[j]=='C') {
                swap(dice[2],dice[3]);
                swap(dice[2],dice[4]);
                swap(dice[2],dice[5]);
            }
            else {
                swap(dice[2],dice[5]);
                swap(dice[2],dice[4]);
                swap(dice[2],dice[3]);
            }
        }
        cout << dice[2] << " ";
    }
}