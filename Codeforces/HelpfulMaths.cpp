#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> nums;
vector<char> ops;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    for(auto i: s) {
        if(i == '+') ops.push_back(i);
        else nums.push_back(i-'0');
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i < ops.size()) cout << ops[i];
    }
}