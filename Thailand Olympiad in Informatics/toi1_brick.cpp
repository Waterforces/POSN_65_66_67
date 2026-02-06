#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[50][50];

void display() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout << s[i][j];
        cout << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> s[i][j];
        } 
    }
    for(int i=0;i<m;i++) s[n][i]='O';
    for(int i=0;i<m;i++) {
        int a;
        cin >> a;
        for(int j=0;j<a;j++) {
            int h=0;
            while(true) {
                if(s[h][i]=='O' || s[h][i]=='#') {
                    if(h>0) s[h-1][i]='#';
                    break ;
                }
                h++;
            }
        }
    }
    display();
}