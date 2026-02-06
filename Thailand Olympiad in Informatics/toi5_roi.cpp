#include<bits/stdc++.h>
using namespace std;
double n,_min=INT_MAX;
pair<int,int> ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1000,discount=100;i<=15000;i+=500,discount--) { //product
        for(int j=74;j<=144;j++) { //prices
            double allCost=n+(i*discount);
            double bookSolded=((100-(0.8569*exp((j-100)*0.09)))*i)/100;
            double income=bookSolded*j;
            double profit=income-allCost;
            // cout << profit << endl;
            if(profit>0 && profit<_min) {
                ans={i,j};
                _min=profit;
            } 
        }
    }
    auto [i,j]=ans;
    cout << i << "\n" << j << "\n" << fixed << setprecision(2) << _min;
}