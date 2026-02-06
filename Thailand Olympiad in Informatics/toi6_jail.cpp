#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
bool visited[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    int i=1,j=1,cou=0;
    while(cou<n) {
        i++;
        if(i>n) i=1;
        if(visited[i]) continue ;
        if(j>m) j=1;
        if(j+1==m) {
            visited[i]=++cou;
            cout << i << " ";
        }
        j++;
    }
}