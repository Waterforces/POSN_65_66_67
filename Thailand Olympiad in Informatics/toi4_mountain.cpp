#include<bits/stdc++.h>
using namespace std;
int n,mh,ml,al;
bool b=0;
char s[100][100];
queue<tuple<int,int,int> > q;

void display() {
    for(int i=11-mh;i<=10;i++) {
        for(int j=1;j<al;j++) {
            cout << s[i][j];
        } cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(s,'.',sizeof(s));
    cin >> n;
    for(int I=0;I<n;I++) {
        int l,h;
        cin >> l >> h;
        mh=max(mh,h);
        if(l>ml) {
            ml=l;
            al=ml+(2*h);
        }
        int x=10,y=l;
        for(int i=0;i<h;i++) {
            if(s[x][y] == '\\') {s[x][y]='v'; q.push({x,y,0});}
            else s[x][y] = '/';
            if(s[x][y-1]=='\\' && s[x][y]=='/') {
                q.push({x+1,y-1,1}); 
                // else q.push({x+2,y-1,1});
                q.push({x+1,y,2});
                // else q.push({x+2,y,2});
            }
            if((s[x][y]=='/' && s[x][y+1]=='\\') && (s[x-1][y]!='.' || s[x-1][y+1]!='.')) {
                q.push({x,y,1}); 
                // else q.push({x+1,y,1});
                // if(s[x][y+2]=='.') q.push({x,y+1,2});
                // else q.push({x+1,y+1,2});
            }
            x--; y++;
        }
        x++;
        for(int i=0;i<h;i++) {
            if(s[x][y] == '/') {
                s[x][y]='v'; 
                q.push({x,y,0});
            }
            else s[x][y] = '\\';
            x++; y++;
        }
        while(!q.empty()) {
            auto [i,j,t]=q.front(); q.pop();
            // cout << i << " " << j << " " << s[i][j] << endl;
            if(i>11) continue ;
            if(t==0) {
                q.push({i+1,j-1,1});
                q.push({i+1,j+1,2});
            }
            else if(t==1) {
                s[i][j]='.';
                q.push({i+1,j-1,1});
            }
            else {
                s[i][j]='.';
                q.push({i+1,j+1,2});
            }
        }
    }
    for(int i=1,t;i<=10;i++) {
        for(int j=1;j<=80;j++) {
            if(s[i][j]=='v') continue ;
            else if(s[i][j]=='/' && !b) b=1;
            else if(s[i][j]=='\\' && b && t!=j) {b=0; t=j;}
            else if(s[i][j]=='\\' && t!=j) {j=t; b=1; s[i][j]='X';}
            else if(b) s[i][j]='X';
        }
    }
    display();
}