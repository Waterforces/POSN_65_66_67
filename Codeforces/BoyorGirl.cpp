#include<iostream>
using namespace std;
int cnt;
bool let[30];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    for(char c: s) {
        if(let[c - 'a']) continue ;
        let[c - 'a'] = true;
        cnt++;
    }
    if(cnt % 2 == 0) cout << "CHAT WITH HER!" << endl;
    else cout << "IGNORE HIM!" << endl;
}