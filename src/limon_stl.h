#include<bits/stdc++.h>
using namespace std;

string tostrlwr(string s){
    string k= "";
    for(int i = 0; i<s.size(); i++){
        if(s[i] != ' ' && s[i] != ',' && s[i] != '.'){
            k+=tolower(s[i]);
        }
    }
    return k; 
}