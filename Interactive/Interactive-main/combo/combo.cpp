#include "combo.h"
#include<bits/stdc++.h>
using namespace std;

string guess_sequence(int N) {
  string s="",compair="",tmp="";
  int coin=0,oldCoin=1;
  coin=press("AB");
  if(coin==0) {
    coin=press("X");
    if(coin==1) s+="X";
    else s+="Y";
  }
  else if(coin==1 || coin==2) {
    coin=press("A");
    if(coin==1) s+="A";
    else s+="B";
  }
  if(s[0]=='A') compair+="BXY";
  else if(s[0]=='B') compair+="AXY";
  else if(s[0]=='X') compair+="ABY";
  else compair+="ABX";
  for(int i=1;i<N-1;i++,tmp=s) {
    tmp=s+compair[0]+s+compair[1]+compair[0]+s+compair[1]+compair[1]+s+compair[1]+compair[2];
    coin=press(tmp);
    // cout << coin <<  " " << s << "\n::: " << tmp << "\n";
    if(coin==s.size()) {
      s+=compair[2];
    }
    else if(coin==s.size()+1) {
      s+=compair[0];
    }
    else {
      s+=compair[1];
    }
    // oldCoin=coin;
  }
  coin=press(s+compair[0]);
  if(N<2) return s; 
  if(coin==N) s+=compair[0];
  else {
    coin=press(s+compair[1]);
    if(coin==N) s+=compair[1];
    else s+=compair[2];
  }
  return s;
}
