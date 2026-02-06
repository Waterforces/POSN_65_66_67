#include<iostream>
using namespace std;
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    s[0] = toupper(s[0]);
    cout << s << endl;
}