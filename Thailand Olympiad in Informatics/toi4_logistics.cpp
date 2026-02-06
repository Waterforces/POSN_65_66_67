#include<bits/stdc++.h>
using namespace std;
int n,tmp;
float ans;
bool visited[31][31],ch=1;
vector<int> _next[31],w[31][31];
queue<pair<int,int> > q;
queue<tuple<char,char,float> > qt;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int I=0;I<n;I++) {
        char v,u;
        int d,a,b;
        cin >> u >> v >> d;
        if(u=='X') a=0;
        else if(u=='Y') a=30;
        else a=u-96;

        if(v=='X') b=0;
        else if(v=='Y') b=30;
        else b=v-96;
        if(a==30 || b==0 || b==tmp) swap(a,b);
        if(!visited[a][b]) {
            _next[a].push_back(b);
            _next[b].push_back(a);
            visited[a][b]=visited[b][a]=true ;
        }
        tmp=b;
        w[a][b].push_back(d);
        w[b][a].push_back(d);
    }
    for(auto i: _next[0]) q.push({0,i});
    while(!q.empty()) {
        auto [i,j]=q.front(); q.pop();
        char a,b;
        sort(w[i][j].begin(),w[i][j].end());
        int ws=w[i][j].size();
        float med;
        if(i==0) a='X';
        else a=char(i+96);
        if(j==30) b='Y';
        else b=char(j+96);
        if(ws%2==0)  med=float(w[i][j][ws/2-1]+w[i][j][ws/2])/2;
        else med=w[i][j][ws/2];
        if(((a>='a' && a<='z') || a=='X') && ((b>='a' && b<='z') || b=='Y') && visited[i][j]) {
            qt.push({a,b,med});
            ans+=med;
            visited[i][j]=visited[j][i]=false ;
        } 
        else continue ;
        if(j==30) {ch=0; break ;}
        for(auto k: _next[j]) q.push({j,k});
    }
    if(ch) {
        cout << "broken";
        return 0;
    }
    while(!qt.empty()) {
        auto [a,b,d]=qt.front(); qt.pop();
        cout << a << " " << b << " " << fixed << setprecision(1) << d << "\n";
    }
    cout << ans;
    
}