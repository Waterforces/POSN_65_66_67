#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
string s;
stack<int> num;
stack<char> oper;

void cal() {
    int x = num.top(); num.pop();
    int y = num.top(); num.pop();
    char o = oper.top(); oper.pop();
    if(o == '1') num.push( (x+y) * 104/100);
    else if(o == '2') num.push( (x+y) * 108/100);
    else if(o == '3') num.push( (x+y) * 116/100);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    for(auto x: s) {
        if(x >= 'A' && x <= 'Z') num.push(20);
        else if(x == '[') oper.push('0');
        else if(x == ']') {
            while(oper.top() != '0') cal();
            oper.pop();
        }
        else {
            while(!oper.empty() && oper.top() >= x) cal();
            oper.push(x); 
        }
    }
    while(!oper.empty()) cal();
    cout << num.top();
} 