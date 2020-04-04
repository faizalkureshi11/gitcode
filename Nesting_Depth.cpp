#include <bits/stdc++.h>
using namespace std;

void check(){
    string word;
    cin >> word;
    int dp=0;
    string answ;
    for(char ch : word){
        int ndp=ch-'0';
        while(ndp>dp){
            ++dp;
            answ=answ+'(';
        }
        while(ndp<dp){
            --dp;
            answ=answ+')';
        }
        answ=answ+ch;
    }
    while(dp>0){
        --dp;
        answ=answ+')';
    }
    cout << answ << "\n";
    
}

int main(){
    int tcase;
    cin >> tcase;
    for(int j=1; j<=tcase; ++j){
        cout << "Case #" << j << ": ";
        check();
    }
}